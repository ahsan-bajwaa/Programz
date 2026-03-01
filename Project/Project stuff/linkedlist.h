#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class LogNode
{
private:
    string timestamp;
    string ip;
    string user;
    string action;
    string port;
    string raw;
    LogNode *next;

public:
    // Constructor
    LogNode(string t, string i, string u, string a, string p, string r)
    {
        timestamp = t;
        ip = i;
        user = u;
        action = a;
        port = p;
        raw = r;
        next = nullptr;
    }

    // Getters
    string getTimestamp() { return timestamp; }
    string getIp() { return ip; }
    string getUser() { return user; }
    string getAction() { return action; }
    string getPort() { return port; }
    string getRaw() { return raw; }
    LogNode *getNext() { return next; }

    // Setters
    void setTimestamp(string t) { timestamp = t; }
    void setIp(string i) { ip = i; }
    void setUser(string u) { user = u; }
    void setAction(string a) { action = a; }
    void setPort(string p) { port = p; }
    void setRaw(string r) { raw = r; }
    void setNext(LogNode *n) { next = n; }
};

class LinkedList
{
private:
    LogNode *head;
    LogNode *tail;
    vector<LogNode *> logVector;

    // Helper methods for parsing
    LogNode *parseLogLine(string line)
    {
        stringstream ss(line);
        string date, time, ip_part, user_part, status_part, port_part;

        // Extract basic tokens
        ss >> date >> time >> ip_part >> user_part >> status_part >> port_part;

        if (ss.fail())
        {
            return nullptr; // Parsing failed
        }

        // Extract values using helper function
        string ip = extractValue(ip_part, "IP=");
        string user = extractValue(user_part, "USER=");
        string action = extractValue(status_part, "STATUS=");
        string port = extractValue(port_part, "PORT=");

        // Validate required fields
        if (ip.empty() || user.empty() || action.empty() || port.empty())
        {
            return nullptr; // Missing required fields
        }

        // Create and return new LogNode
        string timestamp = date + " " + time;
        return new LogNode(timestamp, ip, user, action, port, line);
    }

    bool isSecurityRelevant(string line)
    {
        // We only care about lines that contain authentication status
        return line.find("STATUS=") != string::npos;
    }

    string extractValue(string text, string key)
    {
        size_t pos = text.find(key);
        if (pos != string::npos)
        {
            return text.substr(pos + key.length());
        }
        return ""; // Key not found
    }

public: 
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Basic getters
    LogNode *getHead() { return head; }
    LogNode *getTail() { return tail; }
    vector<LogNode *> &getLogVector() { return logVector; }
    int getSize() { return logVector.size(); }

    // Core file operations
    void loadFromFile(string filename)
    {
        clearList(); // Clear existing data first

        ifstream file(filename);
        if (!file.is_open())
        {
            cout << "[ERROR] Cannot open file: " << filename << endl;
            return;
        }

        string line;
        int loadedCount = 0;

        while (getline(file, line))
        {
            if (line.empty() || line[0] == '#' || !isSecurityRelevant(line))
                continue;

            LogNode *newNode = parseLogLine(line);
            if (newNode != nullptr)
            {
                insertNode(newNode);
                loadedCount++;
            }
        }

        file.close();
        cout << "[INFO] Loaded " << loadedCount << " security-relevant logs from " << filename << endl;
    }

    void insertNode(LogNode *newNode)
    {
        if (!newNode)
            return;

        // Add to linked list
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->setNext(newNode);
            tail = newNode;
        }

        // Add to vector for easy access
        logVector.push_back(newNode);
    }

    // Display methods
    void displayAll()
    {
        if (head == nullptr)
        {
            cout << "[INFO] No logs to display." << endl;
            return;
        }

        LogNode *current = head;
        int count = 0;

        while (current != nullptr)
        {
            cout << "Log #" << ++count << " | Time: " << current->getTimestamp()
                 << " | IP: " << current->getIp()
                 << " | User: " << current->getUser()
                 << " | Action: " << current->getAction()
                 << " | Port: " << current->getPort() << endl;
            current = current->getNext();
        }
    }

    void displayByIp(string ip)
    {
        vector<LogNode *> ipLogs = getLogsByIp(ip);
        cout << "[INFO] Displaying " << ipLogs.size() << " logs for IP: " << ip << endl;

        for (int i = 0; i < ipLogs.size(); i++)
        {
            LogNode *node = ipLogs[i];
            cout << "Time: " << node->getTimestamp()
                 << " | User: " << node->getUser()
                 << " | Action: " << node->getAction()
                 << " | Port: " << node->getPort() << endl;
        }
    }

    void displayByUser(string user)
    {
        vector<LogNode *> userLogs = getLogsByUser(user);
        cout << "[INFO] Displaying " << userLogs.size() << " logs for User: " << user << endl;

        for (int i = 0; i < userLogs.size(); i++)
        {
            LogNode *node = userLogs[i];
            cout << "Time: " << node->getTimestamp()
                 << " | IP: " << node->getIp()
                 << " | Action: " << node->getAction()
                 << " | Port: " << node->getPort() << endl;
        }
    }

    void displayByAction(string action)
    {
        vector<LogNode *> actionLogs = getLogsByAction(action);
        cout << "[INFO] Displaying " << actionLogs.size() << " logs with Action: " << action << endl;

        for (int i = 0; i < actionLogs.size(); i++)
        {
            LogNode *node = actionLogs[i];
            cout << "Time: " << node->getTimestamp()
                 << " | IP: " << node->getIp()
                 << " | User: " << node->getUser()
                 << " | Port: " << node->getPort() << endl;
        }
    }

    void displayByPort(string port)
    {
        vector<LogNode *> portLogs = getLogsByPort(port);
        cout << "[INFO] Displaying " << portLogs.size() << " logs for Port: " << port << endl;

        for (int i = 0; i < portLogs.size(); i++)
        {
            LogNode *node = portLogs[i];
            cout << "Time: " << node->getTimestamp()
                 << " | IP: " << node->getIp()
                 << " | User: " << node->getUser()
                 << " | Action: " << node->getAction() << endl;
        }
    }

    // Filtering methods for attack detection
    vector<LogNode *> getLogsByIp(string ip)
    {
        vector<LogNode *> result;
        for (int i = 0; i < logVector.size(); i++)
        {
            if (logVector[i]->getIp() == ip)
            {
                result.push_back(logVector[i]);
            }
        }
        return result;
    }

    vector<LogNode *> getLogsByUser(string user)
    {
        vector<LogNode *> result;
        for (int i = 0; i < logVector.size(); i++)
        {
            if (logVector[i]->getUser() == user)
            {
                result.push_back(logVector[i]);
            }
        }
        return result;
    }

    vector<LogNode *> getLogsByAction(string action)
    {
        vector<LogNode *> result;
        for (int i = 0; i < logVector.size(); i++)
        {
            if (logVector[i]->getAction() == action)
            {
                result.push_back(logVector[i]);
            }
        }
        return result;
    }

    vector<LogNode *> getLogsByPort(string port)
    {
        vector<LogNode *> result;
        for (int i = 0; i < logVector.size(); i++)
        {
            if (logVector[i]->getPort() == port)
            {
                result.push_back(logVector[i]);
            }
        }
        return result;
    }

    vector<LogNode *> getLogsByTimeRange(string startTime, string endTime)
    {
        vector<LogNode *> result;
        for (int i = 0; i < logVector.size(); i++)
        {
            string logTime = logVector[i]->getTimestamp();
            if (logTime >= startTime && logTime <= endTime)
            {
                result.push_back(logVector[i]);
            }
        }
        return result;
    }

    // Statistical methods for pattern detection
    map<string, int> getFailureCountByIp()
    {
        map<string, int> failureCount;
        for (int i = 0; i < logVector.size(); i++)
        {
            if (logVector[i]->getAction() == "Failed")
            {
                failureCount[logVector[i]->getIp()]++;
            }
        }
        return failureCount;
    }

    map<string, int> getSuccessCountByIp()
    {
        map<string, int> successCount;
        for (int i = 0; i < logVector.size(); i++)
        {
            if (logVector[i]->getAction() == "Accepted")
            {
                successCount[logVector[i]->getIp()]++;
            }
        }
        return successCount;
    }

    map<string, int> getPortCountByIp()
    {
        map<string, int> portCount;
        for (int i = 0; i < logVector.size(); i++)
        {
            portCount[logVector[i]->getIp()]++;
        }
        return portCount;
    }

    map<string, set<string>> getUniquePortsByIp()
    {
        map<string, set<string>> uniquePorts;
        for (int i = 0; i < logVector.size(); i++)
        {
            uniquePorts[logVector[i]->getIp()].insert(logVector[i]->getPort());
        }
        return uniquePorts;
    }

    map<string, set<string>> getUniqueUsersByIp()
    {
        map<string, set<string>> uniqueUsers;
        for (int i = 0; i < logVector.size(); i++)
        {
            uniqueUsers[logVector[i]->getIp()].insert(logVector[i]->getUser());
        }
        return uniqueUsers;
    }

    // Time-based analysis methods
    map<string, vector<LogNode *>> groupLogsByIp()
    {
        map<string, vector<LogNode *>> grouped;
        for (int i = 0; i < logVector.size(); i++)
        {
            grouped[logVector[i]->getIp()].push_back(logVector[i]);
        }
        return grouped;
    }

    map<string, vector<LogNode *>> groupLogsByUser()
    {
        map<string, vector<LogNode *>> grouped;
        for (int i = 0; i < logVector.size(); i++)
        {
            grouped[logVector[i]->getUser()].push_back(logVector[i]);
        }
        return grouped;
    }

    // Utility methods
    void clearList()
    {
        LogNode *current = head;
        while (current != nullptr)
        {
            LogNode *next = current->getNext();
            delete current;
            current = next;
        }
        head = tail = nullptr;
        logVector.clear();
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

private:
    // Helper methods for parsing
    LogNode *parseLogLine(string line)
    {
        // Implementation coming next...
        return nullptr; // Placeholder
    }

    bool isSecurityRelevant(string line)
    {
        return line.find("STATUS=") != string::npos;
    }

    string extractValue(string line, string key)
    {
        // Implementation coming next...
        return ""; // Placeholder
    }
};

#endif