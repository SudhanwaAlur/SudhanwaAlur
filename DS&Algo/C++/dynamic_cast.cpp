#include <iostream>
using namespace std;
class Base{
	int a;
	protected:
		int x;
	public:
	Base()
	{
		a=10;
		x=5;
	}
	virtual void show()
	{
		cout<<"Hello! Base class here!\n";
	}
};
class Derived: public Base
{
	public:
		Derived(){}
		void show()
		{
			cout<<"Hello! Derived class here!\n";
			cout<<this->x;
		}
};
class Derived1: public Base
{
	public:
		Derived1(){}
		void show ()
		{
			cout<<"Hello! Derived 1 here!";
		}
};
int main()
{
	Base base;
	base.show();
	Base *bp;
	Derived dp;
	bp=dynamic_cast<Base*>(&dp);
	bp->show();
	Derived1 dp1;
	bp=dynamic_cast<Base*>(&dp1);
	bp->show();
	return 0;
}
