// 4.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

int main()
{

	using namespace std;

	string imie,nazwisko;
	int ocena, lata;

	cout << "Jak masz na imie? " << endl;
	getline(cin, imie);

	cout << "Jak masz na nazwisko? " << endl;
	getline(cin, nazwisko);

	cout << "Na jaka ocene zaslugujesz? " << endl;
	cin >> ocena;

	cout << "Ile masz lat? " << endl;
	cin >> lata;

	ocena = ocena - 1;

	cout << "Pelne imie i nazwisko: " << imie <<", "<< nazwisko << endl;
	cout << "Ocena: " << ocena << endl;
	cout << "Wiek: " << lata << endl;

	cin.get();
	cin.get();

    return 0;
}

