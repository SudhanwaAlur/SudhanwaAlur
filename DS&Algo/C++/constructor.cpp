#include <iostream>
using namespace std;

class base
{
	int a,b;
	static base* bp;
	base()
	{	
	}
	public:
		void print()
		{
			cout<<"hello from base\n";	
		}
		static base* getInstance()
		{
			if(!bp)
			{
				bp=new base();
				cout<<"Object created\n";	
			}
			else
			cout<<"object already available\n";
			return bp;
		}	
};
base *base::bp = 0;
int main()
{
	//base b(4,5);
	base::getInstance();
base::getInstance();	
	return 0;
}
