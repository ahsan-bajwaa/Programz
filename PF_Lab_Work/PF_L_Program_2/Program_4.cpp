#include <iostream>
using namespace std;

int main(){
	string colour;
	int select = 0;
	cout << "Enter colour(red,yellow,green): ";
	cin >> colour;
	
	if(colour == "red")
		select = 1;
	else if(colour == "yellow")
		select = 2;
	else if(colour == "green")
		select = 3;
	else{
		system("cls");
		cout << "You entered Invalid colour." << endl;
		return 0;
	}
					
	switch(select){
	case 1:
		system("cls");
		cout << "\"Stop\"";
		break;
	case 2:
		system("cls");
		cout << "\"Prepare to Stop\"";
		break;
	case 3:
		system("cls");
		cout << "\"Go\"";
	}
	return 0;
}
