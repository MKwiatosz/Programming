#include <iostream>

/* Dane s� nast�puj�ce definicje:
const 
max = 10;
var
tab: array[1..max] of real;
Prosz� napisa� program, kt�ry wczytuje wprowadzony z klawiatury ci�g dodatnich liczb
rzeczywistych zako�czony warto�ci� -1, b�d�c� znacznikiem ko�ca ci�gu i umieszcza max
najwi�kszych element�w w tablicy tab. Mo�na za�o�y�, �e ci�g zawiera co najmniej max liczb. */

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
    if(t[j]>t[j+1]) std::swap(t[j], t[j+1]); // <-- sortowanie na ci�g rosn�cy
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
    
      
