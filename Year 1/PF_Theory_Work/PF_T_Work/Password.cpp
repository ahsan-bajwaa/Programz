#include <iostream>
#include <string>
using namespace std;
int main(){
	string password = "aaa";
	string Password;
	
	int enter = 3;
	while (enter > 0){
		cout << "Let see what you enter here. " ;
		cin >> Password;
		if (password == Password){
			cout << "Wow, you gussed correctly" << endl;
		break;
		}
		else {
			enter--;}
		if (enter == 0){
			
			cout << "You failed. Why don't do you take brake?" << endl;
			}
		else {
			switch (enter){
			
				case 2:
					cout << "Finally you failed in your first try. " << endl << endl;
					break;
					
				case 1:
					cout << "Aha you failed in your second attempt. " << endl << endl;
					
				}
						
					
		}	
		
			
				
			
		
		
	}
	
	 
}

