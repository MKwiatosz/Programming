// 2.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	using namespace std;

	int stopnie, minuty, sekundy;

	cout << "Podaj dlugosc w stopniach, minutach i sekundach: " << endl;
	
	cout << " Najpierw podaj stopnie: ";
	cin >> stopnie;
	cout << " Nastepnie podaj minuty: ";
	cin >> minuty;
	cout << " Na koniec podaj sekundy: ";
	cin >> sekundy;


	double razem = double(stopnie) + (double(minuty) + double(sekundy) / 60) / 60;

	cout <<"\n" << stopnie << " stopni, " << minuty << " minuty, " << sekundy << " sekund = " << razem << " stopni" << endl;


	cin.get();
	cin.get();
	return 0;
}

