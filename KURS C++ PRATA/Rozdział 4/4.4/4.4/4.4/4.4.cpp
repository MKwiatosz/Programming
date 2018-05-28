// 4.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

int main()
{

	using namespace std;

	string imie, nazwisko,calosc;

	cout << "Podaj imie: " << endl;
	getline(cin, imie);

	cout << "Podaj nazwisko: " << endl;
	getline(cin, nazwisko);

		calosc = imie +", " + nazwisko;

	cout << "Oto informacje zestawione w jeden napis: " << calosc << endl;

	cin.get();
	cin.get();

    return 0;
}

