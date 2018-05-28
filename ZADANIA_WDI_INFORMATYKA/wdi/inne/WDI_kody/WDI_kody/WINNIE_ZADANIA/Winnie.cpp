#include <iostream>

/* Dane s¹ deklaracje:
const
max = 20;
type
tablica = array[1..max, 1..max] of integer;
var
T: tablica;
Proszê napisaæ procedurê, która zmienn¹ typu tablica wype³nia "po spirali" kolejnymi
wyrazami ci¹gu arytmetycznego o zadanym wyrazie pocz¹tkowym i zadanej ró¿nicy ci¹gu. Do
procedury nale¿y przekazaæ: wype³nian¹ tablicê, wyraz pocz¹tkowy i ró¿nicê ci¹gu. */

int const N=5;

#if 0
void TablicaPoSpirali(int t[N][N], int a1, int r)
{
  bool doPrzodu=true;
  int dlugosc=N;
  int i=0 ,j=0;
  while(true)
  {
    for(int k=0; k<dlugosc; k++)
    {      
      t[i][j]=a1;
      a1+=r;
      doPrzodu ? j++ : j--;
    }
    if(dlugosc==1) break;
    dlugosc--;
    for(int k=0; k<dlugosc; k++)
    {      
      t[i][j]=a1;
      a1+=r;
      doPrzodu ? i++ : i--;
    }
    doPrzodu=!doPrzodu;
    
  }
}
#endif


void TablicaPoSpirali(int t[N][N], int a1, int r)
{
  bool doPrzodu=true;
  int dlugosc=N-1;
  int i=0 ,j=0;

  
  for(int k=0; k<dlugosc; k++)
  {      
    t[i][j]=a1;
    a1+=r;
    doPrzodu ? j++ : j--;
  }
  
  for(; dlugosc>0; dlugosc--)
  {
    for(int k=0; k<dlugosc; k++)
    {      
      t[i][j]=a1;
      a1+=r;
      doPrzodu ? i++ : i--;
    }
    doPrzodu=!doPrzodu;    
    for(int k=0; k<dlugosc; k++)
    {      
      t[i][j]=a1;
      a1+=r;
      doPrzodu ? j++ : j--;
    }
  }
  t[i][j]=a1;  // ostatni element 

    for (int i = 0; i<N; i++)
  {
    for (int j = 0; j<N; j++)
	{
	  std::cout << t[i][j] << "\t";
	  if (j == N - 1) std::cout << std::endl;
	}
  }


}  

int main()
{

  int t[N][N];
  int a1=3;
  int r=2;

  TablicaPoSpirali(t, a1, r);
std::cin.ignore();
getchar();  
}

