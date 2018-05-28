// 2.6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> 


int main()
{
	using namespace std;

	int przejechane_km, zuzyte_litry, pozostale_litry;

		const double mila = 0.621371192;
		const double galon = 3.78541178;


	cout << "Podaj ile km przejechano: ";
	cin >> przejechane_km;

	cout << "Podaj rowniez ile litrow benzyny zostalo spaloncyh: ";
	cin >> zuzyte_litry;

	cout << " i ile zostalo: ";
	cin >> pozostale_litry;

	double na_mile = przejechane_km * mila;
	double na_galony = zuzyte_litry * galon;

	double galony_na_mile = na_galony / na_mile;

	cout << " Zuzyte paliwo w galonach/mile to: " << galony_na_mile;


	cin.get();
	cin.get();

    return 0;
}

