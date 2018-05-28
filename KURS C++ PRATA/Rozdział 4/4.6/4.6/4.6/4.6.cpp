// 4.6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

int main()
{

	using namespace std;

	struct batonik
	{
		string marka;
		float waga;
		int kalorie;
	};

	batonik jakis[3] =
	{
		{ "Mars",50,150 },
		{ "Snickers",100,200},
		{ "Twix",150,250},
	};

	cout << "Marka batonika 1 to: " << jakis[0].marka << endl;
	cout << "Marka batonika 1 to: " << jakis[0].waga << endl;
	cout << "Marka batonika 1 to: " << jakis[0].kalorie << endl;
	cout << endl;
	cout << "Marka batonika 2 to: " << jakis[1].marka << endl;
	cout << "Marka batonika 2 to: " << jakis[1].waga << endl;
	cout << "Marka batonika 2 to: " << jakis[1].kalorie << endl;
	cout << endl;
	cout << "Marka batonika 3 to: " << jakis[2].marka << endl;
	cout << "Marka batonika 3 to: " << jakis[2].waga << endl;
	cout << "Marka batonika 3 to: " << jakis[2].kalorie << endl;
	cin.get();
	cin.get();

    return 0;
}

