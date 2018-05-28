#include <iostream>

/*Dane s� deklaracje:
const
max = 20;
type
tablica = array[1..max, 1..max] of integer;
var
T: tablica;
Prosz� napisa� funkcj�, kt�ra zwraca warto�� true je�eli w zmiennej typu tablica istnieje
przynajmniej jedna para s�siednich element�w, kt�rych suma jest r�wna �redniej
arytmetycznej wszystkich element�w tablicy. */

int const N=10;

bool SredniaRownaSumie(int t[N][N])
{
  int suma=0;
  double srednia;  
  
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      suma=suma+t[i][j];    
  
  srednia=(double)suma/(N*N);  
  std::cout << srednia << std::endl;
  
  suma=0;
  for(int i=0; i<N;i++)  // sumowanie sasiednich element�w poziomych
  {  
    for(int j=0; j<N-1; j++)
    {
      suma=t[i][j]+t[i][j+1];
      if(suma==srednia){ std:: cout << i << '.' <<j << '-' << i << '.' << j+1; return true;}
    }
  }
  for(int i=0; i<N-1; i++) // sumowanie sasiednich element�w pionowych
  {
    for(int j=0; j<N; j++)
    {    
      suma=t[i][j]+t[i+1][j];
      if(suma==srednia)
      { 
        std:: cout << i << '.' <<j << '-' << i+1  << '.' << j; 
        return true;
      }
    }
  }
  for(int i=0; i<N-1;i++) // sumowanie sasiednich element�w tak : /// 
  {
    for(int j=0; j<N-1; j++)
    {  
      suma=t[i][j+1]+t[i+1][j];
      if(suma==srednia)
      { 
        std::cout << i << '.' << j+1 << '-' << i+1  << '.' << j; 
        return true;
      }
    }
  }
  for(int i=0; i<N-1; i++)  // sumowanie sasiednich element�w tak : \\\ xx 
  {
    for(int j=0; j<N-1; j++)
    {  
      suma=t[i][j]+t[i+1][j+1];
      if(suma==srednia)
      { 
        std::cout << i << '.' << j << '-' << i+1  << '.' << j+1; 
        return true;
      }      
    } 
  }
  return false;
}
 

int main()
{  
  int t[N][N];
  
  srand(time(NULL));
  for (int i=0; i<N; i++)
  {
        for(int j=0; j<N; j++)
        {        
                 t[i][j]=(rand()%50);
        }         
  }
  for (int i = 0; i<N; i++)
  {
    for (int j = 0; j<N; j++)
	{
	  std::cout << i << '.' << j << ':' << t[i][j] << "\t";
	  if (j == N - 1) std::cout << std::endl;
	}
  }
  
  SredniaRownaSumie(t);

  std::cin.ignore();
  getchar();
  
  return 0;
}
