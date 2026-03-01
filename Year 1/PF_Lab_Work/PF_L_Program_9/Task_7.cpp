#include <iostream>
using namespace std;

int main(){
	bool Array[8] = {true, false, true, true, false, true, true, true};
	int length = 0, no_of_ture = 0;
	for(int i = 0; i < 8; i++){
		if(Array[i] == true){
			no_of_ture++;
		}
		else{
			if(no_of_ture > length){
                length = no_of_ture;
            }
            no_of_ture = 0;
		}
		
		if(no_of_ture > length){
        	length = no_of_ture;
        }
	}
	cout << "Largest subarray of true values is : " << length;
}
