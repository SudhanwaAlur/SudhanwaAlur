#include <iostream>
using namespace std;
template<typename T>
class Base
{
	T *data;
	public:
	Base(T *x)
	{
		data=x;
	}
	~Base()
	{
		delete data;
		cout<<"destructor called\n";
	}
};
int main()
{
	int *p=new int();
	Base<int> bp(p);
}
