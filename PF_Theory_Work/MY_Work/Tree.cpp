#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ===============================================
// CLASS: Node for Log Entry (Linked List)
// ===============================================
class LogEntryNode
{
private:
    string eventID;
    string timeCreated;
    string accountName;
    string sourceIP;
    string logonType;
    string attackType;
    string severity;
    LogEntryNode* link;

public:
    LogEntryNode()
    {
        eventID = "";
        timeCreated = "";
        accountName = "";
        sourceIP = "";
        logonType = "";
        attackType = "";
        severity = "LOW";
        link = nullptr;
    }

    // Setters
    void setEventID(string id)          { eventID = id; }
    void setTimeCreated(string time)    { timeCreated = time; }
    void setAccountName(string name)    { accountName = name; }
    void setSourceIP(string ip)         { sourceIP = ip; }
    void setLogonType(string type)      { logonType = type; }
    void setAttackType(string type)     { attackType = type; }
    void setSeverity(string sev)        { severity = sev; }
    void setLink(LogEntryNode* next)   { link = next; }

    // Getters
    string getEventID()         { return eventID; }
    string getTimeCreated()    { return timeCreated; }
    string getAccountName()     { return accountName; }
    string getSourceIP()        { return sourceIP; }
    string getLogonType()       { return logonType; }
    string getAttackType()      { return attackType; }
    string getSeverity()        { return severity; }
    LogEntryNode* getLink()     { return link; }
};

// ===============================================
// CLASS: Timeline Node for BST (Time Sorted)
// ===============================================
class TimelineNode
{
private:
    string timeCreated;
    string message;
    string severity;
    TimelineNode* left;
    TimelineNode* right;

public:
    TimelineNode(string t, string m, string s)
    {
        timeCreated = t;
        message = m;
        severity = s;
        left = right = nullptr;
    }

    // Setters
    void setLeft(TimelineNode* node)  { left = node; }
    void setRight(TimelineNode* node) { right = node; }
    void setMessage(string msg)       { message = msg; }

    // Getters
    string getTimeCreated() { return timeCreated; }
    string getMessage()     { return message; }
    string getSeverity()    { return severity; }
    TimelineNode* getLeft() { return left; }
    TimelineNode* getRight(){ return right; }
};

// ===============================================
// CLASS: Singly Linked List for Logs
// ===============================================
class SecurityLogList
{
private:
    LogEntryNode* head;
    LogEntryNode* tail;

public:
    SecurityLogList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertLog(LogEntryNode* newNode)
    {
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->setLink(newNode);
            tail = newNode;
        }
    }

    void displayAll()
    {
        LogEntryNode* temp = head;
        int count = 1;
        if (temp == nullptr)
        {
            cout << "No logs found.\n";
            return;
        }
        while (temp != nullptr)
        {
            cout << count++ << ". [" << temp->getTimeCreated().substr(0,19) << "] "
                 << temp->getSeverity() << " -> " << temp->getAttackType()
                 << " (" << temp->getAccountName() << " from " << temp->getSourceIP() << ")\n";
            temp = temp->getLink();
        }
    }

    LogEntryNode* getHead() { return head; }
};

// ===============================================
// CLASS: Binary Search Tree for Timeline
// ===============================================
class AttackTimeline
{
private:
    TimelineNode* root;

public:
    AttackTimeline()
    {
        root = nullptr;
    }

    TimelineNode* insert(TimelineNode* node, string time, string msg, string sev)
    {
        if (node == nullptr)
        {
            return new TimelineNode(time, msg, sev);
        }
        if (time < node->getTimeCreated())
        {
            node->setLeft(insert(node->getLeft(), time, msg, sev));
        }
        else
        {
            node->setRight(insert(node->getRight(), time, msg, sev));
        }
        return node;
    }

    void insertEvent(string time, string msg, string sev)
    {
        root = insert(root, time, msg, sev);
    }

    void displayInOrder(TimelineNode* node)
    {
        if (node == nullptr) return;

        displayInOrder(node->getLeft());
        cout << " [" << node->getTimeCreated().substr(0,19) << "] "
             << node->getSeverity() << " -> " << node->getMessage() << endl;
        displayInOrder(node->getRight());
    }

    void showTimeline()
    {
        cout << "\n=== ATTACK TIMELINE (CHRONOLOGICAL ORDER) ===\n";
        if (root == nullptr)
        {
            cout << "No events recorded.\n";
        }
        else
        {
            displayInOrder(root);
        }
    }

    TimelineNode* getRoot() { return root; }
};

// ===============================================
// GLOBAL OBJECTS
// ===============================================
SecurityLogList masterList;
SecurityLogList bruteForceList;
SecurityLogList rdpList;
AttackTimeline timeline;

// ===============================================
// HELPER: Extract value from XML line
// ===============================================
string extract(string line, string startTag, string endTag)
{
    size_t start = line.find(startTag);
    if (start == string::npos) return "";
    start += startTag.length();

    size_t end = line.find(endTag, start);
    if (end == string::npos) return "";

    return line.substr(start, end - start);
}

// ===============================================
// MAIN PARSING FUNCTION
// ===============================================
bool parseXMLFile(string path)
{
    ifstream file(path.c_str());
    if (!file.is_open())
    {
        cout << "\nERROR: File not found or cannot be opened!\n";
        cout << "Please check the path and try again.\n\n";
        return false;
    }

    cout << "\nParsing security log file... Please wait...\n";

    string line;
    bool inEvent = false;
    LogEntryNode* current = nullptr;
    int failedLogins = 0;

    while (getline(file, line))
    {
        if (line.find("<Event>") != string::npos)
        {
            inEvent = true;
            current = new LogEntryNode();
        }
        else if (line.find("</Event>") != string::npos && current != nullptr)
        {
            // Analyze the event
            if (current->getEventID() == "4625")
            {
                failedLogins++;
                current->setAttackType("Brute Force Attempt");
                current->setSeverity("MEDIUM");
                if (failedLogins > 10)
                {
                    current->setSeverity("CRITICAL");
                    current->setAttackType("BRUTE FORCE ATTACK DETECTED!");
                }

                bruteForceList.insertLog(current);
                masterList.insertLog(current);

                string msg = "Failed login: " + current->getAccountName() + " from " + current->getSourceIP();
                timeline.insertEvent(current->getTimeCreated(), msg, current->getSeverity());
            }
            else if (current->getEventID() == "4624" && current->getLogonType() == "10")
            {
                current->setAttackType("Remote Desktop Login");
                current->setSeverity("HIGH");

                rdpList.insertLog(current);
                masterList.insertLog(current);

                string msg = "RDP Login: " + current->getAccountName() + " from " + current->getSourceIP();
                timeline.insertEvent(current->getTimeCreated(), msg, current->getSeverity());
            }

            inEvent = false;
        }

        if (inEvent && current != nullptr)
        {
            if (line.find("<EventID>") != string::npos)
                current->setEventID(extract(line, ">", "<"));
            else if (line.find("SystemTime") != string::npos)
                current->setTimeCreated(extract(line, "'", "'"));
            else if (line.find("TargetUserName") != string::npos)
                current->setAccountName(extract(line, ">", "<"));
            else if (line.find("IpAddress") != string::npos)
            {
                string ip = extract(line, ">", "<");
                if (ip == "::1" || ip == "127.0.0.1" || ip == "-") ip = "LOCALHOST";
                current->setSourceIP(ip);
            }
            else if (line.find("LogonType") != string::npos)
                current->setLogonType(extract(line, ">", "<"));
        }
    }

    file.close();
    cout << "File parsed successfully!\n\n";
    return true;
}

// ===============================================
// MENU SYSTEM
// ===============================================
void showMenu()
{
    cout << "==================================================\n";
    cout << "     WINDOWS SECURITY LOG ANALYZER v3.0\n";
    cout << "==================================================\n";
    cout << " 1. Load Security Log File (.xml)\n";
    cout << " 2. View Brute Force Attacks\n";
    cout << " 3. View RDP (Remote Desktop) Logins\n";
    cout << " 4. View Attack Timeline (Time-Sorted)\n";
    cout << " 5. Generate Final Report\n";
    cout << " 6. Exit\n";
    cout << "--------------------------------------------------\n";
    cout << " Enter choice (1-6): ";
}

int main()
{
    int choice;
    string filePath;

    while (true)
    {
        showMenu();
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid input! Please enter a number.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            cout << "\nEnter full path to XML file:\n> ";
            cin.ignore();
            getline(cin, filePath);
            parseXMLFile(filePath);
            break;

        case 2:
            cout << "\n=== BRUTE FORCE ATTACKS ===\n";
            bruteForceList.displayAll();
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            break;

        case 3:
            cout << "\n=== REMOTE DESKTOP LOGINS ===\n";
            rdpList.displayAll();
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            break;

        case 4:
            timeline.showTimeline();
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            break;

        case 5:
            cout << "\n";
            cout << "=============================================\n";
            cout << "           FINAL THREAT REPORT\n";
            cout << "=============================================\n";
            cout << "Data Structures Used   : Singly Linked List + BST\n";
            cout << "Total Events Parsed    : Success\n";
            cout << "Brute Force Detection  : Active\n";
            cout << "Timeline Sorting       : Binary Search Tree\n";
            cout << "Project by             : Your Name\n";
            cout << "=============================================\n";
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            break;

        case 6:
            cout << "\nThank you for using the analyzer!\n\n";
            return 0;

        default:
            cout << "\nInvalid choice! Try again.\n";
        }
    }

    return 0;
}