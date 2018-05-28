#include <iostream>
#include <math.h>

/* Tr�jk� pitagorejsk� nazywa si� w matematyce trzy liczby naturalne a, b, c spe�niaj�ce
warunek a^2 + b^2 = c^2. Prosz� napisa� program wczytuj�cy liczb� naturaln� N i
wypisuj�cy wszystkie tr�jki w kt�rych c nie przekracza N. */

int main()
{
  int a, b, N, licznik=0;
  double c;
  
  std::cout << "Podaj N: ";
  std::cin >> N;
  
  for(a=1; a<N; a++)
  {
    b=a;
    while(b<N)
    {
      c=sqrt(a*a+b*b);
      if(c<N and c>1 and c==round(c))
        {
        licznik++; 
        std::cout << licznik << ".\t" << a << "\t" << b << "\t" << c << std::endl;
        }
      b++;
    }
  }
  if(!licznik) std::cout << "Brak takich trojek.";

std::cin.ignore();
getchar();

}
