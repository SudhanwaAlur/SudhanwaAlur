#include<iostream>
#define NUMELEMENTS 7
using namespace std;
void merge(int arr[],int l,int m,int r)
{
	int temp[NUMELEMENTS];
	int i=l;
	int j=m+1;
	int k=l;
	while(i<=m && j<=r)
	{
		if(arr[i]>=arr[j])
		{
			temp[k]=arr[j];
			j++;k++;
		}
		else
		{
			temp[k]=arr[i];
			i++;k++;	
		}
	}
	while(i<=m)
	{
		temp[k]=arr[i];
		i++;k++;
	}
	while(j<=r)
	{
		temp[k]=arr[j];
		j++;k++;
	}
	for(int p=l;p<=r;p++)
	{
		arr[p]=temp[p];
		//cout<<arr[p]<<" ";
	}
	cout<<"\n";
}
void mergeSort(int arr[],int l,int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}
int main()
{
	int arr[NUMELEMENTS];
	for(int i=0;i<NUMELEMENTS;i++)
	{
		cin>>arr[i];
	}
	mergeSort(arr,0,NUMELEMENTS-1);
	for(int i=0;i<NUMELEMENTS;i++)
	{
		cout<<arr[i]<<" ";
	}
	
	return 0;
}
