/*2. Dana jest tablica typu tab = array [1..100] of integer wype�niona liczbami naturalnymi. 
Stoj�c na polu tablicy o indeksie n mo�emy przesun�� si� w prawo o liczb� b�d�c� czynnikiem pierwszym 
liczby t[n]. Na przyk�ad:
- warto�� w polu tablicy wynosi 12, mo�emy przeskoczy� o 2 lub 3 pola,
- warto�� w polu tablicy wynosi 14, mo�emy przeskoczy� o 2 lub 7 p�l,
- warto�� w polu tablicy wynosi 17, mo�emy przeskoczy� o 17 p�l.
Prosz� napisa� program, kt�ry tablic� typu tab wype�nia liczbami pseudolosowymi z zakresu [2..100], 
nast�pnie odpowiada na pytanie: czy jest mo�liwe przej�cie z pola 1 do 100?*/

const int N=100;

bool CzyMozna(int t[N], int n)
{
  if(n==N-1) return true;
  bool l;
  int a=t[n];
  for(int p=2; p<a; p++)
  {
    if(a%p==0)  
    { 
      while(a%p==0)
        a/=p;
      if(n+p<N)
      {
        if(CzyMozna(t, n+p)) return true;
      }
    }      
  }
  return false;
}  
