// Jan Golda, 15.12.2016

#include<iostream>

using namespace std;

struct node{
    int value;
    node* next;
};

/**
 *  @param in - lancuch do podzielenia
 *  @param @return out1 - lancuch zawierajacy liczby przystajace do 1 (mod 3)
 *  @param @return out2 - lancuch zawierajacy liczby przystajace do 2 (mod 3)
 */
void splitMod3(node* in, node *&out1, node *&out2){
    out1 = NULL;
    out2 = NULL;

    while(in != NULL){
        node* next = in->next;

        switch(in->value%3){

            // liczba przstaje do 0 (mod 3) -> usuwamy
            case 0:
                delete in;
                break;

            // liczba przstaje do 1 (mod 3) -> przepinamy do out1
            case 1:
                in->next = out1;
                out1 = in;
                break;

            // liczba przstaje do 2 (mod 3) -> przepinamy do out2
            case 2:
                in->next = out2;
                out2 = in;
                break;
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
    int values[] = {0,1,2,3,18,21,37,13,8,5,100};
    node* in = createChain(values, 11);

    // wypisanie danych wejsciowych
    cout << "Input:" << endl;
    printChain(in);

    // dzielenie
    node* out1 = NULL;
    node* out2 = NULL;
    splitMod3(in, out1, out2);

    // wypisanie wyniku
    cout << endl << "Output:" << endl;
    printChain(out1);
    printChain(out2);

    // usuwanie lancuchow
    deleteChain(out1);
    deleteChain(out2);

    return 0;
}
