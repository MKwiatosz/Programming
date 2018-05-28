#include <time.h>
#include <iostream>

/* Dane s¹ definicje:
const 
max1 = 100;
max2 = 2000;
type
table = array[1..max1] of array[1..max2] of real;
Typ table opisuje tablicê zawieraj¹c¹ max1 wierszy po max2 elementów. Proszê napisaæ
funkcjê, która dla zmiennej typu table zwraca numer wiersza w którym najwiêksza wartoœæ
jest najmniejsza */

int const N=10;
int const M=10;

// POCZATEK ZADANIA
int MinFromMax(int table[N][M])
{
  double max=table[0][0];
  for(int j=1; j<M; j++)  // przelatuje przez kolumny
        {  
              if(table[0][j]>max) // jesli element jest wiekszy(lub rowny) od nastepnego, to przypisuje nastepnemu element wiekszy
              {
                max=table[0][j];
              }      
        }
  double min=max;
  int k=0;  
  for(int i=1; i<N; i++)  // przelatuje przez wiersze
  {
        double max=table[i][0];
        for(int j=1; j<M; j++)  // przelatuje przez kolumny
        {  
              if(table[i][j]>max) // jesli element jest wiekszy(lub rowny) od nastepnego, to przypisuje nastepnemu element wiekszy
              {
                max=table[i][j];
              }      
        }
   if(min>max)     // max zawiera maksimum w wierszu t[i]. 
   {
     min=max;
     k=i;
   }
  } 
return k;  // zwróci ostatni indeks - do poprawy
}
// KONIEC ZADANIA

int main()
{  
  int table[N][M];
  
  srand(time(NULL));
  for (int i=0; i<N; i++)
  {
        for(int j=0; j<M; j++)
        {        
                 table[i][j]=(rand()%50);
        }         
  }
  for (int i = 0; i<N; i++)
  {
    for (int j = 0; j<M; j++)
	{
		std::cout << table[i][j] << "\t";
		if (j == M - 1) std::cout << std::endl;
	}
  }
  
std::cout << std::endl << MinFromMax(table);

std::cin.ignore();
getchar();
}


 
