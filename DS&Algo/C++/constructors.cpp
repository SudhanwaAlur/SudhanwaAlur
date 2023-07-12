#include<iostream>
using namespace std;
class Test{
	private:
		int a,b;	
	public:
	Test(){
		a=0;
		b=0;
		cout<<"Default"<<a<<" "<<b<<"\n";
	}
	Test(int x, int y)
	{
		a=x;
		b=y;
		cout<<"Parameterised"<<a<<" "<<b<<"\n";
	}
	Test(const Test& t)
	{
		a=t.a;
		b=t.b;
		cout<<"Copy"<<a<<" "<<b<<"\n";
	}
	Test& operator=(const Test& t)
	{
		a=t.a;
		b=t.b;
		cout<<"copy assignment"<<a<<" "<<b<<"\n";
		return *this;
	}
	
};
int main()
{
	Test t1;   //default constructor;
	Test t2(1,2); // parameterised ocnstructor
	Test t3=t2;  // copy constructor
	t3=t2; //copy assignemnt operator.
	return 0;
}
