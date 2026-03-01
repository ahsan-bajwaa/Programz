#include <iostream>
using namespace std;

int main(){
    int arr[9] = {1, 3, 2, 4, -1, 5, 0, -3, 3};
    
	int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    
	cout << "Enter a target number: ";
    cin >> target;
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] + arr[j] == target){
                cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
                break;
            }
        }
    }
}
