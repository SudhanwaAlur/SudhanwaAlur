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
	//get the rightmost set Bit
	int rightMostSetBit=result & (~(result-1));
	int res1=0;
	int res2=0;
	for(int i=0;i<N;i++)
	{
		if(arr[i] & rightMostSetBit)
		res1=res1^arr[i];
		else
		res2=res2^arr[i];
	}
	cout<<"Two odd occuring digits are : "<<res1<<"  "<< res2;
}
