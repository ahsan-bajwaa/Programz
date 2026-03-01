#include <iostream>
#include <fstream>
using namespace std;

// Structure to hold student details
struct Student {
    char name[50];
    char rollNo[20];
    char classSection[20];
    char course[50];
    char username[20];
    char password[20];
};

// Class to manage the university portal
class UniversityPortal {
private:
    Student students[100]; // Array to store up to 100 students
    int studentCount;     // Track number of students
    const char* filename = "students.txt"; // File to store student data

public:
    // Constructor to initialize student count
    UniversityPortal() {
        studentCount = 0;
        loadStudents(); // Load existing students from file
    }

    // Custom function to compare two strings
    bool stringCompare(const char* str1, const char* str2) {
        int i = 0;
        while (str1[i] != '\0' && str2[i] != '\0') {
            if (str1[i] != str2[i]) return false;
            i++;
        }
        return str1[i] == str2[i]; // True if both strings end together
    }

    // Function to load students from file
    void loadStudents() {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            while (inFile >> students[studentCount].name >> students[studentCount].rollNo
                   >> students[studentCount].classSection >> students[studentCount].course
                   >> students[studentCount].username >> students[studentCount].password) {
                studentCount++;
                if (studentCount >= 100) break; // Prevent overflow
            }
            inFile.close();
        }
    }

    // Function to save students to file
    void saveStudents() {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            for (int i = 0; i < studentCount; i++) {
                outFile << students[i].name << " " << students[i].rollNo << " "
                        << students[i].classSection << " " << students[i].course << " "
                        << students[i].username << " " << students[i].password << endl;
            }
            outFile.close();
        } else {
            cout << "Error: Unable to save data to file!" << endl;
        }
    }

    // Function to check if a string is empty or contains only spaces
    bool isEmptyOrSpaces(const char* str) {
        if (str[0] == '\0') return true;
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] != ' ') return false;
        }
        return true;
    }

    // Function to validate username (no spaces, not empty)
    bool isValidUsername(const char* username) {
        if (isEmptyOrSpaces(username)) return false;
        for (int i = 0; username[i] != '\0'; i++) {
            if (username[i] == ' ') return false;
        }
        return true;
    }

    // Function to check if username already exists
    bool usernameExists(const char* username) {
        for (int i = 0; i < studentCount; i++) {
            if (stringCompare(students[i].username, username)) {
                return true;
            }
        }
        return false;
    }

    // Function to add a new student (teacher only)
    void addStudent() {
        cout << "\n--------------------------------------------\n";
        cout << "          Add New Student\n";
        cout << "--------------------------------------------\n";

        if (studentCount >= 100) {
            cout << "Error: Maximum student limit reached!\n";
            return;
        }

        Student newStudent;
        cout << "Enter Name: ";
        cin >> newStudent.name;
        if (isEmptyOrSpaces(newStudent.name)) {
            cout << "Error: Name cannot be empty or spaces!\n";
            return;
        }

        cout << "Enter Roll Number: ";
        cin >> newStudent.rollNo;
        if (isEmptyOrSpaces(newStudent.rollNo)) {
            cout << "Error: Roll Number cannot be empty or spaces!\n";
            return;
        }

        cout << "Enter Class and Section (e.g., BSCS-1A): ";
        cin >> newStudent.classSection;
        if (isEmptyOrSpaces(newStudent.classSection)) {
            cout << "Error: Class and Section cannot be empty or spaces!\n";
            return;
        }

        cout << "Enter Course: ";
        cin >> newStudent.course;
        if (isEmptyOrSpaces(newStudent.course)) {
            cout << "Error: Course cannot be empty or spaces!\n";
            return;
        }

        cout << "Enter Username: ";
        cin >> newStudent.username;
        if (!isValidUsername(newStudent.username)) {
            cout << "Error: Username cannot be empty or contain spaces!\n";
            return;
        }
        if (usernameExists(newStudent.username)) {
            cout << "Error: Username already exists!\n";
            return;
        }

        cout << "Enter Password: ";
        cin >> newStudent.password;
        if (isEmptyOrSpaces(newStudent.password)) {
            cout << "Error: Password cannot be empty or spaces!\n";
            return;
        }

        students[studentCount] = newStudent;
        studentCount++;
        saveStudents();
        cout << "Student added successfully!\n";
        cout << "--------------------------------------------\n";
    }

    // Function to display all students (teacher only)
    void displayAllStudents() {
        cout << "\n--------------------------------------------\n";
        cout << "          All Students List\n";
        cout << "--------------------------------------------\n";
        if (studentCount == 0) {
            cout << "No students found!\n";
            return;
        }

        for (int i = 0; i < studentCount; i++) {
            cout << "Student " << i + 1 << ":\n";
            cout << "Name: " << students[i].name << "\n";
            cout << "Roll Number: " << students[i].rollNo << "\n";
            cout << "Class & Section: " << students[i].classSection << "\n";
            cout << "Course: " << students[i].course << "\n";
            cout << "Username: " << students[i].username << "\n";
            cout << "--------------------------------------------\n";
        }
    }

    // Function for student login and display details
    void studentLogin() {
        char username[20], password[20];
        cout << "\n--------------------------------------------\n";
        cout << "          Student Login\n";
        cout << "--------------------------------------------\n";
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;

        for (int i = 0; i < studentCount; i++) {
            if (stringCompare(students[i].username, username) &&
                stringCompare(students[i].password, password)) {
                cout << "\n--------------------------------------------\n";
                cout << "          Student Details\n";
                cout << "--------------------------------------------\n";
                cout << "Name: " << students[i].name << "\n";
                cout << "Roll Number: " << students[i].rollNo << "\n";
                cout << "Class & Section: " << students[i].classSection << "\n";
                cout << "Course: " << students[i].course << "\n";
                cout << "--------------------------------------------\n";
                return;
            }
        }
        cout << "Error: Invalid username or password!\n";
        cout << "--------------------------------------------\n";
    }

    // Function to display main menu
    void mainMenu() {
        char choice;
        do {
            cout << "\n============================================\n";
            cout << "      University Portal System\n";
            cout << "============================================\n";
            cout << "1. Teacher Login\n";
            cout << "2. Student Login\n";
            cout << "3. Exit\n";
            cout << "Enter choice (1-3): ";
            cin >> choice;

            if (cin.fail() || choice < '1' || choice > '3') {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Error: Please enter a valid choice (1-3)!\n";
                continue;
            }

            if (choice == '1') {
                teacherMenu();
            } else if (choice == '2') {
                studentLogin();
            } else if (choice == '3') {
                cout << "\nThank you for using the University Portal System!\n";
                cout << "============================================\n";
                break;
            }
        } while (true);
    }

    // Function to display teacher menu
    void teacherMenu() {
        char choice;
        char teacherPass[20] = "teacher123"; // Hardcoded teacher password
        char inputPass[20];
        cout << "\n--------------------------------------------\n";
        cout << "          Teacher Login\n";
        cout << "--------------------------------------------\n";
        cout << "Enter Password: ";
        cin >> inputPass;

        if (!stringCompare(inputPass, teacherPass)) {
            cout << "Error: Invalid teacher password!\n";
            return;
        }

        do {
            cout << "\n--------------------------------------------\n";
            cout << "          Teacher Menu\n";
            cout << "--------------------------------------------\n";
            cout << "1. Add New Student\n";
            cout << "2. Display All Students\n";
            cout << "3. Back to Main Menu\n";
            cout << "Enter choice (1-3): ";
            cin >> choice;

            if (cin.fail() || choice < '1' || choice > '3') {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Error: Please enter a valid choice (1-3)!\n";
 tingling:
                continue;
            }

            if (choice == '1') {
                addStudent();
            } else if (choice == '2') {
                displayAllStudents();
            } else if (choice == '3') {
                break;
            }
        } while (true);
    }
};

// Main function to run the program
int main() {
    UniversityPortal portal;
    portal.mainMenu();
    return 0;
}