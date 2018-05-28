// 2.5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	using namespace std;

	long long ludnosc, ludnosc_polski;

	cout << " Czesc podaj liczbe ludnosci swiata: ";
	cin >> ludnosc;

	cout << " teraz podaj liczbe ludnosci Polski: ";
	cin >> ludnosc_polski;

			long double procent = long double (ludnosc_polski * 100) / long double (ludnosc); // wlasciwa kalkulacja 

	cout << " Populacja Polski stanowi " << procent << "% populacji swiata";

	cin.get();
	cin.get();

	return 0;
}

