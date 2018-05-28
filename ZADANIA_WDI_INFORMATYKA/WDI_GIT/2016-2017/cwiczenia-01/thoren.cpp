/*
 Autor: @thoren (Tomasz Makowski)
*/

#include <iostream>

using namespace std;

int main() {
    
    int a,b,c;
    
    cout << "Wprowadz liczby: " << endl;
    cin >> a;
    cin >> b;
    
    int liczba1 = a;
    int liczba2 = b;
    
    while (b!=0) {
        c=(a%b) ;
        a=b ;
        b=c ;
    }
    
    cout << "NWD(" << liczba1 << "," << liczba2 << ") = " << a << endl;
    
    return 0;
}