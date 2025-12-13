#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class LogEntryNode{
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
    LogEntryNode(){
        event_id = "";
        time_created = "";
        account_name = "";
        source_ip = "";
        logon_type = "";
        attack_type = "";
        severity = "LOW";
        link = nullptr;
    }
    void set_event_id(const string& id){event_id = id;}
    void set_time_created(const string& t){time_created = t;}
    void set_account_name(const string& n){account_name = n;}
    void set_source_ip(const string& ip){source_ip = ip;}
    void set_logon_type(const string& t){logon_type = t;}
    void set_attack_type(const string& t){attack_type = t;}
    void set_severity(const string& s){severity = s;}
    void set_link(LogEntryNode* next){link = next;}
    string get_event_id()const{return event_id;}
    string get_time_created()const{return time_created;}
    string get_account_name()const{return account_name;}
    string get_source_ip()const{return source_ip;}
    string get_logon_type()const{return logon_type;}
    string get_attack_type()const{return attack_type;}
    string get_severity()const{return severity;}
    LogEntryNode* get_link()const{return link;}
};

class SecurityLogList{
private:
    LogEntryNode* head;
    LogEntryNode* tail;
public:
    SecurityLogList(){
        head = nullptr;
        tail = nullptr;
    }
    void insert_log(LogEntryNode* new_node){
        if(new_node==nullptr)return;
        new_node->set_link(nullptr);
        if(head==nullptr){
            head=new_node;
            tail=new_node;
        }else{
            tail->set_link(new_node);
            tail=new_node;
        }
    }
    void display_all(){
        LogEntryNode* temp=head;
        int count=1;
        if(temp==nullptr){
            cout<<"No logs found.\n";
            return;
        }
        while(temp!=nullptr){
            string t=temp->get_time_created();
            if(t.size()>19)t=t.substr(0,19);
            cout<<count++<<". ["<<t<<"] "
                 <<temp->get_severity()<<" -> "<<temp->get_attack_type()
                 <<" ("<<temp->get_account_name()<<" from "<<temp->get_source_ip()<<")\n";
            temp=temp->get_link();
        }
    }
    void clear(){
        LogEntryNode* cur=head;
        while(cur){
            LogEntryNode* nxt=cur->get_link();
            delete cur;
            cur=nxt;
        }
        head=tail=nullptr;
    }
    LogEntryNode* get_head(){return head;}
};

class TimelineNode{
public:
    string time_created;
    string message;
    string severity;
    TimelineNode* left;
    TimelineNode* right;
    TimelineNode(const string& t,const string& m,const string& s){
        time_created=t;
        message=m;
        severity=s;
        left=right=nullptr;
    }
};

class AttackTimeline{
private:
    TimelineNode* root;
    TimelineNode* insert_node(TimelineNode* node,const string& time,const string& msg,const string& sev){
        if(node==nullptr)
            return new TimelineNode(time,msg,sev);
        if(time<node->time_created)
            node->left=insert_node(node->left,time,msg,sev);
        else
            node->right=insert_node(node->right,time,msg,sev);
        return node;
    }
    void display_in_order(TimelineNode* node){
        if(node==nullptr)return;
        display_in_order(node->left);
        string t=node->time_created;
        if(t.size()>19)t=t.substr(0,19);
        cout<<" ["<<t<<"] "<<node->severity<<" -> "<<node->message<<endl;
        display_in_order(node->right);
    }
    void clear_nodes(TimelineNode* node){
        if(node==nullptr)return;
        clear_nodes(node->left);
        clear_nodes(node->right);
        delete node;
    }
public:
    AttackTimeline(){root=nullptr;}
    void insert_event(const string& time,const string& msg,const string& sev){
        root=insert_node(root,time,msg,sev);
    }
    void show_timeline(){
        cout<<"\n=== ATTACK TIMELINE (CHRONOLOGICAL ORDER) ===\n";
        if(root==nullptr)
            cout<<"No events recorded.\n";
        else
            display_in_order(root);
    }
    void clear(){
        clear_nodes(root);
        root=nullptr;
    }
};

struct CountNode{
    string key;
    int count;
    CountNode* next;
    CountNode(const string& k){key=k;count=0;next=nullptr;}
};

int increment_count(CountNode*& head,const string& key){
    CountNode* cur=head;
    CountNode* prev=nullptr;
    while(cur){
        if(cur->key==key){
            cur->count++;
            return cur->count;
        }
        prev=cur;
        cur=cur->next;
    }
    CountNode* n=new CountNode(key);
    n->count=1;
    if(prev==nullptr)head=n;
    else prev->next=n;
    return 1;
}

int get_count(CountNode* head,const string& key){
    CountNode* cur=head;
    while(cur){
        if(cur->key==key)return cur->count;
        cur=cur->next;
    }
    return 0;
}

void clear_counts(CountNode*& head){
    CountNode* cur=head;
    while(cur){
        CountNode* nxt=cur->next;
        delete cur;
        cur=nxt;
    }
    head=nullptr;
}

SecurityLogList brute_force_list;
SecurityLogList rdp_list;
SecurityLogList suspicious_list;
AttackTimeline timeline;
CountNode* account_fail_head=nullptr;
CountNode* ip_fail_head=nullptr;

string extract(const string& line,const string& start_tag,const string& end_tag){
    size_t start=line.find(start_tag);
    if(start==string::npos)return "";
    start+=start_tag.length();
    size_t end=line.find(end_tag,start);
    if(end==string::npos)return "";
    return line.substr(start,end-start);
}

string extract_attribute(const string& line,const string& attr_name){
    size_t pos=line.find(attr_name);
    if(pos==string::npos)return "";
    pos=line.find('=',pos);
    if(pos==string::npos)return "";
    pos++;
    while(pos<line.size()&&isspace((unsigned char)line[pos]))pos++;
    if(pos>=line.size())return "";
    char q=line[pos];
    if(q!='"'&&q!='\'')return "";
    size_t start=pos+1;
    size_t end=line.find(q,start);
    if(end==string::npos)return "";
    return line.substr(start,end-start);
}

bool parseXMLFile(const string& path){
    ifstream file(path);
    if(!file.is_open()){
        cout<<"\nERROR: File not found or cannot be opened!\n";
        cout<<"Please check the path and try again...\n\n";
        return false;
    }
    cout<<"\nParsing security log file... Please wait...\n";
    string line;
    bool in_event=false;
    LogEntryNode* current=nullptr;
    const int threshold_brute_force_account=6;
    const int threshold_account_takeover=3;
    const int threshold_ip_failures=10;
    while(getline(file,line)){
        if(line.find("<Event>")!=string::npos){
            in_event=true;
            current=new LogEntryNode();
        }else if(line.find("</Event>")!=string::npos&&current!=nullptr){
            string event_id=current->get_event_id();
            string account=current->get_account_name();
            string ip=current->get_source_ip();
            string logon=current->get_logon_type();
            bool inserted=false;
            if(!inserted&&event_id=="4624"){
                int failed_by_account=get_count(account_fail_head,account);
                if(failed_by_account>=threshold_account_takeover){
                    current->set_attack_type("Account Takeover Suspected");
                    current->set_severity("CRITICAL");
                    suspicious_list.insert_log(current);
                    inserted=true;
                    string msg="Account takeover suspected: "+account+" from "+ip;
                    timeline.insert_event(current->get_time_created(),msg,current->get_severity());
                }
            }
            if(!inserted&&event_id=="4625"){
                int failed_by_account=increment_count(account_fail_head,account);
                int failed_by_ip=increment_count(ip_fail_head,ip);
                current->set_attack_type("Brute Force Attempt");
                current->set_severity("MEDIUM");
                if(failed_by_account>=threshold_brute_force_account||failed_by_ip>=threshold_ip_failures){
                    current->set_severity("CRITICAL");
                    current->set_attack_type("BRUTE FORCE ATTACK DETECTED!");
                }
                brute_force_list.insert_log(current);
                inserted=true;
                string msg="Failed login: "+account+" from "+ip;
                timeline.insert_event(current->get_time_created(),msg,current->get_severity());
            }
            if(!inserted&&event_id=="4624"&&logon=="10"){
                current->set_attack_type("Remote Desktop Login");
                current->set_severity("HIGH");
                rdp_list.insert_log(current);
                inserted=true;
                string msg="RDP Login: "+account+" from "+ip;
                timeline.insert_event(current->get_time_created(),msg,current->get_severity());
            }
            if(!inserted){
                delete current;
            }
            in_event=false;
            current=nullptr;
        }
        if(in_event&&current!=nullptr){
            if(line.find("<EventID>")!=string::npos){
                current->set_event_id(extract(line,">","<"));
            }
            if(line.find("SystemTime")!=string::npos){
                string v=extract_attribute(line,"SystemTime");
                if(v!="")current->set_time_created(v);
            }
            if(line.find("TargetUserName")!=string::npos){
                current->set_account_name(extract(line,">","<"));
            }
            if(line.find("IpAddress")!=string::npos){
                string ip=extract(line,">","<");
                if(ip=="::1"||ip=="127.0.0.1"||ip=="-")ip="LOCALHOST";
                current->set_source_ip(ip);
            }
            if(line.find("LogonType")!=string::npos){
                current->set_logon_type(extract(line,">","<"));
            }
        }
    }
    file.close();
    cout<<"File parsed successfully!\n\n";
    return true;
}

void show_menu(){
    cout<<"==================================================\n";
    cout<<"     WINDOWS SECURITY LOG ANALYZER v3.0 (SIMPLE)\n";
    cout<<"==================================================\n";
    cout<<" 1. Load Security Log File (.xml)\n";
    cout<<" 2. View Brute Force Attacks\n";
    cout<<" 3. View RDP (Remote Desktop) Logins\n";
    cout<<" 4. View Suspicious Events (Account Takeover Suspected)\n";
    cout<<" 5. Show Attack Timeline (Time-Sorted)\n";
    cout<<" 6. Generate Final Report\n";
    cout<<" 7. Exit\n";
    cout<<"--------------------------------------------------\n";
    cout<<" Enter choice (1-7): ";
}

void generate_report(){
    cout<<"\n";
    cout<<"=============================================\n";
    cout<<"           FINAL THREAT REPORT\n";
    cout<<"=============================================\n";
    int brute_count=0;
    LogEntryNode* tmp=brute_force_list.get_head();
    while(tmp){brute_count++;tmp=tmp->get_link();}
    int rdp_count=0;
    tmp=rdp_list.get_head();
    while(tmp){rdp_count++;tmp=tmp->get_link();}
    int suspicious_count=0;
    tmp=suspicious_list.get_head();
    while(tmp){suspicious_count++;tmp=tmp->get_link();}
    cout<<"Detected Threat Types  : BruteForce, RDP Login, Account Takeover Suspected\n";
    cout<<"Brute Force Events     : "<<brute_count<<"\n";
    cout<<"RDP Login Events       : "<<rdp_count<<"\n";
    cout<<"Suspicious Events      : "<<suspicious_count<<"\n";
    cout<<"Timeline Events Stored : (see timeline)\n";
    cout<<"---------------------------------------------\n";
    cout<<"Notes:\n";
    cout<<"- Brute Force: repeated failed logins for same account or many fails from same IP.\n";
    cout<<"- RDP Login: successful logon type 10 (Remote Desktop).\n";
    cout<<"- Account Takeover Suspected: successful login after multiple failed attempts for same account.\n";
    cout<<"=============================================\n\n";
}

void cleanup_all(){
    brute_force_list.clear();
    rdp_list.clear();
    suspicious_list.clear();
    timeline.clear();
    clear_counts(account_fail_head);
    clear_counts(ip_fail_head);
}

int main(){
    int choice=0;
    string file_path;
    while(true){
        show_menu();
        cin>>choice;
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000,'\n');
            cout<<"\nInvalid input! Please enter a number.\n";
            continue;
        }
        switch(choice){
        case 1:
            cout<<"\nEnter full path to XML file:\n> ";
            cin.ignore();
            getline(cin,file_path);
            parseXMLFile(file_path);
            break;
        case 2:
            cout<<"\n=== BRUTE FORCE ATTACKS ===\n";
            brute_force_list.display_all();
            cout<<"\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            break;
        case 3:
            cout<<"\n=== REMOTE DESKTOP LOGINS ===\n";
            rdp_list.display_all();
            cout<<"\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            break;
        case 4:
            cout<<"\n=== SUSPICIOUS EVENTS (ACCOUNT TAKEOVER SUSPECTED) ===\n";
            suspicious_list.display_all();
            cout<<"\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            break;
        case 5:
            timeline.show_timeline();
            cout<<"\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            break;
        case 6:
            generate_report();
            cout<<"\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            break;
        case 7:
            cout<<"\nCleaning up and exiting...\n";
            cleanup_all();
            cout<<"Goodbye!\n\n";
            return 0;
        default:
            cout<<"\nInvalid choice! Try again.\n";
        }
    }
    return 0;
}