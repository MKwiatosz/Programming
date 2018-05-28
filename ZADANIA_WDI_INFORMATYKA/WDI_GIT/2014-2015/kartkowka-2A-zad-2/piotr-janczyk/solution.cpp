/* 2016 Piotr Janczyk */
#include <string>
using namespace std;

// sprawdza czy litera jest samogloska
bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

// src - napis zrodlowy
// sum - pozostala suma kodow ASCII
// vowels - pozostala liczba samoglosek
// g - generowany napis
// pos - biezaca pozycja (indeks) w napisie zrodlowym
bool generate(const string& src, int sum, int vowels, string& g, int pos) {
    if (pos == src.length()) {
        return sum == 0 && vowels == 0;
    }

    // wariant 1: nie dodajemy litery
    if (generate(src, sum, vowels, g, pos + 1)) {
        return true;
    }

    // wariant 2: dodajemy litere
    char ch = src[pos];
    sum -= ch;
    if (is_vowel(ch)) {
        vowels--;
    }
    g.push_back(ch);
    bool ret = generate(src, sum, vowels, g, pos + 1);
    g.pop_back();
    return ret;
}

bool wyraz(string s1, string s2) {
    int sum = 0;
    int vowels = 0;
    for (int i = 0; i < s1.length(); i++) {
        char ch = s1[i];
        if (is_vowel(ch)) {
            vowels++;
        }
        sum += (int) ch;
    }

    string tmp;
    return generate(s2, sum, vowels, tmp, 0);
}
