#include <iostream>
#include <cstring>
using namespace std;
class String{
	private:
		char* res;
		unsigned int len;
	public:
	String():res(NULL),len(0)
	{
		
	}
	String(const char* ch)
	{
		len=strlen(ch);
		res=new char[len+1];
		strcpy(res,ch);
	}
	String(const String& str)
	{
		len=str.len;
		res=new char[len+1];
		strcpy(res,str.res);	
	}
	String& operator=(const String& str)
	{
		if(this!=&str)
		{
			delete[] res;
			len=str.len;
			res=new char[len+1];
			strcpy(res,str.res);
		}
		return *this;
	}
	unsigned int length(){
		return len;
	}	
	
};
int main()
{
	String str1; //default constructor
	String str2="hello"; // parameterised constructor
	String str3=str2; // copy constructor
	//cout<<str3;
	str3=str2; //copy assignment operator. str3 calls the function with str2 as parameter.
	int len=str3.length();
	//std::cout<<str2; //overload <<
	//std::cin>>str1; //overload >>
	
	return 0;
}
