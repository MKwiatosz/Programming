// Wojciech Geisler
// 2016-10-23
// Implementacja rozwiązania podanego przez p. Gajęckiego na wykładzie

#include <iostream>

using namespace ::std;

int main(){
    int count2, count5;
    count2 = count5 = 0;
    int last = 1;
    int last2 = 0;

    int num;
    cin >> num;

    for(int i = 2; i <= num; ++i){
        int n = i;
        while(n%5 == 0){
            ++count5;
            n /= 5;
        }
        while(n%2 == 0){
            ++count2;
            n /= 2;
        }

        last = last * (n % 10) % 10;
    }
    count2 = (count2 - count5) % 4;

    switch(count2){ // ostatnie cyfry potęg dwójki powtarzają się cyklicznie
        case 0:
            last *= 6;
            break;
        case 1:
            last  *= 2;
            break;
        case 2:
            last  *= 4;
            break;
        case 3:
            last  *= 8;
            break;
    }

    cout << last % 10 << endl;


}
