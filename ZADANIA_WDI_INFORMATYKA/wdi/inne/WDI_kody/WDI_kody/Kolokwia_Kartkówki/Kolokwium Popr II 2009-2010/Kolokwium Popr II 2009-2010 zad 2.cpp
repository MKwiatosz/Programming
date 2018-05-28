/*Zad. 2
Do budowy liczby naturalnej reprezentowanej w systemie dw�jkowym mo�emy u�y� A cyfr
1 oraz B cyfr 0, gdzie A,B>0. Prosz� napisa�
funkcj�, kt�ra dla zadanych parametr�w A i B zwraca
ilo�� wszystkich mo�liwych do zbudowania liczb, takich �e pierwsza cyfra w systemie dw�jkowym
(najstarszy bit) jest r�wna 1, a zbudowana liczba jest z�o�ona.*/

bool IsComposite(int a)
{
  if(a==1) return false;  
  int i=2;
  while(i*i<=a)
  {
    if(a%i==0) return true;
    i++;
  }
  return false;
}

bool IsFirstOne(int a, int N)
{
  return (a>>(N-1))==1; 
}

// A-ilo�� pozostalych "1"
// B-ilo�� pozostalych "0"
// N=pierwotna suma A+B (z poczatku)
// p-poziom rekursji = numer bitu w liczbie kt�rym si� zajmujemy
// liczba- generowana liczba
// Zwraca liczbe dobrych liczb w podrzewie rekursji
int Zlozone2(int A, int B, int N, int p, int liczba)
{ 
 if(p==N) // li�� drzewa rekursji
 {
   return (A==0 and B==0 and IsComposite(liczba) and IsFirstOne(liczba, N)) ? 1 : 0; // zwraca 1 jesli jest dobrze, 0 �le
 }
 
 return Zlozone2(A, B-1, N, p+1, liczba) + Zlozone2(A-1, B, N, p+1, liczba | (1<<p));  //zwraca sume z poddrzew do g�ry rekursji
}

int Funkcja48(int A, int B)
{
  return Zlozone2(A, B, A+B, 0, 0);  // g��wne wywolanie na poziomie 0
}
