#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

int main(){
	string password;
	int select, length, attempts = 5;
	bool character = false, number = false, symbol = false;
	char cha;
	bool flag = true;
	
	while(flag){
		
		cout << setw(35) << setfill('_') << " " <<  endl;
		cout << " 1. See Password Guidlines.\n 2. Set Password." << endl;
		cout << setw(35) << setfill('-') << " " <<  endl;
		cout << "Select: ";
		cin >> select;
		
		switch(select){
	
			case 1: {
				cout << endl;
				system("cls");
				cout << setw(73) << setfill('_') << " " <<  endl;
				cout << "To set a password you have to enter \'Character\', \'Number\', and \'Symbol\'!" << endl;
				cout << "Password lenght must be greather than \"8\" digits!" << endl;
				cout << setw(73) << setfill('-') << " " <<  endl;
				break;
			}
			case 2:	{
				system("cls");
				cout << "Enter Password to create. (" << attempts << " attempts left) : ";
				cin >> password;
				attempts--;
				length = password.length();
				
				if(length >= 8){				
					for(int i = 0; i < length; i++){
						cha = password[i];
						
						if(isdigit(cha))
							number = true;
						else if(isalpha(cha))
							character = true;
						else if(!isdigit(cha) && !isalpha(cha))
							symbol = true;			
					}
				}
				else{
					system("cls");
					cout << "You entered Invalid Password!" << endl << endl;
					break;
				}
				
				if(number && character && symbol){
					system("cls");
					cout << "You have entered \"Strong Password\"!" << endl << endl;
					break;	
				}
				else if(number || character || symbol){
					system("cls");
					cout << "You have entered \"Weak Password\"!" << endl << endl;
					break;	
				}
			}		
		}
			
		if(attempts == 0){
			system("cls");
			cout << "You are out of attempts. Try another time!" << endl;
			flag = false;
		}
	}
	return 0;
}

