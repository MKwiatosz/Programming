#include <iostream>
using namespace std;

int sumuj_slowo(const char *slowo) {
    int i = 0;
    int suma = 0;

    // const char * to lanchuch znakow albo inaczej tablica charow zakonczona
    // znakiem o kodzie ASCII 0 (nie mylic z cyfra zero o kodzie 48).
    while (slowo[i] != '\0') {
        suma += slowo[i];
        i++;
    }
    return suma;
}

int policz_samogloski(const char *slowo) {
    int i = 0;
    int ilosc = 0;

    // Sprawdzam wszystkie znaki w lanchuchu znakow.
    while (slowo[i] != '\0') {
        if (slowo[i] == 'a'
            || slowo[i] == 'e'
            || slowo[i] == 'i'
            || slowo[i] == 'o'
            || slowo[i] == 'u'
            || slowo[i] == 'y') {
            ilosc++;
        }
        i++;
    }
    return ilosc;
}

bool czy_waza_tyle_samo(const char *a, const char *b) {
    return sumuj_slowo(a) == sumuj_slowo(b)
        && policz_samogloski(a) == policz_samogloski(b);
}

bool porownaj(
    const char *slowo,
    const char *drugie_slowo,
    string podzbiorowe_slowo,
    int p) {

    // Funkcja c_str() zwraca lanchuch znakow (const char *) ze stringa.
    if (czy_waza_tyle_samo(slowo, podzbiorowe_slowo.c_str())) {
        cout << podzbiorowe_slowo << endl;
        return true;
    }

    // Odsylam do komentarza o const charach u gory.
    if (drugie_slowo[p] == '\0') {
        return false;
    }

    return porownaj(slowo, drugie_slowo, podzbiorowe_slowo + drugie_slowo[p], p + 1)
        || porownaj(slowo, drugie_slowo, podzbiorowe_slowo, p + 1);
}

bool zadanie(const char *slowo, const char *drugie_slowo) {
    return porownaj(slowo, drugie_slowo, "", 0);
}

int main() {
    cout << zadanie("ula", "abcdefex") << endl;
    return 0;
}