/* Virtual function implementation in derived classes override the implementations of their base class counterparts*/

// Normal Impplementation
#include<iostream>
#include<memory>
using namespace std;
class Base_n{
	public:
		Base_n(){}
		virtual void doWork(){
		}
		~Base_n(){
		}
};
class Derv_n: public Base_n{
	public:
		Derv_n(){
		}
		void doWork(){
		}
		~Derv_n(){
		}
};
/* For overriding to occur, several requirements must be met.

1: Base Class function must be virtual
2: The Base and Derviced Class functions must be identical
3: The parameters and constness must be identical
4: Return types must be compatible
5: Function reference qualifiers hsould be identical -> ex: void doWork() & -> lvalue references , void doWork() && -> rvalue references.
	Here factory function always returns rvalue and normal object decalarions lvalue.
*/

/* Advantages of using the override

If any of the above mentioned points are not met while overriding functions, then if "override" is not used, Normally compilers will not be able to detect the errors and find the the functions 
declared in the derived class are not overriding the Base class functions and compilation will be successfull even though the desired result is not met. 

If "override" is written in frot of functions overriding the Base class functions, then even though if the functions are not following the overriding conventions , then the compiler
this time will complain about the errors and compilation will not bve successfull.

*/

/* Below is the usecase which describes the problem. Even the the functions in the derived class are not overriding the Base class implementation as intented the compilation is successful*/
class Base_prblm{
	public:
		Base_prblm(){
		}
		virtual void doWork() const{
		}
		virtual void doWork1(int x){
		}
		~Base_prblm(){
		}
	
};
class Derv_prblm:public Base_prblm{
	public:
		Derv_prblm(){
		}
		void doWork(){
		}
		void doWork1(){
		}
		~Derv_prblm(){
		}
};
/* Below implementation shows how thw problems descrbed above can be resolved using "override"
 For the below code, compiler will throw errors saying "'void Derv_f::doWork1()' marked 'override', but does not override"
 Similarly for doWork(), if the identicals are taken care then these errors can be resolved.
*/
class Base_f{
	public:
		Base_f(){
		}
		virtual void doWork() const{
		}
		virtual void doWork1(int x){
		}
		~Base_f(){
		}
};
class Derv_f:public Base_f{
	public:
		Derv_f(){
		}
		void doWork() override{
		}
		void doWork1() override{
		}
		~Derv_f(){
		}
};
int main(){
	std::unique_ptr<Base_n> upb=std::make_unique<Derv_n>();
	std::unique_ptr<Base_prblm> upb1=std::make_unique<Derv_prblm>();
	std::unique_ptr<Base_f> upb2=std::make_unique<Derv_f>();
	return 0;
}