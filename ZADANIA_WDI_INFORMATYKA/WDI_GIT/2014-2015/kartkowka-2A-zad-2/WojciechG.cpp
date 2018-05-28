#include <iostream>

using namespace std;

char vowels[] = {'a','e','i','o','u','y','\0'};


// sprwadzanie, czy litera jest samogłoską 
bool is_vowel(char c){
	int i = 0;
	while(vowels[i] != c && vowels[i] != '\0')
		++i;
	return vowels[i] != '\0';
}

struct weight{
	int sum;
	int vowels;

	weight();
	void add(char c);
	bool operator==(weight const& r);
};

weight::weight(){
	sum  = 0;
	vowels = 0;
}
 
void weight::add(char c){
	if(is_vowel(c)){
		++vowels;
	}
	sum += c;
}

bool weight::operator==(weight const& r){
	return r.sum == sum && r.vowels == vowels;
}

// debug
void print(weight const& w){
	cerr << "s: " << w.sum << " w: " << w.vowels << endl;
}

// funkcja rekurencyjna
// target - waga s1
// s - slowo z ktorego wybieramy podciągi
// pos - dodana (lub nie) pozycja
// acc - accumulator - do niego dodawane są wagi
// result - słowo spełniające zadanie
bool wordr(weight const& target, string const& s, int pos, weight acc, string& result){
	if(acc == target){
		// warunek spełniony
		return true;
	}
	if(pos == s.size() - 1){
		// nie udało się
		return false;
	}

	if(wordr(target, s, pos + 1, acc, result)){
		// pominięcie następnej litery
		return true;
	}

	// dodanie następnej litery
	acc.add(s[pos + 1]);

	if( wordr(target, s, pos + 1, acc, result)){
		result = s[pos + 1] + result;
		return true;
	}
	return false;
}


// wrapper rekurencji
bool word(string s1, string s2){
	string result;
	bool ok;
	weight target;
	weight acc; // accumulator - do niego dodawane są wagi

	for(int i = 0; i < s1.size(); ++i){
		target.add(s1[i]);
	}

	ok = wordr(target, s2, -1, acc, result);
	if(ok){
		cout << result << endl;
	}
	return ok;
}

int main(){
	string s1,s2;
	cin >> s1 >> s2;
	cout << word(s1,s2)<<endl; 


}
