#pragma once
#include"stdafx.h"

class Tank
{
protected:
	std::string type;
	unsigned int volume;
public:
	virtual const std::string& get_type()const = 0;	//Pure virtual function - ������ ������ ����� �����������
	void info()const
	{
		cout << type << ", volume " << volume << " litres\t" << endl;
	}
};
class SportTank :public Tank
{
public:
	SportTank()
	{
		this->type = "SportTank";
		this->volume = 60;
	}
	~SportTank() {}
	const std::string& get_type() const
	{
		return this->type;
	}
};
class TruckTank :public Tank
{
public:
	TruckTank()
	{
		this->type = "TruckTank";
		this->volume = 200;
	}
	~TruckTank() {}
	const std::string& get_type() const
	{
		return this->type;
	}
};
