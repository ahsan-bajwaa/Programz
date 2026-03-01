#include <iostream>
#include <fstream>
using namespace std;

class Startup
{
public:
    string string_input;

    // Verify the input is valid..
    bool is_valid_input(string input, char range)
    {
        if (!isdigit(input[0]) || input.length() != 1 || input[0] < '1' || input[0] > range)
        {
            cout << "Invalid input! Please enter a number between 1 and " << range << ".\n";
            return true;
        }
        return false;
    }

    // Verify the file is correct one..
    bool is_valid_file(string input)
    {
        // Check file path is openable..
        ifstream file(input);
        if (!file.is_open())
        {
            cout << "Error: File not found or cannot be opened!\n";
            return true;
        }

        // Check if the have has entension..
        int dot_position = input.find_last_of('.');

        if (dot_position == string::npos)
        {
            cout << "Error: File has no extension! (.log, .evt, .evtx required)\n";
            return true;
        }

        string ext = input.substr(dot_position);  // save the string from . to on word (like: .txt or .log , etc).

        // Convert extension to lowercase manually
        for (int i = 0; i < ext.length(); i++)
        {
            if (ext[i] >= 'A' && ext[i] <= 'Z')
            {
                ext[i] = ext[i] + 32;
            }
        }

        if (ext != ".log" && ext != ".evt" && ext != ".evtx")
        {
            cout << "Error: Unsupported file type! Only .log, .evt or .evtx allowed.\n";
            return true;
        }

        cout << "File verified successfully.\n";
        return false;
    }


    void selecting_OS()
    {
        do
        {
            cout << "============   Welcome to Report Analysis System =============\n";
            cout << "Select the Operating System:-\n";
            cout << "=> (1) Windows\n";
            cout << "=> (2) Linux\n";
            cout << "Choice: ";
            cin >> string_input;

        } while (is_valid_input(string_input, '2'));
        // Call next function..
        get_file_path();
    }

    void get_file_path()
    {
        do
        {
            cout << "Paste the log file path:\nPath: ";
            cin >> string_input;

        } while (is_valid_file(string_input));
    }
};

int main()
{
    Startup s;
    s.selecting_OS();
}
