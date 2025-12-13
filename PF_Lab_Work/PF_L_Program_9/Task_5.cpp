#include <iostream>
using namespace std;

int main(){
	string Array[3] = {"Apple", "Banana", "Mango"};
	
	for(int i = 0; i < 3; i++){
		int length = 0;
		
		for(int  j= 0; j < Array[i].length(); j++){
			length++;
		}
		cout << "Length of '" << Array[i] << "' is: " << length << endl;
	}
}
