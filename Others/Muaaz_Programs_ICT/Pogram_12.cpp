#include <iostream>
using namespace std;

int main() {
    int month;
    cin >> month;
   
   	if(month == 2){
        cout << "28 or 29 days";
    }
	else if(month == 4 || month == 6 || month == 9 || month == 11){
        cout << "30 days";
    }
	else{
        cout << "31 days";
    }
}

