#include <iostream>

/*Proszê napisaæ program, który wczytuje wprowadzany z klawiatury ci¹g liczb naturalnych
zakoñczonych zerem stanowi¹cym wy³¹cznie znacznik koñca danych.
Program powinien wypisaæ 10 co do wielkoœci wartoœæ, jaka wyst¹pi³a w ci¹gu.
Na przyk³ad dla ci¹gu: 1,2,3,2,3,4,5,6,7,8,9,9,11,12,13,0 powinna zostaæ wypisana liczba 3.
Mo¿na za³o¿yæ, ¿e w ci¹gu znajduje siê wystarczaj¹ca liczba elementów.*/

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
