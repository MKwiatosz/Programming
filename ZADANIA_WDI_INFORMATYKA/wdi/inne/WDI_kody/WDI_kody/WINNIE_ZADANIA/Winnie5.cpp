#include <iostream>

/* Prosz� napisa� procedur� wypisuj�ca warto�� u�amka A/B z dok�adno�ci� do N cyfr
dziesi�tnych. Do procedury nale�y przekaza�: licznik, mianownik oraz liczb� okre�laj�c� ilo��
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
