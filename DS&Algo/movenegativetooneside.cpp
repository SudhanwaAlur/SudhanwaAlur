#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class MNOS{
	public:
	void Mnegative(int a[],int n);
};

void MNOS::Mnegative(int a[],int n){
	int j=0;
	for(int i=0;i<n;i++){
		if(a[i]<0){
			if(i!=j){
				swap(a[i],a[j]);
			}
			j++;
		}
		
	}
	
}

main(){
	int n;
	MNOS obj;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	obj.Mnegative(arr,n);
	for(int j=0;j<n;j++){
		cout<<arr[j];
	}
}
