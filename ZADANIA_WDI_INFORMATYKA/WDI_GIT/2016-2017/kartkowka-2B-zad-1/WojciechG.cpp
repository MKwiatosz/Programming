// 2016-12-13
// Wojciech Geisler
//
// Uwaga! Poniższe rozwiązanie wypisuje kilkakrotnie identyczne pary, jeśli 
// podana N ma powtarzające się cyfry. Nie wiem, czy jest to zgodne z wymogami zadania.
//
// Na pewno też powtarzają się wartości między pierwszą i drugą częścią, tj. wypisywany
// jest zarówno podział (a, b) jak (b, a). Wg. dr Słoty jest to akceptowalna interpretacja zadania.

#include <iostream>

using namespace ::std;

// sprawdzenie, czy liczby są względnie pierwsze
bool are_coprime(int a, int b){
	int r;
	if(a == 0){
		return false;
	}
	while(b != 0){
		r = a % b;
		a = b; 
		b = r;
	}
	return a == 1;
}

// argumenty exp1, exp2, których wartościami są potęgi 10
// pozwalają mi ustawiać cyfry na odpowiednich pozycjach, 
// przeglądając source "od tyłu"
int partition(int source, int part1 = 0, int part2 = 0, int exp1 = 1, int exp2 = 1){
	if(source == 0){
		if(are_coprime(part1, part2)){
			cout << part1 << ' ' << part2 << endl;
			return 1;
		} else {
			return 0;
		}
	}

	// rozważam dopisanie ostatniej cyfry source do pierwszej lub drugiej części
	return \
		partition(source / 10, part1 + exp1 * (source % 10), part2, exp1 * 10, exp2) + \
		partition(source / 10, part1, part2 + exp2 * (source % 10),  exp1, exp2 * 10);
}


int main(){
	int n;
	cin >> n;
	cout << partition(n) << endl;;
}
