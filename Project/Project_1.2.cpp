// log_analyzer_part1.cpp
// Part 1 of 2: definitions, XML loading into doubly linked list, helpers, analyzer skeleton.
//
// Requirements: tinyxml2 (either single-file tinyxml2.cpp/.h or system lib tinyxml2)
// Compile (if tinyxml2 is installed system-wide):
// g++ -std=c++11 log_analyzer_part1.cpp -o log_analyzer_part1 -ltinyxml2
// Or (if tinyxml2.cpp is in same folder):
// g++ -std=c++11 log_analyzer_part1.cpp tinyxml2.cpp -o log_analyzer_part1

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include "tinyxml2.h" // Make sure tinyxml2.h is available in include path

using namespace std;
using namespace tinyxml2;

// ------------------------ Basic data types ------------------------

struct LogEntry
{
    string timestamp;   // original timestamp string from XML (ISO)
    time_t epoch;       // parsed epoch seconds (0 if not parsed)
    string event_id;    // e.g., "4625"
    string ip;          // IP address if found (may be empty)
    string username;    // username if found (may be empty)
    string raw_summary; // short summary for debugging
};

struct Node
{
    LogEntry data;
    Node* prev;
    Node* next;

    Node(const LogEntry& e)
    {
        data = e;
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

    // small helper to print first N entries (for quick sanity-check)
    void print_first_n(int n)
    {
        Node* cur = head;
        int count = 0;
        while (cur != NULL && count < n)
        {
            cout << "[" << count+1 << "] EventID: " << cur->data.event_id
                 << " Time: " << cur->data.timestamp
                 << " IP: " << (cur->data.ip.empty() ? "-" : cur->data.ip)
                 << " User: " << (cur->data.username.empty() ? "-" : cur->data.username)
                 << endl;
            cur = cur->next;
            count++;
        }
    }
};

// ------------------------ XML parsing helpers ------------------------

static const char* safeText(XMLElement* e)
{
    if (e == NULL) return NULL;
    const char* t = e->GetText();
    if (t == NULL) return NULL;
    return t;
}

// find an IP-like value inside EventData/Data elements (simple heuristics)
string find_ip_in_eventdata(XMLElement* eventData)
{
    if (eventData == NULL) return "";

    XMLElement* data = eventData->FirstChildElement("Data");
    while (data != NULL)
    {
        const char* nameAttr = data->Attribute("Name");
        const char* value = safeText(data);

        string name = (nameAttr != NULL) ? string(nameAttr) : string("");
        string val = (value != NULL) ? string(value) : string("");

        if (name == "IpAddress" || name == "Ip" || name == "IpAddressV4" || name == "Address")
        {
            return val;
        }

        // crude heuristic: looks like IPv4 (has at least one dot and digits)
        int dotcount = 0;
        int digits = 0;
        for (size_t i = 0; i < val.length(); ++i)
        {
            if (val[i] == '.') dotcount++;
            if (val[i] >= '0' && val[i] <= '9') digits++;
        }
        if (dotcount >= 1 && digits >= 2 && val.length() <= 45)
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

        // fallback: prefer short alpha-containing tokens
        bool has_alpha = false;
        for (size_t i = 0; i < val.length(); ++i)
        {
            if ((val[i] >= 'A' && val[i] <= 'Z') || (val[i] >= 'a' && val[i] <= 'z'))
            {
                has_alpha = true;
                break;
            }
        }
        if (has_alpha && val.length() <= 64 && val != "0")
        {
            return val;
        }

        data = data->NextSiblingElement("Data");
    }

    return "";
}

// ------------------------ Timestamp helper ------------------------
//
// We expect timestamps in ISO-like form from EVTX XML, e.g.
// 2025-11-05T05:05:01.499561600Z
// We'll parse YYYY-MM-DDThh:mm:ss part and ignore fractional seconds.
// Returns epoch seconds (UTC) or 0 on failure.
//

time_t parse_iso_timestamp_to_epoch(const string& s)
{
    // simple safety checks
    if (s.length() < 19) return 0;

    // extract date/time substrings
    // YYYY-MM-DDThh:mm:ss
    int year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0;
    // using stringstream to avoid sscanf for simplicity
    // substring positions fixed
    try
    {
        year = stoi(s.substr(0,4));
        month = stoi(s.substr(5,2));
        day = stoi(s.substr(8,2));
        hour = stoi(s.substr(11,2));
        minute = stoi(s.substr(14,2));
        second = stoi(s.substr(17,2));
    }
    catch(...)
    {
        return 0;
    }

    struct tm tm_time;
    tm_time.tm_year = year - 1900; // years since 1900
    tm_time.tm_mon  = month - 1;   // months since January [0-11]
    tm_time.tm_mday = day;
    tm_time.tm_hour = hour;
    tm_time.tm_min  = minute;
    tm_time.tm_sec  = second;
    tm_time.tm_isdst = 0; // not considering daylight savings (timestamps are UTC)

    // Use timegm if available (converts UTC tm to time_t). Fallback to mktime with adjustments.
    #if defined(__unix__) || defined(__APPLE__)
    // timegm is often available on unix-like systems
    time_t epoch = timegm(&tm_time); // convert assuming UTC
    return epoch;
    #else
    // On systems without timegm, mktime treats tm as local time; this may be wrong for UTC.
    time_t epoch_local = mktime(&tm_time);
    return epoch_local;
    #endif
}

// ------------------------ XML loader: load events into linked list ------------------------

bool load_xml_into_list(const char* filename, DoublyLinkedList& list)
{
    XMLDocument doc;
    XMLError r = doc.LoadFile(filename);
    if (r != XML_SUCCESS)
    {
        cout << "Error: cannot open or parse XML file: " << filename << " (tinyxml2 error " << r << ")\n";
        return false;
    }

    XMLElement* root = doc.RootElement();
    if (root == NULL)
    {
        cout << "Error: empty XML file or invalid structure.\n";
        return false;
    }

    // Try to find <Event> nodes under typical structures.
    // We'll search the document for Event elements in a simple two-pass approach:
    // 1) try root->FirstChildElement("Event") chain
    // 2) if not found or to catch others, iterate many children and look for Event nodes

    // Pass 1: direct Event children under root or <Events>
    XMLElement* eventElem = root->FirstChildElement("Event");
    if (eventElem == NULL)
    {
        XMLElement* eventsNode = root->FirstChildElement("Events");
        if (eventsNode != NULL) eventElem = eventsNode->FirstChildElement("Event");
    }

    // We'll collect Event nodes found in a simple loop (this will catch common structures)
    if (eventElem != NULL)
    {
        XMLElement* cur = eventElem;
        while (cur != NULL)
        {
            // parse fields
            string event_id = "";
            string timestamp = "";
            string ip = "";
            string username = "";

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

            XMLElement* eventData = cur->FirstChildElement("EventData");
            if (eventData != NULL)
            {
                ip = find_ip_in_eventdata(eventData);
                username = find_username_in_eventdata(eventData);
            }

            // Build LogEntry
            LogEntry entry;
            entry.event_id = event_id;
            entry.timestamp = timestamp;
            entry.epoch = parse_iso_timestamp_to_epoch(timestamp);
            entry.ip = ip;
            entry.username = username;
            entry.raw_summary = "EventID=" + event_id + " Time=" + timestamp;

            list.append(entry);

            cur = cur->NextSiblingElement("Event");
        }
    }

    // Pass 2: if list is still empty or to catch nested Event nodes, do a broader scan:
    // iterate over first-level children and search for Event grandchildren.
    if (list.size == 0)
    {
        XMLElement* child = root->FirstChildElement();
        while (child != NULL)
        {
            XMLElement* ev = child->FirstChildElement("Event");
            while (ev != NULL)
            {
                string event_id = "";
                string timestamp = "";
                string ip = "";
                string username = "";

                XMLElement* systemNode = ev->FirstChildElement("System");
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

                XMLElement* eventData = ev->FirstChildElement("EventData");
                if (eventData != NULL)
                {
                    ip = find_ip_in_eventdata(eventData);
                    username = find_username_in_eventdata(eventData);
                }

                LogEntry entry;
                entry.event_id = event_id;
                entry.timestamp = timestamp;
                entry.epoch = parse_iso_timestamp_to_epoch(timestamp);
                entry.ip = ip;
                entry.username = username;
                entry.raw_summary = "EventID=" + event_id + " Time=" + timestamp;

                list.append(entry);

                ev = ev->NextSiblingElement("Event");
            }
            child = child->NextSiblingElement();
        }
    }

    cout << "Loaded " << list.size << " events into the linked list (approx).\n";
    return true;
}

// ------------------------ Analyzer skeleton (data structures only) ------------------------
//
// The Analyzer will implement detection rules in Part 2.
// We declare storage and helper methods here so the overall program structure is clear.
//

class Analyzer
{
public:
    DoublyLinkedList* list;

    // Blacklist of known bad IPs
    unordered_set<string> blacklist;

    // For brute-force detection:
    // map IP -> deque of failed-login epoch timestamps
    unordered_map<string, deque<time_t> > ip_fail_times;

    // For tracking unique usernames seen per IP
    unordered_map<string, unordered_set<string> > ip_usernames;

    // For storing alerts (simple vector of strings for now)
    vector<string> alerts;

    // configurable thresholds
    int brute_force_threshold; // e.g., 5 attempts
    int brute_force_window_seconds; // e.g., 300 seconds

    Analyzer(DoublyLinkedList* l)
    {
        list = l;
        brute_force_threshold = 5;
        brute_force_window_seconds = 300; // 5 minutes
        // Example blacklist seeds (you will likely load from file in real program)
        blacklist.insert("45.118.211.3");
        blacklist.insert("203.0.113.5");
    }

    // helper to add an alert (keeps alerts human-friendly)
    void add_alert(const string& a)
    {
        alerts.push_back(a);
    }

    // We'll implement these in Part 2:
    // - process_all_events(): traverse linked list and call process_event on each
    // - process_event(const LogEntry& e): check event type and update structures, raise alerts
    // - report(): print friendly report and optionally save to file

    void process_all_events(); // implemented in Part 2
    void process_event(const LogEntry& e); // implemented in Part 2
    void report(); // implemented in Part 2
};

// ------------------------ main (Part 1) ------------------------

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
        cout << "Failed to load XML. Exiting.\n";
        return 1;
    }

    cout << "Sanity-check: first 10 events (if available):\n";
    list.print_first_n(10);

    // create analyzer but processing is in Part 2
    Analyzer analyzer(&list);

    cout << "\nPART 1 complete. In Part 2 I will provide:\n"
         << " - Implementation of Analyzer::process_all_events()\n"
         << " - Detection rules: brute-force (sliding window), blacklist checks,\n"
         << "   many-usernames-per-IP, success-after-fails correlation, basic scoring\n"
         << " - report() function that prints a clear, user-friendly report and saves alerts to a file\n\n";

    cout << "Run the Part 2 program once I give it to actually analyze the loaded list.\n";
    return 0;
}
