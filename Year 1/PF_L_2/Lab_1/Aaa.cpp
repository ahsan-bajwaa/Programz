#include <iostream>
using namespace std;

class Student {
public:
	string name;
	int age;
	string rollNumber;
};

int main(){
	Student obj1;
	
	obj1.name = "Ahsan";
	obj1.age = 21;
	obj1.rollNumber = "003";
	
	cout << "Name: " << obj1.name << endl;
	cout << "Age: " << obj1.age << endl;
	cout << "Roll Number: " << obj1.rollNumber;
}