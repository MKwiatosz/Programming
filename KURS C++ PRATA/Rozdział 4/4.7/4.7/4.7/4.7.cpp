// 4.7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

int main()
{

	using namespace std;
    
	struct pizza  
	{
		string nazwa_firmy;
		int srednica;
		float waga;
	};

	pizza jakas;

	cout << " Podaj nazwe firmy: " << endl;
	getline(cin, jakas.nazwa_firmy);

	cout << " Podaj srednice: " << endl;
	cin >> jakas.srednica;

	cout << " Podaj wage: " << endl;
	cin >> jakas.waga;

	cout << "Nazwa firmy:" << jakas.nazwa_firmy << endl;
	cout << "Srednica:" << jakas.srednica << endl;
	cout << "Waga:" << jakas.waga << endl;

	cin.get();
	cin.get();

    return 0;
}

