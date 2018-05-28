#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <windows.h>
using namespace std;
int const N=10;

/* 1. Dany jest typ:
type tab = array [1..max,1..max] of integer.
Prosz� napisa� procedur� kt�ra znajdzie w tablicy typu tab najwi�kszy kwadrat, z�o�ony 
wy��cznie z element�w, kt�re w zapisie �semkowym z�o�one s� z niepowtarzaj�cych si� cyfr. 
Do procedury nale�y przekaza� tablic� i parametry znalezionego kwadratu (wsp�rz�dne 
lewego g�rnego wierzcho�ka i d�ugo�� boku). Kwadrat 1x1 te� jest kwadratem. W przypadku 
nieznalezienia �adnego kwadratu d�ugo�� boku = 0, dane wej�ciowe w tablicy maj� zosta� 
niezniszczone. */

struct sqr {
	int x;
	int y;
	int max;

};

bool isGood(int a)
{
bool t[8]= {false, false, false, false, false, false, false, false}; // przechowuje informacje czy cyfra ju� wyst�pi�a
int c;
     for(; a>0;) // generuje kolejne cyfry �semkowe a
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
  booltab[i][j]=isGood(t[i][j]);  //kopiowanie tablicy int na tablice bool (wed�ug warunku liczb w poleceniu)
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


                       
