#include <iostream>
#include <memory>
using namespace std;

class foo
{
	int x;
	public:
	foo(int x)
	{
		x=x;
	}
	~foo()
	{
		cout<<"destructor called\n";
	}
};
int main()
{
	foo *f = new foo(10);
	delete f;
	unique_ptr<foo> p(new foo(10));
	
}
