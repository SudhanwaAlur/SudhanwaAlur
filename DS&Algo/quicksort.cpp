#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void swap(int &a, int &b) 
{ 
    int t = a; 
    a = b; 
    b = t; 
} 
int partition(int *arr,int start,int end)
{
	int pivot=arr[end];
	int pIndex=start;
	
	for(int i=start;i<end;i++)
	{
		if(arr[i]<=pivot)
		{
			//swap(arr[pIndex],arr[i]);
			int temp=arr[pIndex];
			arr[pIndex]=arr[i];
			arr[i]=temp;
			pIndex=pIndex+1;
			
		}
	}
	swap(arr[pIndex],arr[end]);
	return pIndex;
}
void quickSort(int *arr,int start,int end)
{
	if(start<end)
	{
	int pIndex=partition(arr,start,end);
	quickSort(arr,start,pIndex-1);
	quickSort(arr,pIndex+1,end);
	for(int i=0;i<8;i++)
	{
		cout<<arr[i];
	}
	cout<<"\n";
}
}
int main()
{
	int arr[]={7,2,1,6,8,5,3,4};
	quickSort(arr,0,7);
	for(int i=0;i<8;i++)
	{
		cout<<arr[i];
	}
}
