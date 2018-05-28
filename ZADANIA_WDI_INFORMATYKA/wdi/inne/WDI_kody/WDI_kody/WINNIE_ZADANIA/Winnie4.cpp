#include <iostream>

/* Prosz� napisa� procedur� zamieniaj�c� nieujemn� liczb� ca�kowit� na system o podstawie p i
wypisuj�ca jej warto�� w nowym systemie. Do procedury nale�y przekaza� liczb� i podstaw�
systemu, na kt�ry zamieniamy. */

void zamiana(int N, int p)
{ 
   if(N==0) return;  // warunek ko�ca rekursji. je�li n=0 wychodzimy z instancji.
   
   int reszta=N%p;
   N=N/p;
   zamiana(N, p);   // rekurencja, zeby nie uzywac tablic i wypisa� od ko�ca
   if(reszta<10) std::cout << reszta;
   else
   {
     char litera=reszta+55;  // zamiana na kod asci dla reszt 11-16
     std::cout << litera;
   }
}
   
int main()
{
  int N,p;
  std::cout << "Podaj liczbe N w systemie 10: ";
  std:: cin >> N;
  std::cout << std::endl << "Podaj podstawe na ktora chcesz zamienic liczbe N (2-16): ";
  std::cin >> p;
 
  std::cout << std::endl << "Liczba " << N << " w systemie " << p << " to ";
  zamiana(N, p);
  std::cout << ".";
  
  std::cin.ignore();
  getchar();            
  return 0;  
}
