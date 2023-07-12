#include<iostream>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int arr[N];
	for(int i=0;i<N;i++)
	{
		cin>>arr[i];
	}
	int result=0;
	for(int j=0;j<N;j++)
	{
		result=result ^ arr[j];
	}
	cout<<result;
	
	/*to find the missing number in a sequence ex: {1,4,3,5} here 2 is missing.
	In order to find the missing number ,  
	result=1^4^3^5;
	result = result ^ 1 ^ 2 ^ 3 ^ 4 ^ 5
	Now result will be 2;
}
