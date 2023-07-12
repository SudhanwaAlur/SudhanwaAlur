/* Prefer scoped enums to unscoped enums 
Declaring a name inside curly braces in unscoped braces does not mean that the scope of the names is limited to the braces. However, in case of enums, the scope of the names take the scope
of the enum itself. In case the enum is declared in the global scope, then the scope of the names declared in the enums would be global. This means that no other variables or code entieties
have the same name.
*/
#include<iostream>
#include<memory>

enum Color{
	white,
	red,
	green
};

enum class vehicle{
	car,
	bike,
	truck
};
//auto white=false; This will lead to an error. Here the name white is redeclared but with a different entity
auto car=false; // No error!!, because now the enum has a scope specific to enum class vehicle

/* Scoped enums are more strongly type. Unscoped enums are implicitely converted to integral types*/ 

/* Enums can also be explicitely typed. This means the underlying type of the enum can be explicitely mentioned during the declaration of the enums */

enum class flowers: std::uint32_t{
	rose,
	jasmine,
	cactus
};
int main()
{
	Color c=white;
	if(c<10)
	{
		std::cout<<"Implicit conversion of white to integral type\n";
	}
	vehicle v=vehicle::car;
	if(static_cast<int>(v)<10){   // If the static casting is not used, then operand types are 'vehicle' and 'int'. Hence there is no  match for operand< error is thrown
		std::cout<<"conversion possible due to casting\n";
	}
	return 0;
}