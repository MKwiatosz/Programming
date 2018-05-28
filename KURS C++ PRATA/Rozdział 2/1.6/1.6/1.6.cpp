// 1.6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int zamiana(double swietlne)
{
	int astronomiczne;
	return astronomiczne = 63240 * swietlne;
}

int main()
{
	double swietlne;

	cout << "Podaj liczne lat swietlnych: \n";
	cin >> swietlne;
	
	cout << swietlne << " lat swietlnych = " << zamiana(swietlne) << " jednostek astronomicznych\n";

	cin.get();
	cin.get();
    return 0;
}

