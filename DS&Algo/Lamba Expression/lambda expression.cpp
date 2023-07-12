#include <iostream>
using namespace std;

/*
    Capture Claue []
    Tells what variables are captured from outside scope into the scope of lamba function.
    If it is empty, then lambda function can make use of only the variables which ar in its scope.
    If[=], then values are passed by value and these are passed implicitelzy as const. Hence we cannot modify those variables in lambda expr.
    If[&], then values are passed by reference. Hence modifiable.

*/
template<typename F>
void test_function(const F& handler)
{
    cout<<handler(10,5);
}
int main()
{
    enum {numtypes=5,name=10};
    cout<<numtypes;
    test_function([&](int a,int b){
         return a*b;
    });
    return 0;
}
