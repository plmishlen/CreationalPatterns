#include<iostream>
#include<string>
using namespace std;

class Computer
{
	std::string type;
	std::string cpu;
	size_t ram;
	std::string disk;
	std::string gpu;
public:
	void set_type(const std::string& type)
	{
		this->type = type;
	}
	void set_cpu(const std::string& cpu)
	{
		this->cpu = cpu;
	}
	void set_ram(size_t ram)
	{
		this->ram=ram;
	}
	void set_disk(const std::string& disk)
	{
		this->disk = disk;
	}
	void set_gpu(const std::string& gpu)
	{
		this->gpu = gpu;
	}
	void info()const
	{
		cout << type << endl;
		cout << cpu << endl;
		cout << ram << endl;
		cout << disk << endl;
		cout << gpu << endl;
	}
};
class ComputerBuilder
{
protected:
	Computer* computer;
public:
	ComputerBuilder()
	{
		this->computer = new Computer;
	}
	virtual ~ComputerBuilder()
	{

	}
	Computer* getComputer()
	{
		return computer;
	}
	void createNewComputer()
	{
		computer = new Computer;
	}
	virtual void setTYPE() = 0;
	virtual void setCPU()  = 0;
	virtual void setRAM()  = 0;
	virtual void setDISK() = 0;
	virtual void setGPU()  = 0;
};

class CheapComputerBuilder :public ComputerBuilder
{
public:
	~CheapComputerBuilder()
	{

	}
	void setTYPE()override
	{
		computer->set_type("Ѕюджетный компьютер");
	}
	void setCPU()override
	{
		computer->set_cpu("Pentium");
	}
	void setRAM()override
	{
		computer->set_ram(4);
	}
	void setDISK()override
	{
		computer->set_disk("Toshiba HDD 500GB");
	}
	void setGPU()override
	{
		computer->set_gpu("Integrated GPU");
	}
};

class OfficeComputerBuilder :public ComputerBuilder
{
public:
	~OfficeComputerBuilder()
	{

	}
	void setTYPE()
	{
		computer->set_type("ќфисный компьютер");
	}
	void setCPU()
	{
		computer->set_cpu("Core i3");
	}
	void setRAM()
	{
		computer->set_ram(8);
	}
	void setDISK()
	{
		computer->set_disk("Kingston SSD 240 GB");
	}
	void setGPU()
	{
		computer->set_gpu("Integrated GPU");
	}
};
class GameComputerBuilder :public ComputerBuilder
{
public:
	~GameComputerBuilder()
	{

	}
	void setTYPE()
	{
		computer->set_type("»гровой компьютер");
	}
	void setCPU()
	{
		computer->set_cpu("Core i7");
	}
	void setRAM()
	{
		computer->set_ram(16);
	}
	void setDISK()
	{
		computer->set_disk("Samsung SSD 500 GB");
	}
	void setGPU()
	{
		computer->set_gpu("nVidia GetForce 2050 Ti");
	}
};

class Assembler
{
	ComputerBuilder* computer;
public:
	void assamblyComputer(ComputerBuilder* builder)
	{
		this->computer = builder;
		this->computer = computer;
		this->computer->setTYPE();
		this->computer->setCPU();
		this->computer->setRAM();
		this->computer->setDISK();
		this->computer->setGPU();
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	CheapComputerBuilder cheap_comp;
	OfficeComputerBuilder office;
	GameComputerBuilder for_crysis;

	Assembler sysadmin;
	sysadmin.assamblyComputer(&cheap_comp);
	cheap_comp.getComputer()->info();
	
	sysadmin.assamblyComputer(&office);
	office.getComputer()->info();

	sysadmin.assamblyComputer(&for_crysis);
	for_crysis.getComputer()->info();

}