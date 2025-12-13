#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ===============================================
// CLASS: Node for Log Entry (Singly linked)
// ===============================================
class LogEntryNode
{
private:
    string event_id;
    string time_created;
    string account_name;
    string source_ip;
    string logon_type;
    string attack_type;
    string severity;
    LogEntryNode* link;

public:
    LogEntryNode()
    {
        event_id = "";
        time_created = "";
        account_name = "";
        source_ip = "";
        logon_type = "";
        attack_type = "";
        severity = "LOW";
        link = nullptr;
    }

    // Setters
    void set_event_id(const string& id)        { event_id = id; }
    void set_time_created(const string& t)     { time_created = t; }
    void set_account_name(const string& n)     { account_name = n; }
    void set_source_ip(const string& ip)       { source_ip = ip; }
    void set_logon_type(const string& t)       { logon_type = t; }
    void set_attack_type(const string& t)      { attack_type = t; }
    void set_severity(const string& s)         { severity = s; }
    void set_link(LogEntryNode* next)          { link = next; }

    // Getters
    string get_event_id()      const { return event_id; }
    string get_time_created()  const { return time_created; }
    string get_account_name()  const { return account_name; }
    string get_source_ip()     const { return source_ip; }
    string get_logon_type()    const { return logon_type; }
    string get_attack_type()   const { return attack_type; }
    string get_severity()      const { return severity; }
    LogEntryNode* get_link()   const { return link; }
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

    // Insert node at tail. List takes ownership of the pointer.
    void insert_log(LogEntryNode* new_node)
    {
        if (new_node == nullptr) return;
        new_node->set_link(nullptr);
        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->set_link(new_node);
            tail = new_node;
        }
    }

    // Display all logs in this list
    void display_all()
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
            string t = temp->get_time_created();
            if (t.size() > 19) t = t.substr(0, 19);
            cout << count++ << ". [" << t << "] "
                 << temp->get_severity() << " -> " << temp->get_attack_type()
                 << " (" << temp->get_account_name() << " from " << temp->get_source_ip() << ")\n";
            temp = temp->get_link();
        }
    }

    // Clear list and free memory (manual cleanup)
    void clear()
    {
        LogEntryNode* cur = head;
        while (cur)
        {
            LogEntryNode* nxt = cur->get_link();
            delete cur;
            cur = nxt;
        }
        head = tail = nullptr;
    }

    LogEntryNode* get_head() { return head; }
};

// ===============================================
// CLASS: Binary Search Tree for Timeline
// ===============================================
class TimelineNode
{
public:
    string time_created;
    string message;
    string severity;
    TimelineNode* left;
    TimelineNode* right;

    TimelineNode(const string& t, const string& m, const string& s)
    {
        time_created = t;
        message = m;
        severity = s;
        left = right = nullptr;
    }
};

class AttackTimeline
{
private:
    TimelineNode* root;

    TimelineNode* insert_node(TimelineNode* node, const string& time, const string& msg, const string& sev)
    {
        if (node == nullptr)
            return new TimelineNode(time, msg, sev);

        // lexicographic compare works if time is ISO-like. i.e "apple" is less than "banana" (because 'a' < 'b').
        if (time < node->time_created)
            node->left = insert_node(node->left, time, msg, sev);
        else
            node->right = insert_node(node->right, time, msg, sev);
        return node;
    }

    void display_in_order(TimelineNode* node)
    {
        if (node == nullptr) return;
        display_in_order(node->left);
        string t = node->time_created;
        if (t.size() > 19) t = t.substr(0, 19);
        cout << " [" << t << "] " << node->severity << " -> " << node->message << endl;
        display_in_order(node->right);
    }

    void clear_nodes(TimelineNode* node)
    {
        if (node == nullptr) return;
        clear_nodes(node->left);
        clear_nodes(node->right);
        delete node;
    }

public:
    AttackTimeline() { root = nullptr; }

    void insert_event(const string& time, const string& msg, const string& sev)
    {
        root = insert_node(root, time, msg, sev);
    }

    void show_timeline()
    {
        cout << "\n=== ATTACK TIMELINE (CHRONOLOGICAL ORDER) ===\n";
        if (root == nullptr)
            cout << "No events recorded.\n";
        else
            display_in_order(root);
    }

    // manual cleanup to free allocated nodes
    void clear()
    {
        clear_nodes(root);
        root = nullptr;
    }
};

// ===============================================
// SIMPLE COUNTERS (linked lists) to avoid extra headers
// Track failed attempts per account and per IP
// ===============================================
struct CountNode
{
    string key;   // account_name or ip
    int count;
    CountNode* next;
    CountNode(const string& k) { key = k; count = 0; next = nullptr; }
};

// increment counter for key, return new count
int increment_count(CountNode*& head, const string& key)
{
    CountNode* cur = head;
    CountNode* prev = nullptr;
    while (cur)
    {
        if (cur->key == key)
        {
            cur->count++;
            return cur->count;
        }
        prev = cur;
        cur = cur->next;
    }
    // not found, create
    CountNode* n = new CountNode(key);
    n->count = 1;
    if (prev == nullptr) head = n;
    else prev->next = n;
    return 1;
}

// get count for key (0 if not found)
int get_count(CountNode* head, const string& key)
{
    CountNode* cur = head;
    while (cur)
    {
        if (cur->key == key) return cur->count;
        cur = cur->next;
    }
    return 0;
}

// free counter list
void clear_counts(CountNode*& head)
{
    CountNode* cur = head;
    while (cur)
    {
        CountNode* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    head = nullptr;
}

// ===============================================
// GLOBAL OBJECTS (only specific security lists)
// ===============================================
SecurityLogList brute_force_list;
SecurityLogList rdp_list;
SecurityLogList suspicious_list; // for "Account Takeover Suspected" or other suspicious events
AttackTimeline timeline;

// Counters to track failed attempts (simple lists)
CountNode* account_fail_head = nullptr;
CountNode* ip_fail_head = nullptr;

// ===============================================
// HELPER: Extract value from XML line
// (simple and same as before)
// ===============================================
string extract(const string& line, const string& start_tag, const string& end_tag)
{
    size_t start = line.find(start_tag);
    if (start == string::npos) return "";
    start += start_tag.length();
    size_t end = line.find(end_tag, start);
    if (end == string::npos) return "";
    return line.substr(start, end - start);
}

// helper: extract attribute value (handles ' or ")
// looks for attrName (like SystemTime) then '=' then quote
string extract_attribute(const string& line, const string& attr_name)
{
    size_t pos = line.find(attr_name);  // pos = 13
    if (pos == string::npos) return "";  // (13 == false)
    pos = line.find('=', pos);  //     <TimeCreated SystemTime="2025-11-29T10:00:00Z"/>
    if (pos == string::npos) return ""; // pos 23...
    // skip spaces
    pos++;  // 24
    // while (pos < line.size() && isspace((unsigned char)line[pos])) pos++;  // Use to skip any space if founded..
    if (pos >= line.size()) return "";
    char q = line[pos];
    if (q != '"' && q != '\'') return "";  // (" != " && " != "\'")
    size_t start = pos + 1;  // 25..
    size_t end = line.find(q, start);   // 46..
    if (end == string::npos) return "";
    return line.substr(start, end - start);  // 45 - 25 = 21
}

// ===============================================
// MAIN PARSING FUNCTION (simple, no smart pointers)
// ===============================================
bool parseXMLFile(const string& path)
{
    ifstream file(path);
    if (!file.is_open())
    {
        cout << "\nERROR: File not found or cannot be opened!\n";
        cout << "Please check the path and try again...\n\n";
        return false;
    }

    cout << "\nParsing security log file... Please wait...\n";

    string line;
    bool in_event = false;
    LogEntryNode* current = nullptr;

    // configuration thresholds (simple ints)
    const int threshold_brute_force_account = 6; // after this many failed attempts for same account -> brute force
    const int threshold_account_takeover = 3;    // if successful after >= this failed attempts -> suspect takeover
    const int threshold_ip_failures = 10;        // if IP has this many failed attempts -> suspicious

    while (getline(file, line))
    {
        // start of an event
        if (line.find("<Event>") != string::npos)
        {
            in_event = true;
            current = new LogEntryNode();
        }
        // end of an event: analyze and decide where to put the node (or delete)
        else if (line.find("</Event>") != string::npos && current != nullptr)
        {
            // decide threat type and insert into exactly one list (priority: AccountTakeover -> BruteForce -> RDP)
            string event_id = current->get_event_id();
            string account = current->get_account_name();
            string ip = current->get_source_ip();
            string logon = current->get_logon_type();

            bool inserted = false;

            // 1) If this is a successful login and there were recent failed attempts against same account => Account Takeover Suspected
            if (!inserted && event_id == "4624")
            {
                int failed_by_account = get_count(account_fail_head, account);
                if (failed_by_account >= threshold_account_takeover)
                {
                    current->set_attack_type("Account Takeover Suspected");
                    current->set_severity("CRITICAL");
                    suspicious_list.insert_log(current);
                    inserted = true;

                    string msg = "Account takeover suspected: " + account + " from " + ip;
                    timeline.insert_event(current->get_time_created(), msg, current->get_severity());
                }
            }

            // 2) Brute Force Attempt detection (many failed logins for same account)
            if (!inserted && event_id == "4625")
            {
                int failed_by_account = increment_count(account_fail_head, account);
                int failed_by_ip = increment_count(ip_fail_head, ip);

                current->set_attack_type("Brute Force Attempt");
                current->set_severity("MEDIUM");

                if (failed_by_account >= threshold_brute_force_account || failed_by_ip >= threshold_ip_failures)
                {
                    current->set_severity("CRITICAL");
                    current->set_attack_type("BRUTE FORCE ATTACK DETECTED!");
                }

                // Insert into brute force list
                brute_force_list.insert_log(current);
                inserted = true;

                string msg = "Failed login: " + account + " from " + ip;
                timeline.insert_event(current->get_time_created(), msg, current->get_severity());
            }

            // 3) Remote Desktop successful login
            if (!inserted && event_id == "4624" && logon == "10")
            {
                current->set_attack_type("Remote Desktop Login");
                current->set_severity("HIGH");
                rdp_list.insert_log(current);
                inserted = true;

                string msg = "RDP Login: " + account + " from " + ip;
                timeline.insert_event(current->get_time_created(), msg, current->get_severity());
            }

            // If not interesting -> free the node to avoid leak
            if (!inserted)
            {
                delete current;
            }

            in_event = false;
            current = nullptr;
        }

        // If inside an event, scan the line for all relevant fields.
        // Use independent ifs so multiple tags on the same line are handled.
        if (in_event && current != nullptr)
        {
            // EventID: value is between > and <
            if (line.find("<EventID>") != string::npos)
            {
                current->set_event_id(extract(line, ">", "<"));
            }

            // SystemTime may be an attribute or in-line; handle attribute style
            if (line.find("SystemTime") != string::npos)
            {
                string v = extract_attribute(line, "SystemTime");
                if (v != "") current->set_time_created(v);
            }

            // TargetUserName (account)
            if (line.find("TargetUserName") != string::npos)
            {
                current->set_account_name(extract(line, ">", "<"));
            }

            // IpAddress
            if (line.find("IpAddress") != string::npos)
            {
                string ip = extract(line, ">", "<");
                if (ip == "::1" || ip == "127.0.0.1" || ip == "-") ip = "LOCALHOST";
                current->set_source_ip(ip);
            }

            // LogonType
            if (line.find("LogonType") != string::npos)
            {
                current->set_logon_type(extract(line, ">", "<"));
            }
        }
    } // end while getline

    file.close();

    cout << "File parsed successfully!\n\n";
    return true;
}

// ===============================================
// MENU AND REPORT FUNCTIONS
// ===============================================
void show_menu()
{
    cout << "==================================================\n";
    cout << "     WINDOWS SECURITY LOG ANALYZER v3.0 (SIMPLE)\n";
    cout << "==================================================\n";
    cout << " 1. Load Security Log File (.xml)\n";
    cout << " 2. View Brute Force Attacks\n";
    cout << " 3. View RDP (Remote Desktop) Logins\n";
    cout << " 4. View Suspicious Events (Account Takeover Suspected)\n";
    cout << " 5. Show Attack Timeline (Time-Sorted)\n";
    cout << " 6. Generate Final Report\n";
    cout << " 7. Exit\n";
    cout << "--------------------------------------------------\n";
    cout << " Enter choice (1-7): ";
}

void generate_report()
{
    cout << "\n";
    cout << "=============================================\n";
    cout << "           FINAL THREAT REPORT\n";
    cout << "=============================================\n";

    // simple counts by walking lists
    int brute_count = 0;
    LogEntryNode* tmp = brute_force_list.get_head();
    while (tmp) { brute_count++; tmp = tmp->get_link(); }

    int rdp_count = 0;
    tmp = rdp_list.get_head();
    while (tmp) { rdp_count++; tmp = tmp->get_link(); }

    int suspicious_count = 0;
    tmp = suspicious_list.get_head();
    while (tmp) { suspicious_count++; tmp = tmp->get_link(); }

    cout << "Detected Threat Types  : BruteForce, RDP Login, Account Takeover Suspected\n";
    cout << "Brute Force Events     : " << brute_count << "\n";
    cout << "RDP Login Events       : " << rdp_count << "\n";
    cout << "Suspicious Events      : " << suspicious_count << "\n";
    cout << "Timeline Events Stored : (see timeline)\n";
    cout << "---------------------------------------------\n";
    cout << "Notes:\n";
    cout << "- Brute Force: repeated failed logins for same account or many fails from same IP.\n";
    cout << "- RDP Login: successful logon type 10 (Remote Desktop).\n";
    cout << "- Account Takeover Suspected: successful login after multiple failed attempts for same account.\n";
    cout << "=============================================\n\n";
}

// Clear all data structures and free memory (call before exit)
void cleanup_all()
{
    brute_force_list.clear();
    rdp_list.clear();
    suspicious_list.clear();
    timeline.clear();

    clear_counts(account_fail_head);
    clear_counts(ip_fail_head);
}

// ===============================================
// MAIN
// ===============================================
int main()
{
    int choice = 0;
    string file_path;

    while (true)
    {
        show_menu();
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
            getline(cin, file_path);
            parseXMLFile(file_path);
            break;

        case 2:
            cout << "\n=== BRUTE FORCE ATTACKS ===\n";
            brute_force_list.display_all();
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            break;

        case 3:
            cout << "\n=== REMOTE DESKTOP LOGINS ===\n";
            rdp_list.display_all();
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            break;

        case 4:
            cout << "\n=== SUSPICIOUS EVENTS (ACCOUNT TAKEOVER SUSPECTED) ===\n";
            suspicious_list.display_all();
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            break;

        case 5:
            timeline.show_timeline();
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            break;

        case 6:
            generate_report();
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            break;

        case 7:
            cout << "\nCleaning up and exiting...\n";
            cleanup_all();
            cout << "Goodbye!\n\n";
            return 0;

        default:
            cout << "\nInvalid choice! Try again.\n";
        }
    }


    return 0;
}
