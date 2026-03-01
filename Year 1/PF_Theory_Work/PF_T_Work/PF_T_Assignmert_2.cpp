		// Ahsan Rehman
		// su92-bscbm-f24-003

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
	double a, b, c, z, Root1 ,Root2;
	cout << "Enter First Number. ";
	cin >> a;
	cout << "Enter Second Number. ";
	cin >> b;
	cout << "Enter Third Number. ";
	cin >> c;
	
	cout << fixed << setprecision(2);
	
	z = b*b - 4*a*c;
	
	if(z>0){	
	Root1 = (-b + sqrt(b*b - 4*a*c)) / (2*a);
	cout << "Solution for Root1 = " << Root1 << endl;

	Root2 = (-b - sqrt(b*b - 4*a*c)) / (2*a);
	cout << "Solution for Root2 = " << Root2;
}
	else 
	cout << "Roots are complex.";
}
