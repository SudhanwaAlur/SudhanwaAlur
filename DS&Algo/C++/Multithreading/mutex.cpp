#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
int sum=0;
std::mutex m;
void add()
{
	for(int i=1;i<=10;i++)
	{
		if(m.try_lock())
			sum=sum+i;
		m.unlock();	
	}
}
int main()
{
	thread t1(add);
	thread t2(add);
	
	t1.join();
	t2.join();
	
	cout<<"Sum is: "<<sum;
	return 0;
}
