#include <iostream>
using namespace std;

int main(){
	int a_value, b_value, c_value, disc;
	cout << "Enter value for 'a': ";
	cin >> a_value;
	cout << "Enter value for 'b': ";
	cin >> b_value;
	cout << "Enter value for 'c': ";
	cin >> c_value;
	
	disc = b_value * b_value - (4 * a_value * c_value);
	
	cout << "Dicsriment: " << disc << endl;
	
	if(disc > 0){
		cout << "Two distinct real roots.";
	}
	else if(disc == 0){
		cout << "One real root.";
	}
	else{
		cout << "No Real Roots.";
	}
}
