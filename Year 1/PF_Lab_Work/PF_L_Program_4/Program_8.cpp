#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	string name = "laptop", sample = "______";
	char word;
	bool flag = true, start = true;
	int select, attempts = name.length() + 1;
	
	while(start){
		cout << setw(40) << setfill('-') << " " << endl;
		cout << "Welcome to Word Guessing Game!" << endl;
		cout << setw(40) << setfill('-') << " " << endl;
		cout << "1. Start Game\n2. Game Instrution\n3. Exit\nSelect: ";
		cin >> select;
		switch(select){
			case 1: {
				cout << endl << sample << endl;	
				while(flag)	{
					bool correct = false;
					cout << endl << "Enter a character: ";
					cin >> word;
						
					for(int i = 0; i < name.length(); i++){
						char cha = name[i];
						if(word == cha){
							sample[i] = name[i];
							correct = true;							
						}	
					}
					if(correct){
						cout << "Wow! You gussed the character correctly.." << endl;
					}
					else if(!correct){
						cout << "It wasn\'t correct!!" << endl;
						attempts--;
					}
					cout << " Attempts: \"" << attempts << "\"" << endl;
					cout << setw(40) << setfill('-') << " ";
					cout  << endl << sample << endl;
					if(name == sample){
						cout << "Congratulation!! You guessed the word correctlly.." << endl;
						flag = false;
					}
					if(attempts == 0){
						cout << "You failed to guess the word. It is \"" << name << "\"." << endl;
						flag = false;
					}			
				}
				break;
			}
			
			case 2: {
				system("cls");
				cout << "You will be given one attempt greather than size of blank. You have to choose character to be filled in blank." << endl << endl;
				break;
			}
			
			case 3: {
				start = false;				
				system("cls");
				cout << "Take care!! Thanks for playing.";
				break;
			}
		}
	}
		
}

