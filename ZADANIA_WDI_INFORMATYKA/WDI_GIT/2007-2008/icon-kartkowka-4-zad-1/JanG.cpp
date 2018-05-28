// Jan Golda, 08.12.2016

#include<iostream>

using namespace std;

// data
const int N = 5;
bool tab[N][N] = {
    {false,false,false,false,false},
    {false,false,true, true, false},
    {false,true, true, false,false},
    {false,true, true, true, false},
    {false,false,false,false,false},
};

/** Zatapia to i sasiednie pola
 *  @param x,y - wspolrzedne pola do zatopienia
 *  @return - ilosc zatopionych pol
 */
int plunge(int x, int y){
    // sprawdzamy czy nie jest juz woda
    if(!tab[x][y])
        return 0;

    // zatapianie danego pola
    tab[x][y] = false;

    // zatapianie sasiednich pol
    return 1 + plunge(x, y-1) + plunge(x, y+1) + plunge(x-1, y) + plunge(x+1, y);
}

int main(){

    cout << plunge(3, 3) << endl;

    return 0;
}
