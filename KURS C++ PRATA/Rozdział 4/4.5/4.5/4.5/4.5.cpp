// 4.5.cpp : Defines the entry point for the console application.
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
		double waga;
		int kalorie;
	};

	batonik snack = { "Mocha Munch",2.3,350 };

	cout << "Marka: " << snack.marka << endl;
	cout << "Waga: " << snack.waga << endl;
	cout << "Kalorie: " << snack.kalorie << endl;

	cin.get();
	cin.get();

    return 0;
}

