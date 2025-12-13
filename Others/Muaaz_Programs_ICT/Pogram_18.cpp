#include <iostream>
using namespace std;

int main(){
    float biology, physics, chemistry, math, computer;
    cout << "Enter numbers of subjects (5): ";
    cin >> biology >> chemistry >> physics >> math >> computer;

    float total = biology + physics + chemistry + math + computer;
    float percentage = (total / 500) * 100;

    if(percentage >= 90){
        cout << "Grade A";
    }
	else if(percentage >= 80){
        cout << "Grade B";
    }
	else if(percentage >= 70){
        cout << "Grade C";
    }
	else if(percentage >= 60){
        cout << "Grade D";
    }
	else if(percentage >= 40){
        cout << "Grade E";
    }
	else{
        cout << "Grade F";
    }
}

