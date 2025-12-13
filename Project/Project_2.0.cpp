#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Structure for each node in the doubly linked list
struct Node {
    string log_number;      // Sequential index (e.g., "1", "2")
    string event_number;    // EventID from the log
    string creation_time;   // Timestamp of the event
    string computer_name;   // Computer where event occurred
    string logon_type;      // Logon type (e.g., "10" for remote)
    string description;     // Short message or data (e.g., IP or failure reason)
    Node* prev;             // Pointer to previous node
    Node* next;             // Pointer to next node
};

// Class for the Doubly Linked List
class DoublyLinkedList {
private:
    Node* head;  // Pointer to the first node
    Node* tail;  // Pointer to the last node
    int count;   // Number of nodes in the list

public:
    // Constructor to initialize the list
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    // Destructor to clean up memory
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Function to insert a new node at the end of the list
    void insertAtEnd(string log_num, string event_num, string create_time,
                     string comp_name, string log_type, string desc) {
        Node* newNode = new Node;
        newNode->log_number = log_num;
        newNode->event_number = event_num;
        newNode->creation_time = create_time;
        newNode->computer_name = comp_name;
        newNode->logon_type = log_type;
        newNode->description = desc;
        newNode->next = nullptr;

        if (head == nullptr) {
            // If list is empty, set head and tail to new node
            newNode->prev = nullptr;
            head = newNode;
            tail = newNode;
        } else {
            // Add to end
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
    }

    // Function to display the last N logs (from tail backward)
    void displayRecent(int n) {
        if (n > count) {
            cout << "Only " << count << " logs available. Showing all." << endl;
            n = count;
        }
        if (n <= 0) {
            cout << "Invalid number. Please enter a positive number." << endl;
            return;
        }

        Node* current = tail;
        int shown = 0;
        cout << "Showing last " << n << " logs (most recent first):" << endl;
        while (current != nullptr && shown < n) {
            cout << "Log Number: " << current->log_number << endl;
            cout << "Event Number: " << current->event_number << endl;
            cout << "Creation Time: " << current->creation_time << endl;
            cout << "Computer Name: " << current->computer_name << endl;
            cout << "Logon Type: " << current->logon_type << endl;
            cout << "Description: " << current->description << endl;
            cout << "------------------------" << endl;
            current = current->prev;
            shown++;
        }
    }

    // Function to scan for brute-force attacks (multiple EventID 4625)
    void scanBruteForce() {
        Node* current = head;
        int failureCount = 0;
        string lastDesc = "";
        int perSourceCount = 0;
        while (current != nullptr) {
            if (current->event_number == "4625") {
                failureCount++;
                if (current->description == lastDesc) {
                    perSourceCount++;
                } else {
                    perSourceCount = 1;
                    lastDesc = current->description;
                }
                if (perSourceCount > 3) {
                    cout << "Multiple failures from source: " << current->description << " at " << current->creation_time << endl;
                }
            }
            current = current->next;
        }
        cout << "Brute-force scan: Found " << failureCount << " failed login attempts (EventID 4625)." << endl;
        if (failureCount > 5) {
            cout << "Warning: Possible brute-force attack detected!" << endl;
        } else {
            cout << "No significant brute-force activity." << endl;
        }
    }

    // Function to scan for remote access (EventID 4624 with LogonType 10)
    void scanRemoteAccess() {
        Node* current = head;
        int remoteCount = 0;
        while (current != nullptr) {
            if (current->event_number == "4624" && current->logon_type == "10") {
                remoteCount++;
                cout << "Remote access detected at " << current->creation_time << " from " << current->description << endl;
            }
            current = current->next;
        }
        cout << "Remote access scan: Found " << remoteCount << " remote logons." << endl;
        if (remoteCount > 0) {
            cout << "Review these for unauthorized access." << endl;
        } else {
            cout << "No remote access detected." << endl;
        }
    }

    // Function for entire scan (calls other scans)
    void entireScan() {
        cout << "Performing entire security scan..." << endl;
        scanBruteForce();
        scanRemoteAccess();
        // You can add more scans here if needed
    }

    // Function to get the count of logs
    int getCount() {
        return count;
    }
};

// Helper function to extract value between tags
string extractTagValue(const string& text, const string& startTag, const string& endTag) {
    size_t start = text.find(startTag);
    if (start == string::npos) return "";
    start += startTag.length();
    size_t end = text.find(endTag, start);
    if (end == string::npos) return "";
    return text.substr(start, end - start);
}

// Helper function to extract attribute value
string extractAttributeValue(const string& text, const string& tagStart, const string& attrStart, const string& attrEnd) {
    size_t tagPos = text.find(tagStart);
    if (tagPos == string::npos) return "";
    size_t attrPos = text.find(attrStart, tagPos);
    if (attrPos == string::npos) return "";
    attrPos += attrStart.length();
    size_t endPos = text.find(attrEnd, attrPos);
    if (endPos == string::npos) return "";
    return text.substr(attrPos, endPos - attrPos);
}

// Helper function to extract <Data Name="key">value</Data>
string extractDataValue(const string& text, const string& dataName) {
    string search = "<Data Name=\"" + dataName + "\">";
    size_t start = text.find(search);
    if (start == string::npos) return "";
    start += search.length();
    size_t end = text.find("</Data>", start);
    if (end == string::npos) return "";
    return text.substr(start, end - start);
}

// Function to parse the XML file and load into the list
// Assumes standard Windows Security XML structure with <Event> tags
void loadLogsFromXML(const string& filePath, DoublyLinkedList& logList) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cout << "Error: Could not open file " << filePath << endl;
        return;
    }

    string line;
    string currentEvent;
    int logCounter = 1;
    bool inEvent = false;

    while (getline(file, line)) {
        // Find start of <Event>
        size_t eventStart = line.find("<Event ");
        if (eventStart != string::npos) {
            inEvent = true;
            currentEvent = line;
            continue;
        }

        // If inside <Event>, append lines
        if (inEvent) {
            currentEvent += line;
        }

        // Find end of </Event>
        size_t eventEnd = line.find("</Event>");
        if (eventEnd != string::npos && inEvent) {
            inEvent = false;

            // Now extract fields from currentEvent string
            string log_num = to_string(logCounter);
            string event_num = extractTagValue(currentEvent, "<EventID>", "</EventID>");
            string create_time = extractAttributeValue(currentEvent, "<TimeCreated ", "SystemTime=\"", "\"");
            string comp_name = extractTagValue(currentEvent, "<Computer>", "</Computer>");
            string log_type = extractDataValue(currentEvent, "LogonType");
            string desc = extractDataValue(currentEvent, "IpAddress");  // Or other data; adjust as needed

            // Insert into list if it's a security-relevant event (e.g., logon-related) and fields are not empty
            if (!event_num.empty() && !create_time.empty() && (event_num == "4624" || event_num == "4625" || event_num == "4634")) {
                logList.insertAtEnd(log_num, event_num, create_time, comp_name, log_type, desc);
                logCounter++;
            }

            currentEvent.clear();
        }
    }

    file.close();
    cout << "Loaded " << (logCounter - 1) << " relevant logs into the list." << endl;
}

int main() {
    DoublyLinkedList logList;
    string filePath;

    cout << "Enter the full path to the security.xml file: ";
    getline(cin, filePath);

    loadLogsFromXML(filePath, logList);

    if (logList.getCount() == 0) {
        cout << "No logs loaded. Exiting." << endl;
        return 0;
    }

    int choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Scan for brute-force attacks" << endl;
        cout << "2. Scan for remote access" << endl;
        cout << "3. Entire security scan" << endl;
        cout << "4. View recent logs (enter number)" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Clear newline

        if (choice == 1) {
            logList.scanBruteForce();
        } else if (choice == 2) {
            logList.scanRemoteAccess();
        } else if (choice == 3) {
            logList.entireScan();
        } else if (choice == 4) {
            int n;
            cout << "Enter number of recent logs to view: ";
            cin >> n;
            cin.ignore();
            logList.displayRecent(n);
        } else if (choice == 5) {
            cout << "Exiting program." << endl;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}