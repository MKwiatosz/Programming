// Jan Golda, 12.12.2016

#include<iostream>

using namespace std;

// dane
const int N = 3;
int tab[N][N] = {
    { 1, 3, 6},
    { 2,-5, 9},
    { 8, 3,-7}
};

/**
 *  @param x,y - wspolrzedne pola startowego
 *  @return - najwieksza odleglosc z pola startowego do [N-1][N-1]
 */
int path(int x, int y){

    // gdy jest to pole docelowe
    if(x==N-1 && y==N-1)
        return tab[x][y];

    // gdy jest to pole przy "prawej" krawedzi
    if(x==N-1)
        return tab[x][y] + path(x, y+1);

    // gdy jest to pole przy "dolnej" krawedzi
    if(y==N-1)
        return tab[x][y] + path(x+1, y);

    // gdy jest to pole w "srodku" tablicy
    return tab[x][y] + min(path(x, y+1), path(x+1, y));
}

int main(){

    // przykladowe wywolanie
    cout << path(0, 0) << endl;

    return 0;
}
