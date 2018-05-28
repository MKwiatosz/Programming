#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

double odleglosc(Point p, Point r) {
    return sqrt(
            abs(p.x - r.x) * abs(p.x - r.x)
          + abs(p.y - r.y) * abs(p.y - r.y)
        );
}

void znajdz(
    Point tab[], int size,
    Point s1, int s1_size,
    Point s2, int s2_size,
    int i,
    int &min_odleglosc) {

    double nowa_odleglosc = odleglosc(s1, s2);

    // Podzbiory nie moga byc puste.
    if (s1_size != 0 && s2_size != 0 && nowa_odleglosc < min_odleglosc) {
        min_odleglosc = nowa_odleglosc;
    }

    if (i == size) {
        return;
    }

    Point p;
    // Jezeli to pierwszy dolaczany do zbioru punkt to nie mozemy wyliczac
    // sredniej arytmetycznej jego wspolrzednych.
    if (s1_size != 0) {
        p.x = (s1.x + tab[i].x) / 2;
        p.y = (s1.y + tab[i].y) / 2;
    } else {
        p = tab[i];
    }

    znajdz(tab, size, p, s1_size + 1, s2, s2_size, i + 1, min_odleglosc);

    // Analogicznie.
    if (s2_size != 0) {
        p.x = (s2.x + tab[i].x) / 2;
        p.y = (s2.y + tab[i].y) / 2;
    } else {
        p = tab[i];
    }

    znajdz(tab, size, s1, s1_size, p, s2_size + 1, i + 1, min_odleglosc);

    znajdz(tab, size, s1, s1_size, s2, s2_size, i + 1, min_odleglosc);
}

double zadanie(Point tab[], int size) {
    int min_odleglosc = 10e9; // Po prostu jakas duza liczba.
    Point p;
    p.x = p.y = 0;

    znajdz(tab, size, p, 0, p, 0, 0, min_odleglosc);
    return min_odleglosc;
}

int main() {
    Point p1, p2, p3;
    
    // Testowanie.
    p1.x = 4.0;
    p1.y = 4.0;

    p2.x = 3.0;
    p2.y = 3.0;

    p3.x = 0.0;
    p3.y = 0.0;

    Point tab[] = { p1, p2, p3 };
    cout << zadanie(tab, sizeof(tab) / sizeof(Point)) << endl;

    return 0;
}