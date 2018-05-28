#include <iostream>

/*Dane s¹ deklaracje:
const
max = 10;
type
tablica = array[1..max, 1..max] of integer;
var
T: tablica;
Zak³adamy, ¿e zmienna typu tablica jest wype³niona przypadkowymi wartoœciami. Proszê
napisaæ procedurê, która dla zmiennej typu tablica zwraca wspó³rzêdne i, j elementu T[i, j]
dla którego suma elementów w "ukoœnych rzêdach" jest najwiêksza. */

struct Para
{
  int i;
  int j;
};

int const N=10;


int SumaRzedow(int t[N][N], int i, int j)
{
  int i_prim, j_prim, suma=0;
  int Tp[N][N];
  
  if(j==i)
  {
    for(i_prim=0, j_prim=0; i_prim<N and j_prim<N; i_prim++, j_prim++)
    {
    suma+=t[i_prim][j_prim];
    }
  }
  std::cout << suma << " ";
  if(j<i)
  {
    for(i_prim=i-j, j_prim=0; i_prim<N and j_prim<N; i_prim++, j_prim++)
    {
      suma+=t[i_prim][j_prim];
    }
  }   
  std::cout << suma << " ";
  if(j>i)
  {
    for(i_prim=0, j_prim=j-i; i_prim<N and j_prim<N; i_prim++, j_prim++)
    {
      suma+=t[i_prim][j_prim];
    }
  }
  std::cout << suma << " ";
  for(i_prim=0; i_prim<N; ++i_prim)
  { 
    for(j_prim=0; j_prim<N; ++j_prim) 
    {
      Tp[N - i_prim - 1][j_prim] = t[j_prim][i_prim];
    }
  }
  j_prim=i;
  i_prim=j;
  
  i=N-i_prim-1;
  j=j_prim;
  
  if(j==i)
  {
    for(i_prim=0, j_prim=0; i_prim<N and j_prim<N; i_prim++, j_prim++)
    {
      suma+=Tp[i_prim][j_prim];
    }
  }
  std::cout << suma << " ";  
  if(j<i)
  {
    for(i_prim=i-j, j_prim=0; i_prim<N and j_prim<N; i_prim++, j_prim++)
    {
      suma+=Tp[i_prim][j_prim];
    }
  }
  std::cout << suma << " ";
  if(j>i)
  {
    for(i_prim=0, j_prim=j-i; i_prim<N and j_prim<N; i_prim++, j_prim++)
    {
      suma+=Tp[i_prim][j_prim];
    }
  }
  std::cout << suma << " ";
  return suma;
}

Para MaxSuma(int t[N][N])
{
    int max=SumaRzedow(t, 0, 0), k=0, l=0;
    for(int i=0; i<N; i++)
    {
      for(int j=0; j<N; j++)
      {
        std::cout << max << std::endl;    
        if(max<SumaRzedow(t, i, j)) 
        {
          max=SumaRzedow(t, i, j);
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
  int t[N][N];

  srand(time(NULL));
  for (int i=0; i<N; i++)
  {
        for(int j=0; j<N; j++)
        {        
                 t[i][j]=(rand()%15);
        }   
  } 
  for (int i = 0; i<N; i++)
  {
    for (int j = 0; j<N; j++)
	{
	  std::cout << t[i][j] << "\t";
	  if (j == N - 1) std::cout << std::endl;
	}
  } 
 

  std::cout << SumaRzedow(t, 4, 5);
  std::cin.ignore();
  getchar(); 
  
}
        
      
