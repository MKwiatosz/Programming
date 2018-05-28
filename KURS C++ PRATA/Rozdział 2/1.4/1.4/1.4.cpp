// 1.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int zamiana(int wiek)
{
	int miesiace;
	return miesiace = wiek * 12;
}

int main()
{
	int wiek;

	cout << " Podaj swoj wiek\n";
	cin >> wiek;
	cout << " Twoj wiek w miesiacach to:" << zamiana(wiek) << endl;

	cin.get();
	cin.get();
    return 0;
}

