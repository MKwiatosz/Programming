#include <iostream>

/* Proszê napisaæ procedurê wypisuj¹ca wartoœæ u³amka A/B z dok³adnoœci¹ do N cyfr
dziesiêtnych. Do procedury nale¿y przekazaæ: licznik, mianownik oraz liczbê okreœlaj¹c¹ iloœæ
miejsc po przecinku. */

void dzieleniePisemne(int a, int b, int N)
{  
  int x=a; 
  
  if(a<b)
  {   
    std::cout << a/b << '.';   
    for(int i=0; i<N; i++)
    {
      a=a*10;
      std::cout << a/b;
      a=a%b;
    }
  a=x; 
  }
 
  if(a>b)
  {    
    std::cout << a/b << '.';
    for(int i=0; i<N; i++)
    {
      a=a%b;
      a=a*10;
      std::cout << a/b;
    }
    a=x;    
  }
 
  if(a==b)
  {
    std::cout << a/b << '.';
    for(int i=0; i<N; i++)
      std::cout << 0;
  }
}

int main()
{
  int a, b, N;
  std::cout << "Podaj licznik A: ";
  std::cin >> a;
  std::cout << "Podaj mianownik B: ";
  std::cin >> b;
  std::cout << "Podaj dokladnosc N liczb po przecinku: ";
  std::cin >> N;
  std::cout << std::endl;
 
 dzieleniePisemne(a, b, N);
 
 std::cin.ignore();
 getchar(); 
 return 0;
}  
