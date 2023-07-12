/* Prefer Task based programming to thread 
Lets consider we have a function "doAsyncWork()" which needs to be run asynchronously.
There are two ways in which this can be done.
1) std::thread t(doAsyncWork)
2) auto fut = std::async(doAsyncWork)

*/

#include<iostream>
#include<memory>
#include<future>
#include<ctime>
#include<thread>
using namespace std;


int func(int a)
{
	return a+5;
}
template<typename F, typename T>
std::future<int> reallyAsync(F&& f, T&& params)
{
	return std::async(std::launch::async,f,params);
}
int doAsyncWork(int num){
	
	int count=0;
	for(int i=0;i<num;i++)
		count++;
	std::this_thread::sleep_for(5000ms);
	return count+7;
}
int main()
{
	auto fut=std::async(std::launch::async,doAsyncWork,100000);
	cout<<"Waiting for the completion of doAsyncWork..\n";
	cout<<fut.get()<<"\n";
	int b=10;
	std::future<int> futRA=reallyAsync(func,b);
	cout<<"Reallt Async "<<futRA.get()<<"\n";
	return 0;
}