#include<iostream>

using namespace std;

int main()
{
	int a=10;
	float b=2.5;
	cout<<a<<'\t'<<b<<endl;
	b=static_cast<int>(b);
	cout<<a<<'\t'<<b<<endl;
}
