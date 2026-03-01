#include <iostream>
#include <fstream> // Required for file stream operations (ifstream)
#include <string>  // Required for the std::string type and getline

using namespace std;

// Function to read and process the file
void readFileAndPrint(string filename) {
    // 1. Create an input file stream object
    ifstream inputFile(filename);

    // Check if the file was opened successfully
    if (!inputFile.is_open()) {
        cerr << "🚨 Error: Could not open the file \"" << filename << "\"." << endl;
        return;
    }

    string line;
    int lineNumber = 1;

    cout << "\n--- Starting File Read Loop ---" << endl;

    // 2. The core logic: Read line by line until EOF
    while (getline(inputFile, line)) {
        // This block executes ONLY if getline was successful (returned 'true')

        cout << "Line " << lineNumber << " Read Successfully. Content: \"" << line << "\"" << endl;
        lineNumber++;
        
        // --- End of Loop Iteration ---
    }

    // 3. Check why the loop terminated (it should be EOF)
    if (inputFile.eof()) {
        cout << "--- Loop Finished: Reached End-Of-File (EOF) ---" << endl;
    } else if (inputFile.fail()) {
        cout << "--- Loop Aborted: An input error occurred ---" << endl;
    } else {
        cout << "--- Loop Aborted for an unknown reason ---" << endl;
    }

    // Close the file stream
    inputFile.close();
}

int main() {
    // We will read from this file:
    const string fileName = "/home/lawliet/Videos/abc.xml";
    
    cout << "To test, make sure a file named '" << fileName << "' is in the same directory." << endl;
    
    readFileAndPrint(fileName);

    return 0;
}