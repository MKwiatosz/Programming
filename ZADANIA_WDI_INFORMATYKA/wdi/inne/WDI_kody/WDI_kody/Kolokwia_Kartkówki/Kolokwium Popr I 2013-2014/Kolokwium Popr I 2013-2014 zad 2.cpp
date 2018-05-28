#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;
int const N=5;

#if 0
int rozklad(int k, int q)
{
if(k==0 or k==1) return -1;

int b = k;
q=2 // zle
      
              while(b%q==0)
              {
              b=b/q;
              if(k==q) return -1;  // liczba pierwsza
              }

rozklad(k, q+1); // ...
return q;

}
#endif

int hasPath(int t[N], int i) // zwraca iloœæ skoków z indeksu i do na koniec tablicy lub -1 gdy nie ma mo¿liwoœci
{
if(i==N-1) return 0; // jesteœmy na koñcu tablicy

// policz mo¿liwe skoki
int a=t[i];
int l;
// dla wszustkich dzielników pierwszych a 
for(int p=2; p<a; p++) // generuje dzielniki pierwsze
{
  if(a%p==0) // p jest dzielnikiem a
  {
    while(a%p==0) a=a/p;
    if(i+p<N)
    { 
      l=hasPath(t, i+p);
      if(l!=-1) return l+1;
    } 
  }
}
return -1;
}

int main()
{
int t[N]= {77,0,6,4,10};

cout << "Liczba skokow: " << hasPath(t, 0);


cin.ignore();
getchar();
}

