#include <iostream>

/* Dane s� definicje:
const 
max1 = 10; max2 = 200;
type
wiersz = array[1..max2] of integer;
table = array[1..max1] of wiersz;
Typ table opisuje tablic� zawieraj�c� max1 wierszy po max2 element�w. Prosz� napisa�
funkcj�, kt�ra dla zmiennej typu table zwraca ilo�� wierszy, w kt�rych warto�ci element�w
stanowi� ci�gi arytmetyczne. */

const int N=100;
const int M=200;

int CiagArtm_wiersz(int t[N][M])
{
  int licznik=0;  
  int r;
  for(int i=0; i<N; i++)
  {
    int ilosc=0;
    r=t[i][1]-t[i][0];
    for(int j=1; j<M-1; j++)
    {
      int temp=r;
      r=t[i][j+1]-t[i][j];
      if(temp!=r) break;
      ilosc++;
      if(ilosc==M-2) licznik++;
    }
  }
  return licznik;
}
    
int main() // sprawdzam tylko
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
	  if (j == M - 1) std::cout << std::endl << std::endl;
	}
  }
  
  std::cout << std::endl << CiagArtm_wiersz(t);
  
  std::cin.ignore();
  getchar();
}
    
 
  
