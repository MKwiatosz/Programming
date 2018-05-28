// 2016-12-13
// Wojciech Geisler

#include <iostream>

using namespace std;

const int N = 5;

// pomocnicze tablice, żeby nie liczyć w kółko tego samego
int sums_row[N];
int sums_col[N];

struct coord{ 
	int r, c; // wiersz, kolumna
};

// jeśli funkcja ma zwracac obie pozycje, musimy je umieścić w jednej strukturze
struct coordpair{ 
	coord p1, p2;
};


// wylicza sumy wierszy
void init(int t[N][N]){
	for(int i = 0; i < N; ++i){
		sums_row[i] = sums_col[i] = 0;
	}
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			sums_row[i] += t[i][j];
			sums_col[j] += t[i][j];
		}
	}
}

// funkcja wylicza zysk z postawienia wieży na pozycji p2, 
// jeśli jedna wieża już stoi na p1
int gain(int t[N][N], coord p1, coord p2){
	if(p1.r == p2.r){ 
		// stoją w tym samym wierszu, jedyny zysk to kolumna p2 i 
		// pole, na którym stoi wieża 1, bo dotychczas nie było szachowane.
		// Odejmuje pole p2, bo jest już zliczone jako szachowane przez wieżę 1
		return sums_col[p2.c] - t[p2.r][p2.c] + t[p1.r][p1.c];
	}
	if(p1.c == p2.c){ 
		// stoją w tej samej kolumnie
		return sums_row[p2.r] - t[p2.r][p2.c] + t[p1.r][p1.c];
	}
	// różna kolumna i wiersz. Odejmuje przecięcia oraz pole p2,
	// bo zostałoby policzone dwukrotnie a nie powinno być liczone wcale
	return sums_col[p2.c] + sums_row[p2.r] - 2 * t[p2.r][p2.c] - t[p1.r][p2.c] - t[p2.r][p1.c];
}

// funkcja spełniająca warunki zadania
coordpair best(int t[N][N]){
	init(t);
	int a, b, k, l, sum, sum2, max;
	coordpair best;
	max = 0; // zakładam liczby naturalne w tablicy - wersja zadania z 2016
	int size = N * N;

	// dla uproszczenia przeglądania kwadratowej tablicy "w przód"
	// użyje jednej zmiennej, którą potem przelicze na parę współrzędnych

	for(int i = 0; i < size - 1; ++i){
 		a = i / N; b = i % N;
		sum = sums_row[a] + sums_col[b] - 2 * t[a][b];
		for(int j = i + 1; j < size; ++j){
			k = j / N; l = j % N;
			sum2 = sum + gain(t, {a,b}, {k,l}); 
			if(sum2 > max){ // znaleziono nową najlepszą pozycję
				max = sum2;
				best = {{a,b},{k,l}};
			}
		}
	}
	return best;
}

int main(){
	int t[N][N];
	cerr << "Podaj tablicę " << N << " x " << N << endl;
	for(int i = 0; i < N * N; ++i){
		cin >> t[i/N][i%N];
	}

	coordpair result = best(t);

	cout << result.p1.r << ' ' << result.p1.c << ' ' << result.p2.r << ' ' << result.p2.c << endl;
}
