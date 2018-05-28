// autor: Wojciech Geisler

// Szukanie takich podciągów cyfr danej liczby, żeby tworzyły liczby podzielne przez 7

#include <iostream>

using namespace ::std;

int main(){
    const int DIVISOR = 7;
    int num;
    cin >> num;

    int tmp_mask, tmp_num, multip, gen;
    
    // okreslenie dlugosci liczby
    int len = 1;
    tmp_num = num;
    while(tmp_num /= 10) ++len;

    for(int mask = 1; mask < (1 << len); ++mask){
        tmp_mask = mask;
        tmp_num = num;
        multip = 1;
        gen = 0;
        while(tmp_mask){
            if(tmp_mask % 2 == 1){
                gen += (tmp_num % 10) * multip; // umieszczenie cyfry na odpowiedniej pozycji
                multip *= 10;
            }
            tmp_mask /= 2;
            tmp_num /= 10;
        }
        if(gen % DIVISOR == 0){
            cout << gen << endl;
        }

    }
    

}
