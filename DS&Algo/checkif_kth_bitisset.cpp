#include<iostream>
using namespace std;
void usingRightShift(int N, int K)
{
	if((N>>(K-1)) & 1)
	cout<<"YES";
	else
	cout<<"NO";
}
void usingLeftShift(int N , int K)
{
	if(N & (1<<(K-1)))
	cout<<"Yes";
	else
	cout<<"No";
}
int main()
{
	int N;
	cin>>N;
	int K;
	cin>>K;
	usingLeftShift(N,K);
	usingRightShift(N,K);
}
