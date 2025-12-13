#include<iostream>
#include<string>
using namespace std;

int main(){
	string str;
	int length;
	int vowelCount = 0,consonantCount = 0,digitCount = 0,
	specialCharCount = 0;
	cout<<"Enter your string : ";
	getline(cin,str);
	length = str.length();
	
	for(int i=0; i<length; i++){
		str[i] = tolower(str[i]);
		if(str[i]=='a' || str[i]=='e' || str[i]=='i'
		|| str[i]=='o' || str[i]=='u' ){
			vowelCount++;
		}
		else if(str[i]>='a' && str[i]<='z'){
			consonantCount++;
		}
		else if(str[i]>='0' && str[i]<='9'){
			digitCount++;
		}
		else{
			specialCharCount++;
		}
		
	}
	cout<<"Vowels in your string is = "<<vowelCount<<endl;
	cout<<"Consonants in your string is = "<<consonantCount<<endl;
	cout<<"Digits in your string is = "<<digitCount<<endl;
	cout<<"Special Characters in your string is = "<<specialCharCount<<endl;
	
	
	return 0;
}
