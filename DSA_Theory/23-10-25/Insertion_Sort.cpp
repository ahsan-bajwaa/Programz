#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int A[n];
	for(int i=0; i<=n-1; i++)
    {
		cin>>A[i];
	}
	for(int i=1; i<=n-1; i++)
    {
		int key=A[i];
		int j=i-1;
		while (A[j]>key && j>=0)
        {
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=key;
	}
	for(int i=0;i<=n-1;i++)
    {
		cout<<A[i]<<"  ";
	}
}