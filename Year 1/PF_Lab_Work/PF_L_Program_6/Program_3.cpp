#include <iostream>
using namespace std;

int main(){
	int angle_1, angle_2, angle_3, sum;
	cout << "Enter first side of triangle: ";
	cin >> angle_1;
	cout << "Enter second side of triangle: ";
	cin >> angle_2;
	cout << "Enter third side of triangle: ";
	cin >> angle_3;
	
	sum = angle_1 + angle_2 + angle_3;
	
	if(sum == 180){
		if((angle_1 < 90) && (angle_2 < 90) && (angle_3 < 90)){
			cout << "Acute triangle.";
		}
		else if((angle_1 > 90) || (angle_2 > 90) || (angle_3 > 90)){
			cout << "Obtuse triangle.";
		}
		else if((angle_1 == 90) || (angle_2 == 90) || (angle_3 == 90)){
			cout << "Right triangle.";
		}
	}
	else{
		cout << "It's invalid trianlge!!";
	}
	return 0;
}
