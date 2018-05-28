// Rozwiązanie podane na tablicy przez Gajęckiego
// ...co nie gwarantuje poprawności. Dwa ostatnie if-y 
// musiał mu podpowiedzieć student na wykładzie.

#include <iostream>
#include <cmath>

using namespace ::std;

int main(){
	// a, b - wartości wyrazów ciągu
	// k - zadana liczba
	// d - numer wyrazu w ciągu będącego odpowiedzią do zadania
	// n - licznik wyrazów ciągów
	// min - najmniejsza znaleziona odległość od `k`
	// c - oznaczenie ciągu do którego odnosi się `d`
	int a,b,k,d,n,min;
	char c;
	cin >> k;
	a = 1;
	b = 2;
	min = k + 1;
	for(n = 1; a <= k or b <= k; ++n){
		if(abs(a - k) < min){
			min = abs(a - k); 
			c = 'a';
			d = n;
		}
		if(abs(b - k) < min){
			min = abs(b - k); 
			c = 'b';
			d = n;
		}
		b = a + b;
		a = a + b / 3;
	}
	// sprawdzenie pierwszego wyrazu większego od k
	if(abs(a - k) < min){
		min = abs(a - k); 
		c = 'a';
		d = n;
	}
	if(abs(b - k) < min){
		min = abs(b - k); 
		c = 'b';
		d = n;
	}

	cout << d << ' ' << c << endl;

}
