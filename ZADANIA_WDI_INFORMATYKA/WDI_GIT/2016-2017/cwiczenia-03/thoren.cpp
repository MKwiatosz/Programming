/*
 Autor: @thoren (Tomasz Makowski)
*/

#include <iostream>

using namespace std;

int main() {
    
    int suma=0;
    int iloscKrokow;
    int liczba;
    
    cout << "Wprowadz liczbe: ";
    cin >> liczba;
    
    for (iloscKrokow=0; suma<liczba; iloscKrokow++) {
        suma+=2*(iloscKrokow)+1;
    }
    if (liczba==suma) {
        cout << "Liczba: " << liczba << " pierwiastek całowitoliczbowy i wynosi on: " << iloscKrokow << endl;
        return 0;
    }
    else
        cout << "Liczba: " << liczba << " nie ma pierwiastka całkowitoliczbowego." << endl;
    
    return 0;
}