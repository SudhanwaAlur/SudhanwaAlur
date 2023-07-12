#include <iostream>
using namespace std;
int main()
{
int a, b, c;        // int data type for simple math
a = 9;
c = a + 1 + 1 * 0;
b = c++;
cout<<a<<'\t'<<c<<'\t'<<b;
return 0;           // return main int as Exit Status 0 (success)
} 
