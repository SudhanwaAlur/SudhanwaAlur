#include <iostream>
#include <string>
using namespace std;

class vehicle{
	public:
		virtual void washVehicle()=0;
};
class car: public vehicle
{
	public:
		car(){
		cout<<"Car is created\n";
		}
		void washVehicle(){
			cout<<"Car is washed\n";
		}
};
class bike: public vehicle
{
	public:
		bike(){
		cout<<"Bike is created\n";
		}
		void washVehicle(){
			cout<<"Bike is washed\n";
		}
};
class vehicleFactory
{
	public:
	vehicleFactory(){}
	static vehicle* getVehicle(string type)
	{
		vehicle *v;
		if(type=="bike")
		{
			//cout<<"bike";
			v = new bike();
		}
		else if(type=="car")
		{
			v= new car();	
		}
		else
		{
			cout<<"Provide a correct vehicle type please!\n";
			v=nullptr;
		}
		return v;	
	}	
};

class client : public vehicleFactory
{
	public:
	vehicle* getVehicleFromFactorry(string type)
	{
		return vehicleFactory::getVehicle(type);	
	}	
};

int main()
{
	client *c= new client();
	vehicle* vh;
	vh=c->getVehicleFromFactorry("bike");
	vh->washVehicle();
	vh=c->getVehicleFromFactorry("car");
	vh->washVehicle();
	vh=c->getVehicleFromFactorry("xyz");
	if(vh)
	vh->washVehicle();
	return 0;
}
