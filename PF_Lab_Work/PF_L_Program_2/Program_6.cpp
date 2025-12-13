#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	string username, orignal_username, password, orignal_password;
	int select, attempts = 3;
	
	start:
	system("cls");
	cout << setw(30) << setfill('_') << "Welcome to our Website!" << left 
		 << setw(10) << setfill('_') << "" << endl;
	cout << setw(40) << setfill('-') << "" << endl;
	
	cout << " 1. Signup (press 1)" << endl << " 2. Login (press 2)\n 0. Exit (press 0)" << endl;
	cout << setw(40) << setfill('-') << "" << endl;
	cout << "Select: ";
	cin >> select;
	
	if(select == 1){
		system("cls");
		cout << " 1. Create New account (press 1) \n 2. Exit (hit enter any key)" << endl << "Select: ";
		cin >> select;
		if(select == 1){
			system("cls");
			cout << "Creating your new account." << endl;
			cout << "Enter new username: ";
			cin >> orignal_username;
			cout << "Enter new password: ";
			cin >> orignal_password;
			goto start;
		}
		else
			cout << "See you later.";
			return 0;
	}

	else if(select == 2){
			system("cls");
			cout << " 1. Login in your Account (press 1) \n 2. Exit (hit enter any key)" << endl;
			cin >> select;
			
			if(select == 1){
				system("cls");
				while(attempts > 0){
				cout << "Enter Username:- ";
				cin >> username;
				cout << "Enter Password:- ";
				cin >> password;
					if(password == orignal_password && username == orignal_username){
						system("cls");
						cout << "You successfully Loged in your Account!" << endl;
						return 0;
					}
					else if(password != orignal_password && username != orignal_username){
	        			attempts--;       			
		        		if(attempts != 0){
		        			system("cls");
							cout << "Invalid credentials!! (" << attempts << " attempts left.)" << endl;
						}
						else{
							system("cls");
		            		cout << "Acess Denied. Check back after 2 hours!" << endl;
		            	}
		            	}
		    }
		}
		    else
		    	system("cls");
				cout << "See you later"; 
				return 0;       	
	
	}
	else if(select == 0){
		system("cls");
		cout << "See you later.";
		return 0;
	}
	else
		goto start;	
		system("cls");
		cout << "You enterd invalid Selection.";
			
}
