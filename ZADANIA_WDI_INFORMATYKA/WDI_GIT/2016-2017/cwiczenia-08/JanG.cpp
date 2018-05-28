// Jan Golda, 13.12.2016

#include<iostream>

using namespace std;

struct node{
    node* next;
};

/**
 * Zwraca dlugosc cyklu w lancuchu. Wykorzystuje "Floyd's tortoise and the hare algorithm"
 * @param first - wskaznik na pierwszy element lancucha z cyklem
 * @return dlugosc cyklu
 */
int cycleLength(node* first){

    node* A = first;
    node* B = first->next->next;

    // przesuwa A o jeden, a B o dwa, az nie beda rowne => znaleziony element nalezy do cyklu
    while(A != B){
        A = A->next;
        B = B->next->next;
    }

    // przesuwa sie B o jeden, az B bedzie rowne A => zatoczylismy pelny cykl
    int length = 1;
    B = B->next;
    while(B!=A){
        B = B->next;
        length++;
    }

    return length;
}

int main(){

    // utworzenie przykladowego lancucha dla testu
    node* first = new node;
    node* last = first;
    for(int i = 0; i<3; i++){
        last->next = new node;
        last = last->next;
    }
    node* middle = last;
    for(int i = 0; i<5; i++){
        last->next = new node;
        last = last->next;
    }
    last->next = middle;

    // wywolanie funkcji dla przykladowego lancucha
    cout << cycleLength(first) << endl;

    // usuwanie przykladowego lancucha
    while(first != last){
        node* temp = first->next;
        delete first;
        first = temp;
    }
    delete last;

    return 0;
}
