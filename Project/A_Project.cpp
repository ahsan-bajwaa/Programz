#include <iostream>
#include <string>
#include <sstream>
#include <limits> // Required for numeric_limits
#include "linkedlist.h"
#include "tree.h"
#include "bruteforce.h"
#include "portscan.h"

using namespace std;

// Forward declarations for detector classes (assuming they are in the headers)
class BruteForceDetector; 
class PortScanDetector;

/**
 * @brief Prompts the user for a log file name and validates the .log extension.
 * If the filename does not end in .log, the user is prompted again.
 * @return The validated log file name string.
 */
string getValidLogFileName() {
    string filename;
    bool valid = false;
    
    // Clear any leftover characters from previous input
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (!valid) {
        cout << "Enter the log file name (must end with .log): ";
        getline(cin, filename);

        // Check for empty filename
        if (filename.empty()) {
            cout << "[ERROR] File name cannot be empty. Please try again." << endl;
            continue;
        }

        // Check if the file name ends with ".log" (case-sensitive)
        if (filename.length() >= 4 && filename.substr(filename.length() - 4) == ".log") {
            // Additional check: verify file exists and can be opened
            ifstream testFile(filename);
            if (testFile.is_open()) {
                testFile.close();
                valid = true;
            } else {
                cout << "[ERROR] Cannot open file '" << filename << "'. Please check if file exists." << endl;
            }
        } else {
            cout << "[ERROR] Invalid file extension. Please enter a file ending in .log." << endl;
        }
    }
    return filename;
}

/**
 * @brief Prompts the user for a menu choice and validates the input.
 * Loop until valid input (integer between 1 and 5) is received.
 * @return The validated menu choice integer.
 */
int getValidChoice() {
    int choice;
    
    while (true) {
        cout << "Enter your choice (1-5): ";
        
        if (cin >> choice) {
            // Input was a valid integer, now check range
            if (choice >= 1 && choice <= 5) {
                return choice; // Valid input received
            } else {
                cout << "[ERROR] Invalid choice. Please enter a number between 1 and 5.\n";
            }
        } else {
            // Input failed (not an integer)
            cout << "[ERROR] Invalid input. Please enter a number.\n";
            
            // Clear the error flags on cin
            cin.clear();
            // Ignore the rest of the bad input in the buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

/**
 * @brief Clears the input buffer to prevent any leftover characters
 */
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    cout << "==============================" << endl;
    cout << "  Linux Log Analysis System   " << endl;
    cout << "  (BF & Port Scan Only)       " << endl;
    cout << "==============================" << endl;

    LinkedList logs;  // Linked list to store filtered logs
    bool logsLoaded = false;
    string currentLogFile = "";

    // Instantiate Detectors
    BruteForceDetector bfDetector;
    PortScanDetector psDetector;
    
    while (true) {
        cout << "\nMenu:\n";
        cout << "1) Load Logs (Current: " << (logsLoaded ? currentLogFile : "NONE") << ")\n";
        cout << "2) Detect Brute Force Attack\n";
        cout << "3) Detect Port Scan\n"; 
        cout << "4) Display Filtered Logs\n"; 
        cout << "5) Exit\n"; 
        
        // Get the validated choice from the user
        int choice = getValidChoice();
        clearInputBuffer(); // Clear any leftover newline after numeric input

        switch (choice) {
            case 1: {
                // Clear any potential previous data before loading new file
                logs = LinkedList(); 
                
                // Get the validated filename
                currentLogFile = getValidLogFileName();
                
                cout << "[INFO] Attempting to load logs from " << currentLogFile << "...\n";
                logs.loadFromFile(currentLogFile);
                
                // Check if the list is empty (indicates file not found or no relevant logs)
                if (logs.getHead() != nullptr) {
                    cout << "[INFO] Logs loaded and filtered successfully from " << currentLogFile << ".\n";
                    logsLoaded = true;
                    
                    // Reset detectors to clear any previous results
                    bfDetector = BruteForceDetector();
                    psDetector = PortScanDetector();
                } else {
                    cout << "[WARNING] Could not load data or no important logs found in " << currentLogFile << ". Check filename and contents.\n";
                    logsLoaded = false;
                    currentLogFile = "";
                }
                break;
            }
            case 2:
                if (!logsLoaded) {
                    cout << "[ERROR] Logs must be loaded first (Option 1)!\n";
                    break;
                }
                cout << "[INFO] Detecting Brute Force Attacks...\n";
                try {
                    bfDetector.loadFromList(logs);
                    bfDetector.detect();
                    bfDetector.printResults();
                } catch (const exception& e) {
                    cout << "[ERROR] Brute force detection failed: " << e.what() << endl;
                }
                break;
            
            case 3: 
                if (!logsLoaded) {
                    cout << "[ERROR] Logs must be loaded first (Option 1)!\n";
                    break;
                }
                cout << "[INFO] Detecting Port Scans...\n";
                try {
                    psDetector.loadFromList(logs);
                    psDetector.detect();
                    psDetector.printResults();
                } catch (const exception& e) {
                    cout << "[ERROR] Port scan detection failed: " << e.what() << endl;
                }
                break;

            case 4: 
                if (!logsLoaded) {
                    cout << "[ERROR] Logs must be loaded first (Option 1)!\n";
                    break;
                }
                cout << "[INFO] Displaying all filtered logs from " << currentLogFile << ":\n";
                cout << "======================================================\n";
                logs.display();
                cout << "======================================================\n";
                break;

            case 5: 
                cout << "[INFO] Exiting program. Goodbye!\n";
                return 0;

            default:
                // This case is technically unreachable due to the getValidChoice() loop,
                // but kept for robustness.
                cout << "[ERROR] Unexpected error. Restarting menu.\n";
                break;
        }
    }

    return 0;
}