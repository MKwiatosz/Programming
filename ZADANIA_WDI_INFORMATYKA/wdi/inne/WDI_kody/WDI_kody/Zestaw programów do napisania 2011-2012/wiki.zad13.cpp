#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;

/*Prosz� napisa� program, kt�ry wczytuje liczb� naturaln� i wyznacza sum� jej cyfr
*/

int sumaCyfr(int n)
{
int r;
int s=0;

if(n==0) return 0;
while(n>0)
{  
  r=n%10;
  s=s+r;
  n=n/10;
}
return s;
}

int main()
{
int liczba;

cout << "Podaj liczbe: ";
cin >> liczba;
cout << endl << "Suma cyft podanej liczby to " << sumaCyfr(liczba) << ".";

cin.ignore();
getchar();
}
