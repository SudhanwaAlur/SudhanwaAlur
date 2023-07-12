/* Prefer deleted functions to private undefined ones
C++ 98 approach for preventing use of the functions is to declare them private and not define them. 
So that the clients will not have access to those functions and hence will not be able to use those functions.

But, the friend functions and other memeber functions can call those functions even if they are under private access specifier and thereby linking will fail due to missigng function
definitions.

In order to resolve this issue, "delete" can be used at the end of the functions which makes it evident for the compilers that, these functions cannot be called and results in compiler
errors on doing so.
by default deleted functions are declared public and not private. The reason being, when the client code tries to access deleted fucntions, C++ first checks the accessibility. SO if it
is private, then it will first complain about the "cannot access" erros but rather, the intended error message here is that the function cannot be accessed since it is decalared "deleted"..
This will result in better error messages to the user which are more intuitive to the actual scenario.
*/

/* Below is the usage of the "delete" 
Here the compiler will throw errors  for all other expression passing char,floar,bool.
*/
#include<iostream>
#include<memory>
using namespace std;
bool isLucky(int n){
	return true;
}
bool isLucky(char n)=delete;
bool isLucky(float n)=delete;
bool isLucky(bool n)=delete;
int main()
{
	if(isLucky('a'))
	{
		std::cout<<"Char\n";
	}
	if(isLucky(10)){
		std::cout<<"int\n";
	}
	if(isLucky(false)){
		std::cout<<"bool\n";
	}
	if(isLucky(5.5)){
		std::cout<<"foat\n";
	}
}