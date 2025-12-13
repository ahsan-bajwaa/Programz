#include<iostream>
using namespace std;

int main(){
 int arr_1[5] = {1,2,3,4,5};
 int arr_2[5] = {6,7,8,9,10};
 int arr_3[10];
int a = 5; 

    cout<<"Before Merge:-"<<endl;
     for(int i=0 ; i<5 ; i++){
          cout<<arr_1[i]<<" ";
 }
    cout<<endl;

    for(int j=0 ; j<5 ; j++){
         cout<<arr_2[j]<<" ";
 }
    cout<<endl;

    cout<<"After Merge:-"<<endl;
    for(int k=0 ; k<5 ; k++){
          arr_3[k] = arr_1[k];
 }

    for(int l=6 ; l<10 ; l++){
          arr_3[l] = arr_2[k];
}

 
    
}