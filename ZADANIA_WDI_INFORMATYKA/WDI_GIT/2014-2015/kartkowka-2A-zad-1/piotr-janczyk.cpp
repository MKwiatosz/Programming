/* 2016 Piotr Janczyk */
#include <iostream>
#include <algorithm>
using namespace std;

// Zakładam, że numery wierszy i kolumn na wejściu numerowane są od 1

int main() {
    const int COUNT = 100;
    int xpos[COUNT];
    int ypos[COUNT];
    int dist[COUNT];

    for (int i = 0; i < COUNT; i++) {
        cin >> xpos[i];
        cin >> ypos[i];
        int xdiff = abs(101 - xpos[i]);
        int ydiff = abs(101 - ypos[i]);
        // Król może poruszać się po skosie zatem długość jego trasy nie wyraża
        // się metryką taksówkową (chodzenie w dwóch kierunkach i liczenie ich
        // sumy) tylko za pomocą dłuższej z dwóch odległości (oś X i Y), bo
        // odległość na drugiej może zostać pokonana po skosach, "za darmo".
        dist[i] = max(xdiff, ydiff);

        for (int j = 0; j < i; j++) {
            if (dist[j] == dist[i]) {
                cout << xpos[i] << "," << ypos[i] << endl;
                cout << xpos[j] << "," << ypos[j] << endl;

                return 0;
            }
        }
    }

    cout << "BRAK" << endl;
    return 0;
}
