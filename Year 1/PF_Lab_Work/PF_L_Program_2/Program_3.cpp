#include <iostream>
using namespace std;

int main(){
	int side_1, side_2, side_3;
	cout << "Enter first side: ";
	cin >> side_1;
	cout << "Enter second side: ";
	cin >> side_2;
	cout << "Enter third side: ";
	cin >> side_3;
	
	cout << endl;
	
	if((side_1 + side_2 > side_3) && (side_2 + side_3 > side_1) && (side_1 + side_3 > side_2))
		cout << "The given sides form a triangle." << endl;
	else
		cout << "The given sides doesn\'t form triangle." << endl;
	
	if(side_1 == side_2 && side_1 == side_3)
		cout << "It is an Equilateral (all sides equal) triangle.";
	else if(side_1 == side_2 || side_1 == side_3 || side_2 == side_3)
	 	cout << "It is an Isosceles (two sides equal) triangle.";
	else
		cout << "It is an Scalene (no sides equal) triangle.";	
 	
}
