#include<iostream>
#include<string>
#include<time.h>
#include<list>
using namespace std;

class CPU
{
protected:
	std::string model;
	double frequency;
	unsigned int number_of_cores;
	unsigned int l3cache;
	std::string socket;
	bool hyper_threading;
public:
	CPU(const std::string& model, double frequency, unsigned int number_of_cores,
		unsigned int l3cache, std::string socket, bool hyper_threading)
	{
		this->model = model;
		this->frequency = frequency;
		this->number_of_cores = number_of_cores;
		this->l3cache = l3cache;
		this->socket = socket;
		this->hyper_threading = hyper_threading;
		cout << "CPUConstructor: \t" << this << endl;
	}
	virtual ~CPU()
	{
		cout << "CPUDestructor: \t" << this << endl;
	}

	virtual void info()const
	{
		cout << model
			<< "\tF = " << frequency << " GHz, "
			<< number_of_cores << " cores, "
			<< l3cache << " MB L3cache "
			<< " Socket: " << socket;
		if (hyper_threading) cout << " HyperThreading";
		cout << endl;
	}
	virtual const std::string& get_model()const = 0;	//����� ����������� �����, ������ ������ ����� �����������
};

class Core_i3 :public CPU
{
public:
	Core_i3() :CPU("Core-i3 2120", 2.5, 2, 3, "LGA-1155", true) {}
	~Core_i3() {}
	const std::string& get_model()const
	{
		return this->model;
	}
};

class Core_i5 :public CPU
{
public:
	Core_i5():CPU("Core-i5 2400", 3.4, 4, 4, "LGA-1155", false) {}
	~Core_i5() {}
	const std::string& get_model()const
	{
		return this->model;
	}
};
class Core_i7 :public CPU
{
public:
	Core_i7() :CPU("Core-i7 2700K", 3.8, 4, 8, "LGA-1155", true) {}
	~Core_i7() {}
	const std::string& get_model()const
	{
		return this->model;
	}
};
class Core_i7EE :public CPU
{
public:
	Core_i7EE():CPU("Core-i7EE ExtremeEdition 2900K", 4.2, 6, 12, "LGA-2011", true){}
	~Core_i7EE(){}
	const std::string& get_model()const
	{
		return this->model;
	}
};

//#define FACTORY_AS_GLOBAL_FUNCTION_WITH_ENUM

#ifdef FACTORY_AS_GLOBAL_FUNCTION_WITH_ENUM
enum CPUtype
{
	Core_i3, Core_i5, Core_i7, Core_i7EE
};

CPU* CPUfactory(CPUtype type)
{
	switch (type)
	{
	case Core_i3: return new class Core_i3();
	case Core_i5: return new class Core_i5();
	case Core_i7: return new class Core_i7();
	case Core_i7EE: return new class Core_i7EE;
	default: return nullptr;
	}
}
#endif // FACTORY_AS_GLOBAL_FUNCTION_WITH_ENUM

class CPUfactory
{
public:
	enum CPUtype
	{
		Core_i3, Core_i5, Core_i7, Core_i7EE
	};
	static CPU* CreateCPU(CPUtype type)		//Factory method
	{
		switch (type)
		{
		case Core_i3: return new class Core_i3();
		case Core_i5: return new class Core_i5();
		case Core_i7: return new class Core_i7();
		case Core_i7EE: return new class Core_i7EE;
		default: return nullptr;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	
#ifdef FACTORY_AS_GLOBAL_FUNCTION_WITH_ENUM
	//class Core_i3 ci3;
	//ci3.info();
	CPU* my_cpu = CPUfactory(Core_i7);
	my_cpu->info();
	cout << sizeof(CPUtype) << endl;
	int n;
	cout << "������� ���������� �������: "; cin >> n;
	CPU** _cpu = new CPU * [n];
	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{
		_cpu[i] = CPUfactory(CPUtype(rand() % 3));
	}
	for (int i = 0; i < n; i++)
	{
		_cpu[i]->info();
	}

	delete[] _cpu;
#endif // FACTORY_AS_GLOBAL_FUNCTION_WITH_ENUM

	CPU* my_cpu = CPUfactory::CreateCPU(CPUfactory::Core_i7EE);
	cout << my_cpu->get_model() << endl;
	my_cpu->info();

	int n;
	cout << "������� ���������� �������: "; cin >> n;
	std::list<CPU*> _cpu;
	for (int i = 0; i < n; i++)
	{
		_cpu.push_back(CPUfactory::CreateCPU(CPUfactory::CPUtype(rand() % 4)));
	}
	for (std::list<CPU*>::iterator it = _cpu.begin(); it != _cpu.end(); it++)
	{
		(*it)->info();
	}
	while (_cpu.size())
	{
		delete _cpu.back();
		_cpu.pop_back();
	}

}