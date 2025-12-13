#include<iostream>
using namespace std;

//Fibonacci Sequence
//0,1,1,2,3,5,8,13,21,.....
//fab(n) = fab(n-1) + fab(n-2)
//fab(5) = fab(4) + fab(3)
//fab(5) = 3 + 2
//fab(5) = 5

int fab(int n){
	//base case
	if(n<=1){
		return n;
	}
	//recursive call
	return fab(n-1) + fab(n-2);
}


int main(){
	
cout<<fab(6)<<endl;

	return 0;
}
