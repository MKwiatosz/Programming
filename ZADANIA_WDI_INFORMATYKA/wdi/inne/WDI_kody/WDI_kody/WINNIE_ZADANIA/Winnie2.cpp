#include <iostream>

/*Proszê napisaæ program który wczytuje wprowadzon¹ z klawiatury liczbê naturaln¹ i
odpowiada na pytanie, czy liczba ta jest wielokrotnoœci¹ kwadratu dowolnej liczby naturalnej
wiêkszej od 1 i nie jest równoczeœnie wielokrotnoœci¹ szeœcianu dowolnej liczby naturalnej
wiêkszej od 1.*/

int main()
{
  int N;

  std::cout << "Podaj liczbe N: ";
  std::cin >> N;

  int i=2;
  bool w_kwadrat=false, w_szescian=false, out1=false, out2=false; // czy kwadrat, czy szescian, wyjscie z petli1, wyjscia z petli 2

  while(!w_kwadrat and !out1)
  {
    if(i*i>N) out1=true; 
    if(N%(i*i)==0) w_kwadrat=true;  
    else i++;  
  }

  i=2;
  while(!w_szescian and !out2)
  {
    if(i*i*i>N) out2=true;
    if(N%(i*i*i)==0) w_szescian=true;
    else i++;
  }

  if(!w_kwadrat) std::cout << "Nie jest.";
  if(w_kwadrat and !w_szescian) std::cout << "Tak jest.";
  if(w_kwadrat and w_szescian) std::cout << "Nie jest.";


  std::cin.ignore();
  getchar();
  
  return 0;
}
