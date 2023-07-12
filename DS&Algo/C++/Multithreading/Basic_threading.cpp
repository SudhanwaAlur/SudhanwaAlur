#include<iostream>
#include<thread>
using namespace std;
typedef unsigned long long ull;
ull evenSum=0;
ull oddSum=0;
void even(ull start, ull end)
{
	for(ull i=start;i<=end;i++)
	{
		if((i & 1)== 0)
		{
			evenSum=evenSum+i;
		}
	}
}
void odd(ull start, ull end)
{
	for(ull i=start;i<=end;i++)
	{
		if((i & 1)== 1)
		{
			oddSum=oddSum+i;
		}
	}
}
int main()
{
	ull start=1;
	ull end=1900000000;
	thread t1(even,start,end);
	thread t2(odd,start,end);
	t1.join();
	t2.join();
	cout<<"Even Sum is: "<<evenSum<<"\n";
	cout<<"Odd Sum is: "<<oddSum;
	return 0;
}
