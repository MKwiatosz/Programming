// 1.5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int zamiana(int celcjusz)
{
	int fahrenheit;
	return fahrenheit = 1.8 * celcjusz + 32;
}

int main()
{
	int celcjusz;

	cout << "Podaj temperature w stopniach celcjusza: \n";
	cin >> celcjusz;
	cout << celcjusz << " stopnie celcjusza to " << zamiana(celcjusz) << " stopnie farhenheita\n";

	cin.get();
	cin.get();

    return 0;
}



