#include<iostream>
#include<string>
#include<vector>
class entity{

private:
	char *entityData;
	int value;
	std::string entityStr;
public:
	entity(){
		std::cout<<"default constructor\n";
	}
	entity(const char* str, int val, std::string s):entityStr(s){
		std::cout<<"Parameteriesed Constructor\n";
		entityData=new char[strlen(str)];
		value=val;
		memcpy(entityData, str,strlen(str));	
		
	}
	entity(entity obj){
		std::cout<<"Cpy by value";
		entityData=new char[strlen(obj.entityData)];
		memcpy(entityData, obj.entityData,strlen(obj.entityData));
		value=obj.value;
	}
	entity(const entity& obj){
		std::cout<<"Copy Constructor\n";
		entityData=new char[strlen(obj.entityData)];
		memcpy(entityData, obj.entityData,strlen(obj.entityData));
		value=obj.value;
	}
	entity& operator=(const entity& obj){
		std::cout<<"Copy Assignment Constructor\n";
		entityData=new char[strlen(obj.entityData)];
		memcpy(entityData, obj.entityData,strlen(obj.entityData));
		value=obj.value;
		return *this;
	}
	entity(entity&& obj){
		std::cout<<"Move constructor\n";
		entityData=obj.entityData;
		value=obj.value;
		obj.entityData=nullptr;
	}
	int getVal(){
		return value;
	}
};
int main()
{
	std::string temp="I am testing constructors";
	entity e1("Hello I am entity",1,temp);
	/*entity e2(e1);
	entity e3;
	e3=e1;
	
	entity e4
	*/
	entity e2(e1);
	std::vector<entity*> vec;
	vec.push_back(new entity("hello",1,"world"));
	return 0;
}