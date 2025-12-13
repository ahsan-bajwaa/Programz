// evtx_loader.cpp
#include <iostream>
#include <string>
#include "tinyxml2.h" // make sure this header is available
using namespace std;
using namespace tinyxml2;

// -------------------- Data structures --------------------

struct LogEntry
{
    string timestamp;
    string event_id;
    string ip;
    string username;
    string raw; // optional: entire event XML or short summary
};

struct Node
{
    LogEntry data;
    Node* prev;
    Node* next;

    Node(const LogEntry& entry)
    {
        data = entry;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList
{
public:
    Node* head;
    Node* tail;
    int size;

    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    ~DoublyLinkedList()
    {
        // free nodes
        Node* cur = head;
        while (cur != NULL)
        {
            Node* tmp = cur->next;
            delete cur;
            cur = tmp;
        }
    }

    void append(const LogEntry& entry)
    {
        Node* node = new Node(entry);
        if (head == NULL)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        size++;
    }

    // small helper to print first N entries (for debug)
    void print_first_n(int n)
    {
        Node* cur = head;
        int count = 0;
        while (cur != NULL && count < n)
        {
            cout << "EventID: " << cur->data.event_id
                 << " Time: " << cur->data.timestamp
                 << " IP: " << cur->data.ip
                 << " User: " << cur->data.username << endl;
            cur = cur->next;
            count++;
        }
    }
};

// -------------------- XML parsing helpers --------------------

static const char* safeText(XMLElement* e)
{
    if (e == NULL) return NULL;
    const char* t = e->GetText();
    if (t == NULL) return NULL;
    return t;
}

// Try to extract a child element text by a path like System/EventID
XMLElement* getChild(XMLElement* root, const char* name)
{
    if (root == NULL) return NULL;
    return root->FirstChildElement(name);
}

// Search EventData/Data elements for common names (IpAddress, Ip, IpAddress)
string find_ip_in_eventdata(XMLElement* eventData)
{
    if (eventData == NULL) return "";

    XMLElement* data = eventData->FirstChildElement("Data");
    while (data != NULL)
    {
        const char* nameAttr = data->Attribute("Name"); // EVTX often uses Name attribute
        const char* value = safeText(data);

        string name = (nameAttr != NULL) ? string(nameAttr) : string("");
        string val = (value != NULL) ? string(value) : string("");

        // common keys that may contain IPs
        if (name == "IpAddress" || name == "Ip" || name == "IpAddressV4" || name == "Address")
        {
            return val;
        }

        // sometimes the Data element has IP directly without Name
        // try a simple heuristic: if value contains '.' and digits (IPv4)
        bool looks_like_ip = false;
        int dotcount = 0;
        for (size_t i = 0; i < val.length(); ++i)
        {
            if (val[i] == '.') dotcount++;
            if ((val[i] >= '0' && val[i] <= '9') || val[i] == '.' || val[i] == ':')
                looks_like_ip = looks_like_ip || true;
        }
        if (dotcount >= 1 && val.length() > 6) // crude IPv4 check
        {
            return val;
        }

        data = data->NextSiblingElement("Data");
    }

    return "";
}

string find_username_in_eventdata(XMLElement* eventData)
{
    if (eventData == NULL) return "";

    XMLElement* data = eventData->FirstChildElement("Data");
    while (data != NULL)
    {
        const char* nameAttr = data->Attribute("Name");
        const char* value = safeText(data);

        string name = (nameAttr != NULL) ? string(nameAttr) : string("");
        string val = (value != NULL) ? string(value) : string("");

        if (name == "TargetUserName" || name == "AccountName" || name == "SubjectUserName" || name == "User")
        {
            return val;
        }

        // fallback: skip empty or numeric-only values
        if (val != "")
        {
            // often usernames are short and contain letters
            bool has_alpha = false;
            for (size_t i = 0; i < val.length(); ++i)
            {
                if ((val[i] >= 'A' && val[i] <= 'Z') || (val[i] >= 'a' && val[i] <= 'z'))
                {
                    has_alpha = true;
                    break;
                }
            }
            if (has_alpha && val.length() <= 64)
            {
                return val;
            }
        }

        data = data->NextSiblingElement("Data");
    }
    return "";
}

// -------------------- Main loader --------------------

bool load_xml_into_list(const char* filename, DoublyLinkedList& list)
{
    XMLDocument doc;
    XMLError r = doc.LoadFile(filename);
    if (r != XML_SUCCESS)
    {
        cout << "Error: cannot open or parse XML file: " << filename << " (tinyxml2 error " << r << ")\n";
        return false;
    }

    // EVTX exported XML usually has <Events> root or may directly contain multiple <Event> nodes
    XMLElement* root = doc.RootElement(); // could be <Events> or something else
    if (root == NULL)
    {
        cout << "Error: empty XML file or invalid structure.\n";
        return false;
    }

    // Find first <Event> element under root (depth may vary)
    XMLElement* eventElem = NULL;

    // If root itself is <Events> and children are <Event>
    eventElem = root->FirstChildElement("Event");

    // If not found, try to search recursively for Event elements (simple approach)
    if (eventElem == NULL)
    {
        // try a couple of likely places: root->FirstChildElement("Events")->FirstChildElement("Event")
        XMLElement* eventsNode = root->FirstChildElement("Events");
        if (eventsNode != NULL) eventElem = eventsNode->FirstChildElement("Event");
    }

    if (eventElem == NULL)
    {
        // fallback: maybe the root is <Event> itself
        if (string(root->Name()) == "Event")
        {
            eventElem = root;
        }
    }

    if (eventElem == NULL)
    {
        cout << "Warning: no <Event> elements found. Check XML format.\n";
        return false;
    }

    // iterate all Event nodes (we'll search siblings at same level and also attempt a recursive search if needed)
    XMLElement* cur = eventElem;
    while (cur != NULL)
    {
        // For each <Event> try to extract System/EventID and System/TimeCreated/@SystemTime
        string event_id = "";
        string timestamp = "";
        string ip = "";
        string username = "";
        string raw_summary = "";

        XMLElement* systemNode = cur->FirstChildElement("System");
        if (systemNode != NULL)
        {
            XMLElement* eventIdNode = systemNode->FirstChildElement("EventID");
            const char* idText = safeText(eventIdNode);
            if (idText != NULL) event_id = string(idText);

            XMLElement* timeNode = systemNode->FirstChildElement("TimeCreated");
            if (timeNode != NULL)
            {
                const char* tAttr = timeNode->Attribute("SystemTime");
                if (tAttr != NULL) timestamp = string(tAttr);
            }
        }

        // EventData section
        XMLElement* eventData = cur->FirstChildElement("EventData");
        if (eventData != NULL)
        {
            ip = find_ip_in_eventdata(eventData);
            username = find_username_in_eventdata(eventData);
        }
        else
        {
            // Some XML exports may use <RenderingInfo> or other tags, try to search common places
            XMLElement* dataNode = cur->FirstChildElement("UserData");
            if (dataNode != NULL)
            {
                // try to find Data elements under UserData
                ip = find_ip_in_eventdata(dataNode->FirstChildElement("Data") ? dataNode : NULL);
            }
        }

        // Build raw summary for debugging
        raw_summary = "EventID=" + event_id + " Time=" + timestamp;

        LogEntry entry;
        entry.event_id = event_id;
        entry.timestamp = timestamp;
        entry.ip = ip;
        entry.username = username;
        entry.raw = raw_summary;

        list.append(entry);

        // Move to next sibling <Event>
        XMLElement* nextEvent = cur->NextSiblingElement("Event");
        if (nextEvent == NULL)
        {
            // if no sibling, try to step up and find more events under root->FirstChildElement("Event")->NextSibling...
            break;
        }
        cur = nextEvent;
    } // end while events

    // If the above only captured a first batch (due to structure), attempt a broader traversal:
    // Simple breadth-first scanning of whole document for Event nodes (safe for moderate sizes)
    // This will pick any Event nodes not in the direct sibling chain.
    // (We skip this in extremely large files; if needed we can do streaming)
    XMLElement* anyEvent = root->FirstChildElement();
    while (anyEvent != NULL)
    {
        if (string(anyEvent->Name()) == "Event")
        {
            // Already processed chain earlier; skip duplicates by checking if appended count matches
            // To keep it simple, we won't append duplicates in this naive pass.
        }
        // recursively check children for Event nodes
        XMLElement* child = anyEvent->FirstChildElement("Event");
        if (child != NULL)
        {
            XMLElement* c = child;
            while (c != NULL)
            {
                // extract same as above
                string event_id = "";
                string timestamp = "";
                string ip = "";
                string username = "";
                string raw_summary = "";

                XMLElement* systemNode = c->FirstChildElement("System");
                if (systemNode != NULL)
                {
                    XMLElement* eventIdNode = systemNode->FirstChildElement("EventID");
                    const char* idText = safeText(eventIdNode);
                    if (idText != NULL) event_id = string(idText);

                    XMLElement* timeNode = systemNode->FirstChildElement("TimeCreated");
                    if (timeNode != NULL)
                    {
                        const char* tAttr = timeNode->Attribute("SystemTime");
                        if (tAttr != NULL) timestamp = string(tAttr);
                    }
                }

                XMLElement* eventData = c->FirstChildElement("EventData");
                if (eventData != NULL)
                {
                    ip = find_ip_in_eventdata(eventData);
                    username = find_username_in_eventdata(eventData);
                }

                raw_summary = "EventID=" + event_id + " Time=" + timestamp;

                LogEntry entry;
                entry.event_id = event_id;
                entry.timestamp = timestamp;
                entry.ip = ip;
                entry.username = username;
                entry.raw = raw_summary;

                list.append(entry);

                c = c->NextSiblingElement("Event");
            }
        }
        anyEvent = anyEvent->NextSiblingElement();
    }

    cout << "Loaded " << list.size << " events into the linked list.\n";
    return true;
}

// -------------------- Example main --------------------

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " <security.xml>\n";
        return 1;
    }

    const char* filename = argv[1];

    DoublyLinkedList list;
    bool ok = load_xml_into_list(filename, list);
    if (!ok)
    {
        cout << "Failed to load XML.\n";
        return 1;
    }

    // Print first 10 entries for sanity check
    cout << "First 10 parsed events:\n";
    list.print_first_n(10);

    // You can now traverse list and apply detections (sliding window etc)
    // e.g. traverse: for (Node* cur = list.head; cur != NULL; cur = cur->next) { ... }

    return 0;
}
