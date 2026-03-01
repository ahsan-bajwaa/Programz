#ifndef PORTSCAN_H
#define PORTSCAN_H

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <chrono>
#include <cstdio>
#include <sstream>
#include "linkedlist.h"
#include "tree.h" // Includes the simple AttackReporter

using namespace std;

class PortScanDetector {
private:
    AttackReporter tree;

    // Simple struct to track a successful connection probe
    struct Entry {
        string ip;
        string port;
        chrono::system_clock::time_point timestamp;
    };

    // Vector to store relevant log entries
    vector<Entry> entries;

    // Helper to convert time_point back to a readable string
    string timeToString(chrono::system_clock::time_point tp) {
        std::time_t t = chrono::system_clock::to_time_t(tp);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&t), "%H:%M:%S");
        return ss.str();
    }

    // Helper to parse the YYYY-MM-DD HH:MM:SS string into a C++ time_point
    chrono::system_clock::time_point parseTime(const string &t) {
        std::tm tm = {};
        int year, month, day, hour, min, sec;
        
        sscanf(t.c_str(), "%d-%d-%d %d:%d:%d",
               &year, &month, &day,
               &hour, &min, &sec);

        tm.tm_year = year - 1900;
        tm.tm_mon = month - 1;
        tm.tm_mday = day;
        tm.tm_hour = hour;
        tm.tm_min = min;
        tm.tm_sec = sec;
        tm.tm_isdst = -1; 
        
        return chrono::system_clock::from_time_t(mktime(&tm));
    }

public:
    PortScanDetector() {}

    // ------------------------------------------------------------------
    // FIX: Clears the internal vector to prevent cumulative counting error.
    // ------------------------------------------------------------------
    void loadFromList(LinkedList &list) {
        entries.clear(); // *** CRITICAL FIX: Clear data before every load ***
        
        LogNode *cur = list.getHead();
        while (cur != nullptr) {
            // A port scan is usually detected by a high volume of *successful*
            // connections (probes) across many ports.
            if (cur->action == "Accepted") { 
                Entry e;
                e.ip = cur->ip;
                e.timestamp = parseTime(cur->timestamp);
                
                // The port number is in the message (e.g., PORT=80)
                size_t pos = cur->message.find("PORT=");
                if (pos != string::npos) {
                    // Extract the port number after "PORT="
                    e.port = cur->message.substr(pos + 5); 
                }
                
                entries.push_back(e);
            }
            cur = cur->next;
        }
    }

    // Core Logic: Detects 10 or more *successful connections* (probes) 
    // from a single IP address regardless of the time window, indicating 
    // a high volume of activity often associated with scanning.
    void detect() {
        // Group timestamps by IP address
        unordered_map<string, vector<chrono::system_clock::time_point>> groups;
        
        for (auto &e : entries)
            groups[e.ip].push_back(e.timestamp);

        // Analyze each group
        for (auto &pair : groups) {
            string ip = pair.first;
            auto &times = pair.second;

            // Detection Condition: 10 or more accepted connections
            if (times.size() >= 10) { 
                
                sort(times.begin(), times.end());

                string startTime = timeToString(times.front());
                string endTime = timeToString(times.back());

                string detail = to_string(times.size()) + " successful connection attempts detected between " + 
                                startTime + " and " + endTime + ".";
                
                tree.addAttack("PORT_SCAN", ip, detail);
            }
        }
    }

    void printResults() {
        tree.printAttacks("PORT_SCAN");
    }
};

#endif