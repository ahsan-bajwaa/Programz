#include <iostream>
using namespace std;

int main(){
	string Array[4] = {"Ahmad", "Adnan", "Muhammad", "Rizwan"};
	int shortest_size, longest_size;
	string shortest_string, longest_string;
	
	for(int i = 0; i < 4; i++){
		int count = 0;
		
		for(int j = 0; j < Array[i].length(); j++){
			count++;
		}
		if(i == 0){
			shortest_size = longest_size = count;
		}
		if(longest_size <= count){
			longest_size = count;
			longest_string = Array[i];
		}
		if(shortest_size >= count){
			shortest_size = count;
			shortest_string = Array[i];
		}
	}
	cout << "Longest string is: '" << longest_string << "'" << endl;
	cout << "Longest string size: " << longest_size << endl;
	cout << "Shortest string is: '" << shortest_string << "'" << endl;
	cout << "Shortest string size: " << shortest_size;
}
