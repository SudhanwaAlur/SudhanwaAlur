#include<iostream>
using namespace std;
main()
{
int arr[10]={1,-1,2,3,-10,5,-50,9,90,-150};
int pivot=arr[0];
int temp;
if(pivot>0)
{
	for(int i=0;i<10;i++)
	{
		if(arr[i]<pivot)
		{
			temp=arr[0];
			arr[0]=arr[i];
			arr[i]=temp;
		}
	}
}
else
{
		for(int i=0;i<10;i++)
	{
		if(arr[i]>pivot)
		{
			temp=arr[0];
			arr[0]=arr[i];
			arr[i]=temp;
		}
	}
}
for(int j=0;j<10;j++)
{
	cout<<arr[j];
}
}

