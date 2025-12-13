#include <iostream>
using namespace std;

int main(){
    int number, max_num, min_num;
    bool first_input = true;

    while(true){
        cout << "Enter a number: ";
        cin >> number;
		
        if(number < 0){
            break;
        }

        if(first_input){
            max_num = min_num = number;
            first_input = false;
        }
		else{
            if(number > max_num){
                max_num = number;
            }
            if(number < min_num){
                min_num = number;
            }
        }
        cout << "Maximum number: " << max_num;
   		cout << "Minimum number: " << min_num;
    }
}

