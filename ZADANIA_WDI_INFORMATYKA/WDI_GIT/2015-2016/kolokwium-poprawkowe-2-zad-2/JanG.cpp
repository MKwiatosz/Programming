// Jan Golda, 08.12.2016

#include<iostream>

using namespace std;

// dane
const int n;
const int tab[n];

/**
 *  @param - dana liczba
 *  @return - ilosc jedynek w zapisie binarnym danej liczby
 */
int countOnes(int number){
    int result = 0;

    while(number>0){
        result += number%2;
        number /= 2;
    }

    return result;
}

/**
 *  @param a,b,c - dotychczasowe ilosci jedynek w podzbiorach
 *  @param k - index liczby ktora ma zostac teraz przydzielona do podzbioru
 *  @return - ilczba mozliwych podzialow
 */
int divide(int a, int b, int c, int k){
    // sprawdzamy czy juz rozmiescilismy wszystkie liczby z tab[]
    if(k == n)
        return ( (a==b && b==c) ? 1 : 0);

    int j = countOnes(tab[k]);

    // wynikiem jest suma wywolan po umieszczeniu k-tego elementu w jednym z 3 zboirow
    return divide(a+j, b, c, k+1) + divide(a, b+j, c, k+1) + divide(a, b, c+j, k+1);
}

int main(){
    // wywolanie przy zalozeniu ze n i tab[n] sa wypelnione
    // dzielimy przez 3!=6 poniewaz nie rozrozniamy podzbiorow
    cout << divide(0, 0, 0, 0)/6 << endl;

    return 0;
}
