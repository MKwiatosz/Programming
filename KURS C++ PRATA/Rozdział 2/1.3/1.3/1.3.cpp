// 1.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void entliczek(void)
{
	cout << "Entliczek pentliczek\n";
}

void czerwony(void)
{
	cout << "Czerwony stoliczek\n";
}

int main()
{
	entliczek();
	entliczek();
	czerwony();
	czerwony();

	cin.get();
	cin.get();
	return 0;
}

