#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int marks;

public:
    void setName(string nam) 
    {
        name = nam;
    }

    void setMarks(int mrks)
    {
        if (mrks >= 0 && mrks <= 100)
        {
            marks = mrks;
        } 
        else
        {
            cout << "Invalid marks entery!" << endl;
            marks = 0;
        }
    }

   
    string getName() {
        return name;
    }

    int getMarks() {
        return marks;
    }
};

int main() {
    Student obj;
    string name;
    int marks;

    cout << "Enter student name: ";
    cin >> name;
    obj.setName(name);

    cout << "Enter student marks (0-100): ";
    cin >> marks;
    obj.setMarks(marks);

    cout << "\nStudent Details:" << endl;
    cout << "Name: " << obj.getName() << endl;
    cout << "Marks: " << obj.getMarks() << endl;

    return 0;
}