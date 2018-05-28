// 4.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>

int main()
{

	using namespace std;

	const int size = 20;

	cout << "Podaj imie: " << endl;
	char imie[size];
	cin.getline(imie, size);

	cout << "Podaj pelne nazwisko: " << endl;
	char nazwisko[size];
		cin.getline(nazwisko, size);

	char calosc[2 * size - 1];
	strcpy_s(calosc, nazwisko);
	strcat_s(calosc, ", ");
	strcat_s(calosc, imie);

	cout << "Oto informacje zestawione w jeden napis: " << calosc;

	cin.get();
	cin.get();

	return 0;
}