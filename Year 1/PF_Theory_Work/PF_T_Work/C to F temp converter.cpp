#include <iostream>
using namespace std;

int main(){
	int c,f,x;
	
	cout << "Choose temperature in Unit.\n Press 1 for C. \n Press 2 for F.\n \t \t ";
	cin >> x;
	
	if(x==1){
	
	cout << "Now enter Temperature.";
	cin >> x;
	f = c * (9.0 / 5.0) + 32;
	
	cout << "The entered temperature in F is " << f;
	
}
	
	else {
		cout << "Enter number in F : ";
		cin >> x;
		c = (f - 32) * 5/9;
		cout << "The entered temperature in C is " << c;
}
}











