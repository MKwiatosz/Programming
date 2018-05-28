// Jan Golda, 15.12.2016

#include<iostream>

using namespace std;

struct node{
    int value;
    node* next;
};

/** Sortuje dany ciag niemalejaco wedlug ostatniej cyfry
 *  @param first - wskaznik na pierwszy element lancucha
 *  @return - wskaznik na pierwszy element posortowanego lancucha
 */
node* sortByLastDigit(node* first){

    // poczatki pod-lancuchow o 'i' jako ostatnia cyfra
    node* B[10];
    // konce pod-lancuchow o 'i' jako ostatnia cyfra
    node* E[10];
    // inicjalizacja tablic
    for(int i = 0; i<10; i++){
        // ustawianie wartownika
        B[i] = new node;
        B[i]->next = NULL;
        // na poczatku pierwszy element jest tez ostatnim
        E[i] = B[i];
    }

    // przepinanie elementow lancucha wejsciowego do odpowiednich pod-lancuchow
    while(first != NULL){
        node* next = first->next;

        E[first->value%10]->next = first;
        E[first->value%10] = first;
        E[first->value%10]->next = NULL;

        first = next;
    }

    // laczenie lancuchow w jeden
    for(int i = 9; i>0; i--){
        E[i-1]->next = B[i]->next;
    }

    node* ans = B[0]->next;

    // usuwanie wartownikow
    for(int i = 0; i<10; i++)
        delete B[i];

    return ans;
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
    int values[] = {76,11,234,6,33,91,120,23,44,97,56};
    node* first = createChain(values, 11);

    // wypisanie danych wejsciowych
    cout << "Input:" << endl;
    printChain(first);

    // sortowanie
    first = sortByLastDigit(first);

    // wypisanie wyniku
    cout << endl << "Output:" << endl;
    printChain(first);

    // usuwanie przykladowego lancucha
    deleteChain(first);

    return 0;
}
