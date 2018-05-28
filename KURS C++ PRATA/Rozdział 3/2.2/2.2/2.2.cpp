// 2.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int main()
{

	using namespace std;
		
	
		using namespace std;

		cout << "Podaj wzrost w stopach i calach: ";
		double stopy;
		cin >> stopy;

		cout << "Podaj wage w funtach: ";
		double funty;
		cin >> funty;

		const double cale = stopy * 12;
		const double metry = cale * 0.0254;
		const double kg = funty / 2.2;
		double bmi = kg / (metry * metry);

		cout << "Dla podanych wzrostu oraz wagi BMI wynosi: " << bmi << endl;

			cin.get();
			cin.get();

    return 0;
}

