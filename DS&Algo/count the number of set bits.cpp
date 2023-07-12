#include<iostream>
using namespace std;
void brianKerningamsAlgorithm(int N)
{
	int result=0;
	while(N>0)
	{
		N=(N&(N-1));
		result++;
	}
	cout<<"By brianKerningamsAlgorithm"<<result<<"\n";
	/*Count set Bit logic of brian Kerningam Algorithm can be used
      to check if a given number is a power of 2 or not*/
	if(result==1)             
	{
		cout<<"Give number is power of 2";
	}
}
int main()
{
	int n;
	cin>>n;
	int N=n;
	int count=0;
	int res;
	while(N!=0)
	{
		res=N%2;
		if(res==1)
		count++;
		N=N>>1;
	}
	cout<<"By Naive Solution"<<count<<"\n";
	brianKerningamsAlgorithm(n);
	
	//For one line solution to check if the given Number is power of 2 or not.
	if((n & (n-1))==0)
	{
	
	cout<<"One Line Soln:Give number is power of 2";
    }
}
