#include <iostream>
using namespace std;

void print_numbers(int number){
    if(number == 0){
        return;
    }
	
    cout << number << " ";
    print_numbers(number - 1);
    if(number != 1){
    cout << number << " ";
	}
}

int main(){
    int number;
    cout << "Enter a number: ";
    cin >> number;
	
    print_numbers(number);
    cout << endl;

}

