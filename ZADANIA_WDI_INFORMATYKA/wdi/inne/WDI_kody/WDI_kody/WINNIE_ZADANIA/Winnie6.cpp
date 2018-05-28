#include <iostream>

/* Dane s¹ ci¹gi a(n), b(n) i c(n) okreœlone nastêpuj¹co:
a(n) = 1 dla n=1, 2
a(n) = a(n-1)+a(n-2) dla n>2
b(n) = 1 dla n=1, 2, 3
b(n) = b(n-1)+b(n-2)+b(n-3) dla n>3
Wyrazy ci¹gu c(n) s¹ kolejnymi liczbami naturalnymi nale¿¹cymi do ci¹gu a(n) lub b(n). Ci¹gi
te przyjmuj¹ wartoœci:
ci¹g a(n) 1 1 2 3 5 8 13 21 ...
ci¹g b(n) 1 1 1 3 5 9 17 31 ...
ci¹g c(n) 1 2 3 5 8 9 13 17 ...
Proszê napisaæ program który wczytuje wprowadzon¹ z klawiatury liczbê naturaln¹ i wypisuje
kolejne wyrazy ci¹gu c(n) mniejsze od wprowadzonej liczby. */

int main()
{
  int a1,a2,b1,b2,b3,N;
  a1=1;
  a2=2;
  b1=1;
  b2=3;
  b3=5;
  
  std::cout << "Podaj liczbe N: ";
  std::cin >> N;
  std::cout << std::endl;
   
  for(;a1<N;)
  {
        for(;a1<N;)
        {            
            if(a1==b1 and a1<N)   // jeœli takie a(i)=b(i) przeskocz z a(i) dalej, ¿eby nie wypisaæ 2 razy
            { 
              std::cout << a1 << " "; 
              int temp=a1;
              a1=a2;
              a2=a2+temp;  
              break;
            }
            if(a1<b1 and a1<N) std::cout << a1 << " ";
            if(b1<a1 and b1<N)
            { 
              std::cout << b1 << " "; 
              break;
            }
            int temp=a1; //generacji ciagu a(i)
            a1=a2;
            a2=a2+temp;                
        }       
        int temp=b1;   // generacja ciagu b(i)
        int temp2=b2;
        b1=b2;
        b2=b3;
        b3=temp+temp2+b3; 
  }  
           

  std::cin.ignore();
  getchar();

  return 0;
}

    
