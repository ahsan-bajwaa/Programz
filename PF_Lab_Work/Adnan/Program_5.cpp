#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    for(int i = 1; i <= N-2; i++){
        for(int j = i + 1; j <= N-1; j++){
            for(int k = j + 1; k <= N; k++){
                
                if(i * i + j * j == k * k){
                    cout << "(" << i << ", " << j << ", " << k << ")" << endl;
                }
            }
        }
    }
	return 0;
}

