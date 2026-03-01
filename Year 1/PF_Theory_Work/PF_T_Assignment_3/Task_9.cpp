#include <iostream>
using namespace std;

int main(){
    int whole, max = 0, min, sum = 0, avrg;
    
    cout << "Enter a whole number: ";
    cin >> whole;
    
    min = whole;

    for(int i = 0; i <= whole; i++){
        if(max < i){
            max = i;
        }
        if(min > i){
            min = i;
        }
        sum += i;
    }
	
    avrg = sum / (whole + 1);
    
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Average: " << avrg << endl;

}

