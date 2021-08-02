#pragma once
#include"Factory.h"
#include"Car.h"

class Client
{
	A_Factory* factory;
public:
	Client(A_Factory* fact) : factory(fact) {}

	void setFactory(A_Factory* fact)
	{
		this->factory = fact;
	}
	void info()const
	{
		Engine* engine = factory->createEngine();
		Tank* tank = factory->createTank();
		engine->info();
		tank->info();
		delete engine;
		delete tank;
	}
	Car* assembly(A_Factory* fact)
	{
		return new Car(factory->createEngine(), factory->createTank());
	}

};
