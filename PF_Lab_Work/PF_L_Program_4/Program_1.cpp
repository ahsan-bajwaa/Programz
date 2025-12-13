#include<iostream>
using namespace std;

int main(){
	int number = 1;
	
   	for(int i=1; i<=4; i++){
   		
		if (i <= 3) {
            cout << " ";
        }
   
   		for(int j=3; j>=i; j--){
   			cout<<" ";
	   }
   		
		for(int k = 1; k <= i; k++){
			cout << number << " ";
			number += 2;
		}
   	cout<<endl;
   }
}
