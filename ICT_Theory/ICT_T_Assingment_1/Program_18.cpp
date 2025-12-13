#include <iostream>
using namespace std;

int main(){
	int biology, physics, chemistry, math, computer, sum;
	char grade;
	float percentage;
    cout << "Enter marks for Biology: ";
    cin >> biology;
	cout << "Enter marks for Physics: ";
    cin >> physics;
    cout << "Enter marks for Chemistry: ";
    cin >> chemistry;
    cout << "Enter marks for Computer: ";
    cin >> computer;
    cout << "Enter marks for Mathematics: ";
    cin >> math;
    
	
	sum = physics + biology + chemistry + math + computer;
	percentage = (sum * 1.0) / 500 * 100;
	
	if(percentage >= 90){
		grade = 'A';
	}
	else if(percentage >= 80){
		grade = 'B';	
	}
	else if(percentage >= 70){
		grade = 'C';	
	}
	else if(percentage >= 60){
		grade = 'D';
	}
	else if(percentage >= 40){
		grade = 'E';
	}
	else if(percentage <= 40){
		grade = 'F';
	}
	
	cout << "Precentage: " << percentage << endl;
	cout << "Grade: " << grade;
}
