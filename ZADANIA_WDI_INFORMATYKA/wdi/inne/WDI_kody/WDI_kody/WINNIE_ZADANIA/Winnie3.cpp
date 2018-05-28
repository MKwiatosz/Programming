#include <iostream>

/* Liczb� f(i) nazywamy liczb� Fibonacciego, gdy spe�nia r�wnania:
f(i) = 1 dla i=1,2
f(i) = f(i-1) + f(i-2) dla i>2
Prosz� napisa� program kt�ry wczytuje wprowadzon� z klawiatury liczb� naturaln� i
odpowiada na pytanie, czy liczba ta jest sum� co najwy�ej czterech kolejnych liczb
Fibonacciego. */

int main()
{
  int N, a, b, temp;
  
  std::cout << "Podaj liczbe N: ";
  std::cin >> N;
  
  a=1;
  b=1;
  bool flaga=false, out=false;
  
  for(int i=0; !out and !flaga; i++)   // jesli liczba nie jest suma kolejnych wyraz�w ciagu, to i sie przeitureje, nie zmieniajac flagi
  {
    if(i>N) out=true;
    if((a+b)==N) flaga=true;   // suma 2 kolejnych
    if((a+b+(a+b))==N) flaga=true;  // suma 3 kolejnych
    if((a+b+(a+b)+(a+2*b))==N) flaga=true; // suma 4 kolejnych
    temp=a;
    a=b;  
    b=a+temp;
  }

  if(flaga==true) std::cout << "Jest.";
  else std::cout << "Nie jest.";
  

  std::cin.ignore();
  getchar();

  return 0;
}
