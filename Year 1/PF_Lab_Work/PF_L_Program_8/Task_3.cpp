#include <iostream>
using namespace std;

int sum_of_numbers(int number){
    if (number == 0){
        return 0;
    }
    return number + sum_of_numbers(number - 1);
}

int main(){
    int number;
    cout << "Enter a number: ";
    cin >> number;
	
    int result = sum_of_numbers(number);
    cout << "Sum is: " << result << endl;

}

