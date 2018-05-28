#include <iostream>

/*Dane s¹ deklaracje:
const 
max1 = 100;
max2 = 200;
type
tablica = array[1..max1, 1..max2] of integer;
var
T: tablica;
Zak³adamy, ¿e zmienna typu tablica jest wype³niona przypadkowymi wartoœciami. Proszê
napisaæ procedurê, która dla zmiennej typu tablica zwraca wspó³rzêdne elementu T[i, j] dla
którego iloraz sumy elementów w i-tej kolumnie i sumy elementów w j-tym wierszu jest
okreœlony (uwaga na dzielenie przez 0) i jest najwiêkszy. */

struct Para
{
  int i;
  int j;
};

int const N=10;
int const M=10;

Para MaxOfSumaPrzezSuma(int table[N][M])
{
  int sumCol[M], sumRow[N];  // tablice SumaKolumn, SumaWierszy.
  
  for(int j=0; j<M; j++)  // Oblicza sumy kolumn i zapisuje w tablicy SumCol.
  {
    sumCol[j]=0;
    for(int i=0; i<N; i++)
      sumCol[j]+=table[i][j];
  }

  
  for(int i=0; i<N; i++)   // Oblicza sumy wierszy i zapisuje w tablicy SumRow. 
  {
    sumRow[i]=0;
    for(int j=0; j<M; j++)
      sumRow[i]+=table[i][j];
  }     
#if 0
  int i;
  for(i=0; i<N; i++)
  {
    if(sumRow[i]!=0) break;
  }
#endif
  
  int i=0;
  while(sumRow[i]==0)
    i++;
  
  double max=(double)sumCol[0]/sumRow[i];
  int k=i, l=0;
  for(; i<N; i++)
  {
    if(sumRow[i]==0) continue;
    for(int j=0; j<M; j++)
    {
      if(max<sumCol[j]/sumRow[i]) max=sumCol[j]/sumRow[i];
      k=i;
      l=j;
    }
  }

  Para p;
  p.i=k;
  p.j=l;
  return p;   
// return std::make_pair(k, l);
}

int main()
{
int table[N][M];
}
