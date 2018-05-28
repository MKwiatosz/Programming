/*Zad. 2
Do budowy liczby naturalnej reprezentowanej w systemie dwójkowym mo¿emy u¿yæ A cyfr
1 oraz B cyfr 0, gdzie A,B>0. Proszê napisaæ
funkcjê, która dla zadanych parametrów A i B zwraca
iloœæ wszystkich mo¿liwych do zbudowania liczb, takich ¿e pierwsza cyfra w systemie dwójkowym
(najstarszy bit) jest równa 1, a zbudowana liczba jest z³o¿ona.*/

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

// A-iloœæ pozostalych "1"
// B-iloœæ pozostalych "0"
// N=pierwotna suma A+B (z poczatku)
// p-poziom rekursji = numer bitu w liczbie którym siê zajmujemy
// liczba- generowana liczba
// Zwraca liczbe dobrych liczb w podrzewie rekursji
int Zlozone2(int A, int B, int N, int p, int liczba)
{ 
 if(p==N) // liœæ drzewa rekursji
 {
   return (A==0 and B==0 and IsComposite(liczba) and IsFirstOne(liczba, N)) ? 1 : 0; // zwraca 1 jesli jest dobrze, 0 Ÿle
 }
 
 return Zlozone2(A, B-1, N, p+1, liczba) + Zlozone2(A-1, B, N, p+1, liczba | (1<<p));  //zwraca sume z poddrzew do góry rekursji
}

int Funkcja48(int A, int B)
{
  return Zlozone2(A, B, A+B, 0, 0);  // g³ówne wywolanie na poziomie 0
}
