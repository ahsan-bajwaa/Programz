#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <set> // Added for tracking unique IPs or details
using namespace std;

// The AttackReporter is a simple structure to collect and print alerts.
// We use simple maps and vectors instead of custom binary trees for simplicity.
class AttackReporter {
private:
    // Structure to hold details for a single attack type (e.g., BRUTE_FORCE)
    struct Report {
        string ip;
        int count = 0;
        vector<string> evidence; // Stores specific details (Time, User, Action)
    };

    // Maps Attack Type ("BRUTE_FORCE", "PORT_SCAN") to a map of IP addresses
    // The inner map holds all collected data for a specific IP and attack type.
    map<string, map<string, Report>> reports;

public:
    AttackReporter() {}

    // Adds a detected attack event with detailed evidence.
    void addAttack(string type, string ip, string detail = "") {
        // Check if the IP address is already logged for this attack type
        if (reports[type].find(ip) == reports[type].end()) {
             reports[type][ip] = {ip, 0, {}}; // Initialize if first time
        }

        reports[type][ip].count++;

        // Add the evidence detail (e.g., "5 failures in 10s at 10:00:12")
        // Using a set to ensure evidence is unique for a single detection run.
        if (!detail.empty()) {
            reports[type][ip].evidence.push_back(detail);
        }
    }

    // Prints all collected alerts for a given attack type.
    void printAttacks(string type) {
        cout << "\n================ REPORT: " << type << " ================\n";

        if (reports.find(type) == reports.end() || reports[type].empty()) {
            cout << "No " << type << " attacks detected." << endl;
            cout << "======================================================\n";
            return;
        }

        // Iterate through all reported IP addresses for this attack type
        for (auto const& [ip, data] : reports[type]) {
            cout << "\n[ALERT] " << type << " detected from IP: " << data.ip 
                 << " (Total alert incidents: " << data.count << ")" << endl;
            
            if (!data.evidence.empty()) {
                cout << "   Evidence Log (" << data.evidence.size() << " unique event(s)):" << endl;
                // Print the details collected
                for (const string &ev : data.evidence) {
                    cout << "   -> " << ev << endl;
                }
            }
        }
        cout << "======================================================\n";
    }
};

#endif