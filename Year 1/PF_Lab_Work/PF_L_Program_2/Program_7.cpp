#include <iostream>
using namespace std;

int main(){
	char choice;
	int marks = 0;
	
	cout << "Welcome to your test. Get ready!!\n" << endl;
	
	// question No. 1
	cout << "\n1.What is the capital of Germany" << endl;
	cout << " a. Wellington \n b. Berlin \n c. Rome \n d. Bern" << endl;
	cout << "Choice: ";
	cin >> choice;
	
	switch(choice){
		case 'b':
			cout << "You entered answer correctly." << endl;
			marks = marks + 1;
			break;
		default:
			cout << "Ops. It answer was \"Berlin\"." << endl;
			break;	
	}
	
	cout << endl;
	
	// question No. 2
	cout << "\n2.What is the currency used in South Korea?" << endl;
	cout << " a. Yen \n b. Won \n c. Yuan \n d. Dollar" << endl;
	cout << "Choice: ";
	cin >> choice;
	
	switch(choice){
		case 'b':
			cout << "Wow. It was correct!" << endl;
			marks = marks + 1;
			break;
		default:
			cout << "No! It\'s not a correct answer. It\'s \"Won\"" << endl;
			break;
		}
	
	cout << endl;
	
	// question No. 3
	cout << "\n3.Which country is known as the \"Land of the Rising sun\"?" << endl;
	cout << " a. China \n b. Thiland \n c. Austrilia \n d. Japan" << endl;
	cout << "Choice: ";
	cin >> choice;
	
	switch(choice){
		case 'd':
			cout << "Wow. It was correct!" << endl;
			marks = marks + 1;
			break;
		default:
			cout << "Ops. It answer was \"Japan\"." << endl;
			break;
		}
		
	cout << endl;

	// question No. 4
	cout << "\n4.Which planet on our solar system has the most moons?" << endl;
	cout << " a. Jupiter \n b. Saturn \n c. Uranus \n d. Neptune" << endl;
	cout << "Choice: ";
	cin >> choice;
	
	switch(choice){
		case 'b':
			cout << "Wow. It was correct!" << endl;
			marks = marks + 1;
			break;
		default:
			cout << "Ops. It answer was \"Saturn\"." << endl;
			break;
		}
		
	cout << endl;
	
	// question No. 5
	cout << "\n5.Who is known as \"Father of Computers\"?" << endl;
	cout << " a. Alan Turing \n b. John von Neumann \n c. Charles Babbage \n d. Blaise Pascal" << endl;
	cout << "Choice: ";
	cin >> choice;
	
	switch(choice){
		case 'c':
			cout << "Wow. It was correct!" << endl;
			marks = marks + 1;
			break;
		default:
			cout << "Ops. It answer was \"Charles Babbage\"." << endl;
			break;
		}
		
	cout << "\n\n You Got \"" << marks << "\" mark(s) out of 5!";
	return 0;		
}
