#include <iostream>
using namespace std;

int  main()
{
	int a=10;
	const int* p=&a;
	cout<<a;
	int *d1=const_cast<int*>(p);
	*d1=5;
	cout<<*d1<<a;
}
