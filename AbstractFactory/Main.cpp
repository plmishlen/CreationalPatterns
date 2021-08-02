#include"stdafx.h"
#include"Client.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	SportFactory sf;
	TruckFactory tf;
	Client client(&sf);
	client.info();
	cout << "--------------------------------------" << endl;
	client.setFactory(&tf);
	client.info();
	cout << "--------------------------------------" << endl;
	Car* car = client.assembly(&sf);
	car->info();
	cout << "--------------------------------------" << endl;
	Car* truck = client.assembly(&tf);
	truck->info();


}