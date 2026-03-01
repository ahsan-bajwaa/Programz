#include <iostream>
using namespace std;

class Student {
public:
	string name;
	int age;
	string rollNumber;
	
	void displayInfo(){
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Roll Number: " << rollNumber;
	}
	
};

int main(){
	Student obj1;
	
	obj1.name = "Rizwan";
	obj1.age = 20;
	obj1.rollNumber = "014";

	obj1.displayInfo();
}