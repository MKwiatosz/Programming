/*2. Dana jest tablica typu tab = array [1..100] of integer wype³niona liczbami naturalnymi. 
Stoj¹c na polu tablicy o indeksie n mo¿emy przesun¹æ siê w prawo o liczbê bêd¹c¹ czynnikiem pierwszym 
liczby t[n]. Na przyk³ad:
- wartoœæ w polu tablicy wynosi 12, mo¿emy przeskoczyæ o 2 lub 3 pola,
- wartoœæ w polu tablicy wynosi 14, mo¿emy przeskoczyæ o 2 lub 7 pól,
- wartoœæ w polu tablicy wynosi 17, mo¿emy przeskoczyæ o 17 pól.
Proszê napisaæ program, który tablicê typu tab wype³nia liczbami pseudolosowymi z zakresu [2..100], 
nastêpnie odpowiada na pytanie: czy jest mo¿liwe przejœcie z pola 1 do 100?*/

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
