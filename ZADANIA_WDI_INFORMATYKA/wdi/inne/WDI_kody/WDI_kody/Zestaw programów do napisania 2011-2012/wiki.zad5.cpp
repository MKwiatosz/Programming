#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;

/* Prosz� napisa� program generuj�cy kolejne elementy ci�gu Fibonaciego mniejsze od 1000. 
Zadanie rozwi�za� z u�yciem 3, 2, 1 zmiennej. */

int main()
{
int a=0;
int b=1;
cout << a << endl;
cout << b << endl;
do
{
  a=a+b;
  b=a+b;
  cout << a << endl;
  if (b<1000) cout << b << endl;
}while(b<1000);

cin.ignore();
getchar();
}
  
