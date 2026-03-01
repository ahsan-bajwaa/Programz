#include <iostream>
using namespace std;

void Aaa(int &a) {
	a = 10;
}

int main(){
	int a;
	a = 1;
	
	Aaa(a);
	
	cout << a;
}