#include <iostream>
#include <math.h>

/* Trójk¹ pitagorejsk¹ nazywa siê w matematyce trzy liczby naturalne a, b, c spe³niaj¹ce
warunek a^2 + b^2 = c^2. Proszê napisaæ program wczytuj¹cy liczbê naturaln¹ N i
wypisuj¹cy wszystkie trójki w których c nie przekracza N. */

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
