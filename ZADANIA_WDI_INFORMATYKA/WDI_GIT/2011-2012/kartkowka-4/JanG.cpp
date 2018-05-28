// Jan Golda, 16.12.2016

#include<iostream>

using namespace std;

struct node{
    int value;
    node* next;
};

/** Oblicza ilosc jedynek w reprezentacji binarnej danej liczby
 *  @param n - liczba do sprawdzenia
 *  @return - ilosc jedynek w n
 */
int countBinaryOnes(int n){
    int result = 0;
    while(n>0){
        if(n%2==1)
            result++;
        n /= 2;
    }
    return result;
}

/** Dzieli dany lancuch na 3: 'niskobitowy', 'sredniobitowy' i 'wysokobitowy', a nastepnie zwraca ich sume
 *  @param first - wskaznik na pierwszy element lancucha
 *  @return - wskaznik na pierwszy element posortowanego lancucha
 */
node* sortByNumberOfOnes(node* first){

    // poczatki pod-lancuchow, B[0] - niskobitowy, B[1] - sredniobitowy, B[2] - wysokobitowy
    node* B[3];
    // konce pod-lancuchow, E[0] - niskobitowy, E[1] - sredniobitowy, E[2] - wysokobitowy
    node* E[3];
    // inicjalizacja tablic
    for(int i = 0; i<3; i++){
        // ustawianie wartownika
        B[i] = new node;
        B[i]->next = NULL;
        // na poczatku pierwszy element jest tez ostatnim
        E[i] = B[i];
    }

    // przepinanie elementow lancucha wejsciowego do odpowiednich pod-lancuchow
    while(first != NULL){
        node* next = first->next;

        // obliczanie ilosci jedynek
        int ones = countBinaryOnes(first->value);

        // wybieranie odpowiedzniego pod-lancucha
        int index;
        if(ones < 8){
            index = 0;
        }else if(ones <= 24){
            index = 1;
        }else{
            index = 2;
        }

        // przepianie elementu
        E[index]->next = first;
        E[index] = first;
        E[index]->next = NULL;

        first = next;
    }

    // laczenie lancuchow w jeden
    for(int i = 2; i>0; i--)
        E[i-1]->next = B[i]->next;

    node* ans = B[0]->next;

    // usuwanie wartownikow
    for(int i = 0; i<3; i++)
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
    int values[] = {45,33554431,7035,16777215,1979,1464};
    node* first = createChain(values, 6);

    // wypisanie danych wejsciowych
    cout << "Input:" << endl;
    printChain(first);

    // sortowanie
    first = sortByNumberOfOnes(first);

    // wypisanie wyniku
    cout << endl << "Output:" << endl;
    printChain(first);

    // usuwanie przykladowego lancucha
    deleteChain(first);

    return 0;
}

