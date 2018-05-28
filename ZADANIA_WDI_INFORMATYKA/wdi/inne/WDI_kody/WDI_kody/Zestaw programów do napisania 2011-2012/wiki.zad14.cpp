#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;


/*Proszê napisaæ program, który wczytuje liczbê naturaln¹ i odpowiada na pytanie czy cyfry w tej 
liczbie s¹ w porz¹dku rosn¹cym (niemalej¹cym) */

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
    if(o<=r) return false;   // "<=" - rosn¹cy | "<" - niemalejacy | ">=" - nierosn¹cy | ">" - malej¹cy
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
