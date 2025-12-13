#include <iostream>
using namespace std;

int main(){
	char abc;
	cin >> abc;

	cout << "This is me....\n";
	cin.ignore();
	cin.get();
	cout << "This is not me....\n";
	cin.get();
	cout << "Told you it's not me....";
}
