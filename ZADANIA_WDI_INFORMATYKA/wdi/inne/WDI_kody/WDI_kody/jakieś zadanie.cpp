
/*Tablicê typu tab=array[1..100,1..100] of Integer, zawieraj¹c¹ liczby
naturalne podzielono na 100 pól o rozmiarze 10 na 10. Proszê napisaæ
funkcjê, która dla tablicy typu tab zwraca liczbê pól, w których wiêkszoœæ
stanowi¹ liczby pierwsze. */

const int N=100;

bool IsPrime(int a)
{
  if(a==0 or a==1) return false;
  for(int k=2; k*k<a; k++)
    if(a%k==0) return false;
  return true;
}

bool Pole(int &t[N][N], int i, int j)
{
  int num;
  for(int i1=i; i1<i+10; i1++)
    for(int j1=j; j1<j+10; j1++)
      if(IsPrime(t[i1][j1])) num++;
  return num>50;
} 


int LiczbaBloków(int &t[N][N])
{
  int licz=0;  
  for(int i=0; i<N; i+=10)
    for(int j=0; j<N; j+=10)
      if(Pole(t, i, j)) licz++;
  return licz;
}

