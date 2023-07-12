#include<iostream>
using namespace std;
class A{
	int a;
	int b;
	public:
	A(){
		a=10;
		b=10;
	}
	~A(){
		
	}
	int getval()
	{
		return a;
	}
}a1;
main(){
	int *ptr=10;
	
	A *a1=NULL;
	a1=new A();
	cout<<a1;
	delete(a1);
//	a1=NULL;
	cout<<(a1);
	
}
