// 1.7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void czas(int godziny, int minuty)
{
	 cout << "Czas: " << godziny << ":" << minuty;
}

int main()
{
	int godziny;
	int minuty;

	cout << " Podaj liczbe godzin: ";
	cin >> godziny;
	cout << " Podaj liczbe minut: ";
	cin >> minuty;

	czas(godziny, minuty);

	cin.get();
	cin.get();
    return 0;
}

