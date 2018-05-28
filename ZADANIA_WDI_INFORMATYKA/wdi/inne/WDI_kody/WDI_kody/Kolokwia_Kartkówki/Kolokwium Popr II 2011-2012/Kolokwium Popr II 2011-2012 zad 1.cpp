#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <windows.h>
using namespace std;
int const N=10;

/* 1. Dany jest typ:
type tab = array [1..max,1..max] of integer.
Proszê napisaæ procedurê która znajdzie w tablicy typu tab najwiêkszy kwadrat, z³o¿ony 
wy³¹cznie z elementów, które w zapisie ósemkowym z³o¿one s¹ z niepowtarzaj¹cych siê cyfr. 
Do procedury nale¿y przekazaæ tablicê i parametry znalezionego kwadratu (wspó³rzêdne 
lewego górnego wierzcho³ka i d³ugoœæ boku). Kwadrat 1x1 te¿ jest kwadratem. W przypadku 
nieznalezienia ¿adnego kwadratu d³ugoœæ boku = 0, dane wejœciowe w tablicy maj¹ zostaæ 
niezniszczone. */

struct sqr {
	int x;
	int y;
	int max;

};

bool isGood(int a)
{
bool t[8]= {false, false, false, false, false, false, false, false}; // przechowuje informacje czy cyfra ju¿ wyst¹pi³a
int c;
     for(; a>0;) // generuje kolejne cyfry ósemkowe a
     {
       c=a%8;
       a=a/8;
       if(t[c]==true) return false;
       t[c]=true;
     }  
return true;
}


void Square(int t[N][N], int &l, int &k, int &bok)  // czy dobrze?
{
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
    {
      int max=0
      for(int bok=1; bok+i-1<N and bok+j-1<N; bok++)
      { 
        bool goodSquare=true;
        for(p=i; p<bok+i-1; p++)
          for(r=j; r<bok+j-1; r++)
            if(!IsGood(t[p][r]) goodSquare=false; 
        if(goodSquare and bok>max)
        {
            bok=max;
            k=p;
            l=r;
        }
      }
      
     }
} 
        





// syf

int findSq(bool t[N][N], int y, int x)
{
	int m = 1;
	bool end = false;

	while (!end)
	{
		if ((y + m - 1) < N && (x + m - 1) < N) 
        {
			for (int i = y; i < y + m; i++)
				for (int j = x; j < x + m; j++)
					if (t[i][j] != true)
					{
						end = true;
						m -= 2;
					}
			m++;
		}
		else {
			end = true;
		}
	}
 
    return m;
}
 
sqr Find(bool t[N][N], int a, int b)
{
	sqr max;
	max.max = 0;

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (t[i][j] == true)
            { 
				if (max.max < findSq(t, i, j)) {

					max.max = findSq(t, i, j);
					max.x = j;
					max.y = i;
				}
					
            } 
        }
    }
 
    return max;
}
 

int main()
{
bool booltab[N][N];
int t[N][N];

srand(time(NULL));
for (int i=0; i<N; i++)
{
    for(int j=0; j<N; j++)
    {        
             t[i][j]=(rand()%11);
    }         
}


for(int i=0; i<N; i++)
{
  for(int j=0; j<N; j++)
  {
  booltab[i][j]=isGood(t[i][j]);  //kopiowanie tablicy int na tablice bool (wed³ug warunku liczb w poleceniu)
  }
}

sqr max = Find(booltab, N, N); 
HANDLE hConsole;

hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

cout << "Max: " << max.max << "\tX: " << max.x << "\tY: " << max.y << endl << endl;


for (int i = 0; i<N; i++)
{

	for (int j = 0; j<N; j++)
	{
		if (i >= max.y && i < (max.y + max.max) && j >= max.x && j < (max.x + max.max)) 
			SetConsoleTextAttribute(hConsole, 9);
		else
			SetConsoleTextAttribute(hConsole, 7);
		cout << booltab[i][j] << "\t";
		if (j == N - 1) cout << endl;
	}
}



cin.ignore();
getchar();
}


                       
