// 2.7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{

	using namespace std;

		const double USkm100 = 62.14;
		const double GallLT = 3.875;

		cout << "Podaj zuzycie benzyny w L/100km: ";
		double LtrKM;
		cin >> LtrKM;

		double USGAL = LtrKM / GallLT;
		double USMPG = USkm100 / USGAL;

		cout << "Odpowiednik w milach na galon wynosi: " << USMPG << endl;

	
	cin.get();
	cin.get();

    return 0;
}

