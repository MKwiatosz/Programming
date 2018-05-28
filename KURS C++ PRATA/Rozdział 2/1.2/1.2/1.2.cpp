// 1.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int zamiana(int mile)
{
	int metry;

	metry = mile * 1852;
	return metry;
}

int main()
{
	using namespace std;

	int mile;

	cout << "Podaj odleglos w milach morskich:" << endl;
	cin >> mile;
	cout << "Na metry to bedzie: " << zamiana(mile) <<" m"<< endl;


	cin.get();
	cin.get();

    return 0;

}



