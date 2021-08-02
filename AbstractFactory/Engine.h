#pragma once
#include"stdafx.h"

class Engine
{
protected:
	unsigned int power;
	std::string type;
public:
	~Engine() {}
	virtual const std::string& get_type() const = 0;
	void info()const
	{
		cout << type << "Power: " << power << "HP" << endl;
	}
};
class SportEngine : public Engine
{
public:
	SportEngine()
	{
		this->power = 250;
		this->type = "SportEngine";
	}
	~SportEngine() {}
	const std::string& get_type()const
	{
		return this->type;
	}
};
class TruckEngine :public Engine
{
public:
	TruckEngine()
	{
		this->power = 500;
		this->type = "TruckEngine";
	}
	~TruckEngine() {}
	const std::string& get_type()const
	{
		return this->type;
	}
};
