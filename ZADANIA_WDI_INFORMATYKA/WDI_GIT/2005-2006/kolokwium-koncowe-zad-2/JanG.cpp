// Jan Golda 13.12.2016

#include<iostream>
#include<string>

using namespace std;

/** Stwierdza czy dany char jest mala litera
 *  @param c - char do sprawdzenia
 *  @return - true jezeli nalezy do (a...z), false w innym przypadku
 */
bool isLowercaseLetter(char c){
    // 'a'==97 'z'==122
    return 97<=c && c<=122;
}

/**
 *  @param subset - elementy dotychczas wybrane do podzbioru
 *  @param index - indeks elementu z inSet ktory ma teraz zostac rozwazony
 *  @param hasLetter - czy jak do tad w subset jest przynajmniej jedna litera
 *  @param isSet - zbior wejsciowy
 */
void _printSubsets(string subset, int index, bool hasLetter, string inSet){

    // warunek konca
    if(index >= inSet.length()){
        if(hasLetter)
            cout << subset << endl;
        return;
    }

    // nie bierzemy tego elementu
    _printSubsets(subset, index+1, hasLetter, inSet);

    // bierzemy ten element
    hasLetter = hasLetter || isLowercaseLetter(inSet[index]);
    _printSubsets(subset+inSet[index], index+1, hasLetter, inSet);

}

/**
 *  @param inSet - zbior ktorego podzbiory mamy wypisać
 */
void printSubsets(string inSet){
    _printSubsets("", 0, false, inSet);
}

int main(){

    // przykladowe wywolanie
    printSubsets("a12");

    return 0;
}
