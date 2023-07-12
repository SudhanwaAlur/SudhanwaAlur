#include<iostream>
/* This is a Binary serach algorithm where the following steps are followed.
1: Sort the given array. For sorting , I am using bubble sort for simplicity. 
2: Find the mid point.
3: if(arr[mid]==element) return mid;
   else if (arr[mid] > element) mid =mid -1;
   else mid = mid +1;
*/
using namespace std;
void sort_array(int *arr,int length)
{
    cout <<"length:"<<length<<endl;
    for(int i=0;i<length-1;i++)
    {
        for(int j=0;j<length-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
}
int search_array(int *arr, int x, int length, int low, int high)
{
        if(low>high)
        return -1;
        int mid = (low+high)/2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid]>x)
            return search_array(arr,x,length,low,mid-1);
        else   
            return search_array(arr,x,length,mid+1,high);
}
int main()
{
    int arr[] = {2,1,5,7,100,4};
    int N = sizeof(arr) / sizeof(arr[0]);
    sort_array(arr,N);
    for(int i=0;i<N;i++)
    {
        cout<<arr[i];
    }
    int element =200;
    int result = search_array(arr,element,N,0,N-1);
    cout << "Element is at position :"<<result<<endl;
    return 0;
}