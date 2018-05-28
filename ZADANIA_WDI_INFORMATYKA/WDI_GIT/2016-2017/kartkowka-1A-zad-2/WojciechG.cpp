// Wojciech Geisler
// 2016-11-08

// Wypisywane wartości z tablicy nie są konieczne dla algorytmu
// ale pomagają w ocenie jego pracy. Nie potrzebne na kolokwium.

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	const int max = 15;
	int tab[max];
	int najw[10];
	int sum = 0;
	srand(time(NULL));
	for(int i = 0; i < max; i++){
		tab[i] = rand() % 1000 + 1;
		cout << tab[i] << ",\t"; // debug
	}
	cout << endl; // debug

	for(int i = 0; i < 10; ++i){
		najw[i] = 0;
	}

	for(int i = 0; i < max; ++i){
		if(tab[i] > najw[0]){
			najw[0] = tab[i];
			// umieszczam element t[i] w tablicy największych z zachowaniem kolejności rosnącej
			for(int j = 1; j < 10 and najw[j] < tab[i]; ++j){ 
				najw[j - 1] = najw[j];
				najw[j] = tab[i];
			}
		}
	}

	for(int i = 0; i < 10; ++i){
		cout << najw[i] << ",\t"; // debug
		sum += najw[i];
	}
	cout << endl; // debug

	cout << sum << endl;


}
