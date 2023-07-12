#include<stdio.h>
main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
	scanf("%d",&arr[i]);
	}
	int element;
	scanf("%d",&element);
	int min=arr[0];
	int max=arr[0];
	int temp;
	for(int j=0;j<n;j++)
	{
		min=j;
		for(int k=j+1;k<n;k++)
		{
			if(arr[k]<arr[min])
			{
				min=k;
			}
		}
		temp=arr[min];
		arr[min]=arr[j];
		arr[j]=temp;
	}
	printf("%d smallest element is %d : ",element,arr[element-1]);
	printf("%d largest element is %d : ",element,arr[n-element]);
}
