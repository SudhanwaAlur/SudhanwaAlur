#include<stdio.h>
main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	int temp;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Before\n\n");
	for(int j=0;j<n/2;j++)
	{
		temp=arr[j];
		arr[j]=arr[n-1-j];
		arr[n-1-j]=temp;	
	}
	for(int k=0;k<n;k++)
	{
		printf("%d\n",arr[k]);
	}
}
