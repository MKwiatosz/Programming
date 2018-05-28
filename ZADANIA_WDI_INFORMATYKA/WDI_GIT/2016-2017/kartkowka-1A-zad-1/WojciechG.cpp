#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int k;
	cin >> k;

	int a, b, dist_a, dist_b, pdist_a, pdist_b;
	int best_dist, best_pos; // "poprzedni" (w pętli) dystans
	bool is_a; // określa który ciąg jest odpowiedzią zadania
	int i = 1;
	best_dist = k + 1;
	a = 1; b = 2;
	dist_a = k - a;
	dist_b = k - b;
	pdist_a = pdist_b = k + 1;

	// pętla działa dopóki obie odległości nie zaczną wzrastać
	while(dist_a < pdist_a || dist_b < pdist_b){
		++i;
		b = b + a;
		a = a + b / 3;
		// pomocnicze wypisywanie (do debugowania)
		// użycie `cerr` pozwala je łatwo oddzielić od wyjścia faktycznego
		cerr << i << ": " << a << ' ' << b << endl; 

		pdist_a = dist_a;
		pdist_b = dist_b;
		dist_a = abs(a - k);
		dist_b = abs(b - k);

		if(dist_a  < best_dist){
			best_pos = i;
			best_dist = dist_a;
			is_a = true;
		}
		if(dist_b  < best_dist){
			best_pos = i;
			best_dist = dist_b;
			is_a = false;
		}

	}

	cout << best_pos << endl;
	cout << (is_a ? "a" : "b") << endl;


}
