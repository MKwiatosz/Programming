// Wojciech Geisler
// 2016-11-04

// Zadanie polega na wyliczaniu wartości e do zadanej liczby miejsc po przecinku
// posługując się szeregiem e = 1/0! + 1/1! + 1/2! + ...
// Uwaga - ustalona liczba miejsc oznacza ilość miejsc dla których
// wykonywane są obliczenia. W istocie jest to mniejsza dokładność
// niż zaokrąglenie e do takiej liczby miejsc po przecinku.

#include <iostream>

using namespace ::std;

int main(){
    int prec;
    cin >> prec;
	// wynikowa liczba, przy założeniu że po pierwszym elemencie ustawiamy przecinek
	// tj. wynikowo będzie zawierać [2,7,1,...]
    int e[prec+1]; 
    int part[prec+1]; // kolejny składnik szeregu
    for(int i = 0; i <= prec; ++i){ // zerowanie
        e[i] = part[i] = 0;
    }
    e[0] = 1;
    part[0] = 1;

    int fact = 1; // liczba w mianowniku

    int pos = 0;
    while(pos <= prec){
        // szukanie pierwszej niezerowej cyfry w zapisie ułamka
        while(!part[pos]) ++pos; 

        // dzielenie pisemne
        int n = 0;
        for(int i = pos; i <= prec; ++i){
            n = n * 10 + part[i];
            part[i] = n / fact;
            n = n - part[i] * fact;
        }

        // dodawanie do wyniku
        int overflow = 0;
        for(int i = prec; i >= 0; --i){
            e[i] = e[i] + part[i] + overflow;
            overflow = e[i] / 10;
            e[i] = e[i] % 10;
        }

        ++fact;
    }

    // wypisanie e
    for(int i = 0; i <= prec; ++i){
        cout << e[i];
    }
    cout << endl;

}
