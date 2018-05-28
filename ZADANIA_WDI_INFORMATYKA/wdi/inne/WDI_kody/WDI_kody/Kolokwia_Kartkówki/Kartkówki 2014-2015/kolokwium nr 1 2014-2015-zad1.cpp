#include <iostream>

/*Prosz� napisa� program, kt�ry wczytuje wprowadzany z klawiatury ci�g liczb naturalnych
zako�czonych zerem stanowi�cym wy��cznie znacznik ko�ca danych.
Program powinien wypisa� 10 co do wielko�ci warto��, jaka wyst�pi�a w ci�gu.
Na przyk�ad dla ci�gu: 1,2,3,2,3,4,5,6,7,8,9,9,11,12,13,0 powinna zosta� wypisana liczba 3.
Mo�na za�o�y�, �e w ci�gu znajduje si� wystarczaj�ca liczba element�w.*/

int main()
{
  int number;
  int t[10] = {0,0,0,0,0,0,0,0,0,0};  // w tej tablicy bede trzymal elementy w porzadku rosnacym 
  for(;;)
  {
    std::cin >> number;
    if(number==0) break;
    int i;
    for(i=0; i<10 and t[i]>number ;i++)
      ;
    if(i==10 or t[i]==number) continue;
    for(int j=8; j>=i ;j--) 
      t[j+1]=t[j];
    t[i]=number;      
  }
  std::cout << "10 wartosc: " << t[9];
  return 0;
}
