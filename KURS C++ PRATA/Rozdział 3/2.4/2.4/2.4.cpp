// 2.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	using namespace std;

	const int MIN = 60;
	const int GODZ = 3600;
	const int DZIEN = 3600 * 24;


	long long sekundy;
		cout << "Podaj liczbe sekund: ";
		cin >> sekundy;

			int dni = sekundy / DZIEN;		// ile dni miesci sie w tych sekundach 
			sekundy = sekundy % DZIEN;		// ile dni miesci sie w sekundach tyle ze zwracamy pozostala ilosc sekund

			int godziny = sekundy / GODZ;
			sekundy = sekundy % GODZ;

			int minuty = sekundy / MIN;
			sekundy = sekundy % MIN;

	
	cout << sekundy << " sekund to: " << dni << " dni, " << godziny << " godzin, " << minuty << " minut, " << sekundy << " sekund" << endl;

	cin.get();
	cin.get();

	return 0;
}

