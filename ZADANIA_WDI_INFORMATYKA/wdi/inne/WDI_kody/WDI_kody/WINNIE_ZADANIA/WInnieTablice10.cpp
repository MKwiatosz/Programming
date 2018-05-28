#include <iostream>

/* Dane s¹ definicje:
const 
max1 = 100;
max2 = 2000;
type
table = array[1..max1, 1..max2] of real;
Proszê napisaæ procedurê, która dla zmiennej typu table zwraca numer wiersza i kolumny
elementu, dla którego suma otaczaj¹cych go elementów jest najmniejsza. */

struct Para
{
  int i;
  int j;
};

const int N=10;
const int M=10
;

int sumaElementow(int t[N][M], int i, int j)
{
  int suma=0;
  
  if(i>0)
  {
    suma+=((j>0)?t[i-1][j-1]:0)+
          t[i-1][j]+
          ((j<N-1)?t[i-1][j+1]:0);
  }
  if(i<N-1)
  { 
    suma+=((j>0)?t[i+1][j-1]:0)+
          t[i+1][j]+
          ((j<N-1)?t[i+1][j+1]:0);
  }
  suma+=((j>0)?t[i][j-1]:0)+
        ((j<N-1)?t[i][j+1]:0);
  return suma;
}

Para NajmnSuma(int t[N][M])
{
  int min=sumaElementow(t, 0, 0);
  int k=0, l=0;
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<M; j++)
    {
      
      if(min>sumaElementow(t, i, j)) 
      {
        min=sumaElementow(t, i, j);
        k=i;
        l=j;
      }
    }
  }
  Para p;
  p.i=k;
  p.j=l;
  return p;
}
  
int main()
{
  int t[N][M];

  srand(time(NULL));
  for (int i=0; i<N; i++)
  {
        for(int j=0; j<M; j++)
        {        
                 t[i][j]=(rand()%2);
        }   
  } 
  for (int i = 0; i<N; i++)
  {
    for (int j = 0; j<M; j++)
	{
	  std::cout << t[i][j] << "\t";
	  if (j == M - 1) std::cout << std::endl;
	}
  }    
  
  Para x=NajmnSuma(t);
  std::cout << x.i << " " << x.j;
   
  std::cin.ignore();
  getchar();    
}
