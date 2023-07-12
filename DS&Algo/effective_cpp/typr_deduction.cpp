#include<iostream>
/*Case:1
param type is a reference or pointer but not a universal reference
1. If expre's type is a reference, ignore the reference
2. Then pattern match expr's type again paramtype to determine T

Case:2
param type is a universal reference
1. If expr is an lvalue, both T and paramType are dduced to be lvalue references.
2. If expr is  rvalue, the Case 1 rules apply.
*/
template<typename T>
void f_ref_case1(T& param)
{
    std::cout<<"f_ref_case1::The parameter is: "<<param<<"\n";
}
template<typename T>
void f_pointer_case1(T* param)
{
    std::cout<<"f_pointer_case1::The parameter is: "<<*param<<"\n";
}
template<typename T>
void f_ref_case2(T&& param)
{
    std::cout<<"f_ref_case2:: The parameter is:"<<param<<"\n";
}
int main()
{
    //case 1
    int x=10;
    f_ref_case1(x);    // T is int, param's type is int&
    const int cx=x;
    f_ref_case1(cx);  // T is const int, param's type is const int&
    const int &rx=x;
    f_ref_case1(rx); // T is const int, param's type is const int&

    int y=50;
    f_pointer_case1(&y);
    const int* cy=&y;
    f_pointer_case1(cy);


    //case 2
    int z=15;
    f_ref_case2(15); //27 is rvalue, so T is int, // paramtype is int&&

    const int cz=z;
    f_ref_case2(cz); // T is int& and paramtype is int& because cz is lvalue

    const int& rz=z;
    f_ref_case2(rz); // T is int& and paramtype is int& because rz is lvalue
    return 0;
}