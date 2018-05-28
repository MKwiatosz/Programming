#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;


/*Prosz� napisa� program, kt�ry wczytuje liczb� naturaln� i odpowiada na pytanie czy cyfry w tej 
liczbie s� w porz�dku rosn�cym (niemalej�cym) */

bool czyCiagRosnacy(int n)
{
  if(n<10) return false;
  int r;
  int o;

  while(n>0)
  {            
    o=n%10;
    n=n/10;
    r=n%10;
    if(n==0) return true;
    if(o<=r) return false;   // "<=" - rosn�cy | "<" - niemalejacy | ">=" - nierosn�cy | ">" - malej�cy
  }
return true;
}

int main()
{
int liczba; 
    
cout << "Podaj liczbe naturalna: ";
cin >> liczba;

if(czyCiagRosnacy(liczba)) cout << endl << "Tworzy ciag rosnacy.";
else cout << endl << "Nie tworzy ciagu rosnacego.";

cin.ignore();
getchar();
}
