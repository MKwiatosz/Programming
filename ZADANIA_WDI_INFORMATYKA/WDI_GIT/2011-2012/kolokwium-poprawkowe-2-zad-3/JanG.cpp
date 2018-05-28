// Jan Golda, 16.12.2016

#include<iostream>

using namespace std;

struct node{
    int value;
    node* next;
};

/** Sprawdza czy dana liczba jest wielokrotnoacia kwadratu liczby pierwszej
 *  @param n - liczba do sprawdzenia
 *  @return - true jezeli jest, false w innym wypadku
 */
bool isMultipleOfSquareOfPrimaryNumber(int n){
    // rozkladamy liczbe na czynniki pierwsze
    int i = 2;
    while(n>1){
        if(n%i==0){
            n /= i;
            // jezeli ten samy czynnik pierwszy wystepuje kilka razy to liczba jest wielokrotnoscia kwadratu liczby pierwszej
            if(n%i==0)
                return true;
        }
        i++;
    }

    return false;
}

/** Dzieli dany lancuch na dwa wzgledem wzgledem tego czy dana liczba jest wielokrotnoscia kwadratu liczby pierwszej czy nie
 *  @param in - lancuch do podzielenia
 *  @param @return out1 - lancuch zawierajacy liczby bedace wielokrotnascia kwadratu liczby pierwszej
 *  @param @return out2 - lancuch zawierajacy pozostale liczby
 */
void splitMultiPrimaryNumber(node* in, node *&out1, node *&out2){
    out1 = NULL;
    out2 = NULL;

    while(in != NULL){
        node* next = in->next;

        // przepinaym element do odpowiednich lancuchow
        if(isMultipleOfSquareOfPrimaryNumber(in->value)){
            in->next = out1;
            out1 = in;
        }else{
            in->next = out2;
            out2 = in;
        }

        in = next;
    }
}

/** Tworzy nowy lancuch z zadanymi wartosciami
 *  @param values[] - wartosci do umieszczenia w lancuchu
 *  @param length - dlugosc lancucha
 *  @return wskaznik na pierwszy element nowo utworzonego lancucha
 */
node* createChain(int values[], int length){
    node* first = new node;
    first->value = values[0];
    node* A = first;
    for(int i = 1; i<length; i++){
        A->next = new node;
        A = A->next;
        A->value = values[i];
    }
    return first;
}

/** Wypisuje dany lancuch na standardowe wyjscie
 *  @param in - wskaznik na pierwszy element lancucha do wypisania
 */
void printChain(node* in){
    while(in != NULL){
        cout << " -> " << in->value;
        in = in->next;
    }
    cout << endl;
}

/** Usuwa dany lancuch z pamieci
 *  @param in - wskaznik na pierwszy element lancucha do usuniecia
 */
void deleteChain(node* in){
    while(in != NULL){
        node* temp = in;
        in = in->next;
        delete temp;
    }
}

int main(){

    // tworzenie przykladowego ciagu
    int values[] = {0,1,2,3,18,75,37,13,8,5,100};
    node* in = createChain(values, 11);

    // wypisanie danych wejsciowych
    cout << "Input:" << endl;
    printChain(in);

    // dzielenie
    node* out1 = NULL;
    node* out2 = NULL;
    splitMultiPrimaryNumber(in, out1, out2);

    // wypisanie wyniku
    cout << endl << "Output:" << endl;
    printChain(out1);
    printChain(out2);

    // usuwanie lancuchow
    deleteChain(out1);
    deleteChain(out2);

    return 0;
}
