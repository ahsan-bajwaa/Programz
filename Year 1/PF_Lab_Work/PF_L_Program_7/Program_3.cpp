#include <iostream>
using namespace std;

void volume(int length, int width = 1, int height = 1){
	int volume;
	volume = length * width * height;
	cout << "Volume: " << volume;
}

int main(){
	int lenght, width = 1, height = 1;
	cout << "Enter lenght: ";
	cin >> lenght;
	cout << "Enter widht: ";
	cin >> width;
	cout << "Enter height: ";
	cin >> height;
	
	volume(lenght, width, height);
}
