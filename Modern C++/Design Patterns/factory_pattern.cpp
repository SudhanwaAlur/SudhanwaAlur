#include<iostream>
#include<string>
#include<memory>
#include<functional>

class Shapes{
public:
	virtual std::string getName(){
		return "No Shape yet";
		
	}; 
};
class Circle:public Shapes{
public:
	std::string getName(){
		return "Circle";
	}
};
class Square:public Shapes{
public:
	std::string getName(){
		return "Square";
	}
};

enum class Type{
	CIRCLE,
	SQUARE
};
class Factory{
public:
	
	std::unique_ptr<Shapes> createShape(Type t){
		switch(t)
		{
			case Type::CIRCLE: 
				return (std::unique_ptr<Shapes>(new Circle()));
			
			case Type::SQUARE:
				return (std::move(std::unique_ptr<Shapes>(new Square())));
				
		}
		return nullptr;
	}
	
};
int main(){
	
	auto customDeleter=[](Shapes* shape)
	{
		std::cout<<"Shape deleted";
		delete shape;
	};
	Factory factory;
	std::unique_ptr<Shapes,decltype(customDeleter)> newShape(factory.createShape(Type::CIRCLE).release(),customDeleter);
		
	if(newShape)
	{
		std::cout<<newShape->getName();
	}
	return 0;
}