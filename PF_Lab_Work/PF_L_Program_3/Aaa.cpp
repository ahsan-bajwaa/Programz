#include<iostream>
using namespace std;

int main(){

/*
   *
  ***
 *****
*******
*/
//Uper half diamond
   for(int i=1; i<=4; i++){
   	
   	//spaces
   	for(int j=3; j>=i; j--){
   		cout<<" ";
	   }
   
   	//stars
   	for(int k=1; k<=2*i-1; k++){
   		
   		cout<< "*";
	   }
   	cout<<endl;
   }}
//
////Lower Half Diamond
//  for(int i=3; i>=1; i--){
   	
   	//spaces
   
//   	for(int j=3; j>=i; j--){
//   		cout<<" ";
//	   }
   	
   	//stars
//   	for(int k=1; k<=2*i-1; k++){
//   		
//   		cout<<"*";
//	   }
//   	cout<<endl;
//   }
//		
//	return 0;
//}

