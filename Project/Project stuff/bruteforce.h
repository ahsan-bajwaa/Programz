#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include <string>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <algorithm>
#include <cstdio>
#include "linkedlist.h"
#include "tree.h" // Includes the simple AttackReporter

using namespace std;

class BruteForceDetector {
private:
    AttackReporter tree; // Using the simplified reporter

    // Simple struct to hold relevant log data for brute force analysis
    struct Attempt {
        string ip;
        string user;
        chrono::system_clock::time_point timestamp;
        bool success; // True for Accepted, False for Failed
    };

    // Vector to store only the log entries needed for this detection
    vector<Attempt> attempts;  

    // Helper to convert time_point back to a readable string for reporting
    string timeToString(chrono::system_clock::time_point tp) {
        std::time_t t = chrono::system_clock::to_time_t(tp);
        std::stringstream ss;
        // Use localtime for proper display format
        ss << std::put_time(std::localtime(&t), "%H:%M:%S"); 
        return ss.str();
    }

    // Helper to parse the YYYY-MM-DD HH:MM:SS string into a C++ time_point
    chrono::system_clock::time_point parseTime(const string &t) {
        std::tm tm = {};
        int year, month, day, hour, min, sec;
        
        // Simple C-style parsing is used for easy understanding
        sscanf(t.c_str(), "%d-%d-%d %d:%d:%d",
               &year, &month, &day,
               &hour, &min, &sec);

        tm.tm_year = year - 1900; // tm_year is years since 1900
        tm.tm_mon = month - 1;    // tm_mon is 0-11
        tm.tm_mday = day;
        tm.tm_hour = hour;
        tm.tm_min = min;
        tm.tm_sec = sec;
        tm.tm_isdst = -1; // Standard C++ practice

        return chrono::system_clock::from_time_t(mktime(&tm));
    }

public:
    BruteForceDetector() {}

    // ------------------------------------------------------------------
    // FIX: Clears the internal vector to prevent cumulative counting error.
    // ------------------------------------------------------------------
    void loadFromList(LinkedList &list) {
        attempts.clear(); // *** CRITICAL FIX: Clear data before every load ***
        
        LogNode *cur = list.getHead();
        while (cur != nullptr) {
            // Only logs that are failed or accepted logins are relevant
            if (cur->action != "Failed" && cur->action != "Accepted") { 
                cur = cur->next; 
                continue; 
            }
            
            Attempt a;
            a.ip = cur->ip;
            a.user = cur->user;
            a.timestamp = parseTime(cur->timestamp);
            a.success = (cur->action == "Accepted"); // True if accepted
            
            attempts.push_back(a);
            cur = cur->next;
        }
    }

    // Core Logic: Detects 5 or more *consecutive failures* from the same IP 
    // for the same user within a 60-second window.
    void detect() {
        // 1. Group all attempts by IP address for efficient analysis
        unordered_map<string, vector<Attempt>> groupByIP;
        for (auto &a : attempts) 
            groupByIP[a.ip].push_back(a);

        // 2. Analyze each IP group independently
        for (auto &pair : groupByIP) {
            string ip = pair.first;
            auto &vec = pair.second;

            // Sorting by timestamp is essential for sequential analysis
            sort(vec.begin(), vec.end(),
                 [](const Attempt &a, const Attempt &b) {
                     return a.timestamp < b.timestamp;
                 });

            // Iterate through the sorted list, checking groups of 5
            for (size_t i = 0; i + 4 < vec.size(); i++) {
                
                // Get the timestamp of the first and fifth attempt in this window
                auto t1 = vec[i].timestamp;
                auto t5 = vec[i + 4].timestamp;
                
                // Calculate the time difference in seconds
                auto diff = chrono::duration_cast<chrono::seconds>(t5 - t1).count();

                // Check if all 5 attempts in the window were failures
                bool fiveFails = 
                    !vec[i].success && !vec[i+1].success && !vec[i+2].success && 
                    !vec[i+3].success && !vec[i+4].success;

                // Detection Condition: 5 consecutive failures within 60 seconds
                if (fiveFails && diff <= 60) {
                    string detail = "5 Failures for user '" + vec[i].user + "' in " + 
                                    to_string(diff) + " seconds. Start time: " + 
                                    timeToString(t1);
                    tree.addAttack("BRUTE_FORCE", ip, detail);
                    // Skip the next 4 entries since they were already part of this detection
                    i += 4; 
                }
            }
        }
    }

    void printResults() {
        tree.printAttacks("BRUTE_FORCE");
    }
};

#endif