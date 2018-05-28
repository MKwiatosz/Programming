 2.1.cpp : Defines the entry point for the console application.


#include "stdafx.h"
include <iostream>

int zamianaNaCale(int wzrost)
{
	const double cal = 2.54;
	int cale;

	return cale = wzrost / cal;

}

int zamianaNaStopy(int wzrost)
{
	const double stopa = 30.48;
	int stopy;

	return stopy = wzrost / stopa;

}


int main()
{

	using namespace std;

	int wzrost;

	cout << "Podasz proszê swój wzrost" << endl;
	cin >> wzrost;

	cout << "Twoj wzrost w calach to: " <<  zamianaNaCale(wzrost) << endl;
	cout << "Twoj wzrost w stopach to: " <<  zamianaNaStopy(wzrost) << endl;

	cin.get();
	cin.get();
	return 0;
}

