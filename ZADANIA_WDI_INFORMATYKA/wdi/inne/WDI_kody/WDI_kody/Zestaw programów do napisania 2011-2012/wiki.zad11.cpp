#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;

/* Prosz� napisa� program, kt�ry wczytuje liczb� naturaln� i wyznacza liczb� jedynek w jej 
reprezentacji dw�jkowej. 
*/

int howMany1inBinary(int n)
{
  if(n==0) return 0;
  if(n==1) return 1 ;
  int i=0;
  while(n>0)
  {
    if(n%2==0) n=n/2;
    else
    {
      n=n/2;
      i++;
    }
    
  }
return i;
}   
  
int main()
{
    int liczba;
    
    cout << "Podaj liczbe w systemie (10): ";
    cin >> liczba;
    cout << endl << "Liczba zawiera " <<  howMany1inBinary(liczba) << " jedynek.";
    
cin.ignore();
getchar();
}
      
    
    
