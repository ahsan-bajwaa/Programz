#include <iostream>
using namespace std;

int main(){
	int number;
	int answer, reminder;
	cout << "Enter a decimal number: ";
	cin >> number;
	
	answer = number;
	cout << "Answer is: ";
	while(answer != 1){
		for(int i = answer; i > 0; i++){
			cout << answer / 2 << " ";
			answer /= 2;
			break;
		}
	}
	cout << endl << endl;
	reminder = number;
	cout << "Reminder is: ";
	while(reminder > 0){
		for(int i = reminder; i > 0; i++){
			cout << reminder % 2 << " ";
			reminder /= 2;
			break;
		}
	}
	
}
