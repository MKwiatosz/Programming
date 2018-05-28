#include <iostream>

/* Dane s¹ nastêpuj¹ce definicje:
const 
max = 10;
var
tab: array[1..max] of real;
Proszê napisaæ program, który wczytuje wprowadzony z klawiatury ci¹g dodatnich liczb
rzeczywistych zakoñczony wartoœci¹ -1, bêd¹c¹ znacznikiem koñca ci¹gu i umieszcza max
najwiêkszych elementów w tablicy tab. Mo¿na za³o¿yæ, ¿e ci¹g zawiera co najmniej max liczb. */

int const N=10;

int main()
{
  double liczba;
  double t[N];
  
  
  for(int i=0; i<N; i++)
  {
    std::cin >> t[i];
  } 
  for(int i=0; i<N-1; i++)
  for(int j=0; j<N-1; j++)
    if(t[j]>t[j+1]) std::swap(t[j], t[j+1]); // <-- sortowanie na ci¹g rosn¹cy
  for(;;)
  {
    std::cin >> liczba;
    if(liczba==-1) break;
    
    int i;
    for(i=0; i<N and t[i]<liczba; i++);
    if(i==0) break;
      
    for(int j=0; j<i-1; j++)
      t[j]=t[j+1];
    t[i-1]=liczba;
  }

  for(int k=0; k<N; k++)
  {
    std::cout << t[k] << " ";
  }
  
  std::cin.ignore();
  getchar();
}
    
      
