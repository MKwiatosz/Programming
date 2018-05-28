### 2016/2017 - Ćwiczenia

Dany jest łańcuch o nieznanej dlugości zbudowany z:
```cpp
struct node {
    node* next;
};
```
Łańcuch ten zawsze kończy się cyklem, czyli 'ostatni' element wskazuje na jakiś już znajdujący się w łańcuchu.

Napisz funkcję która przyjmuje wskaznik na pierwszy element lancucha i zwraca dlugosc cyklu w nim występującego.

#### Przykład ####
- Dla łańcucha `a -> b -> c -> d -> e -> c` odpowiedzią jest 3, cykl `c -> d -> e -> c`

#### Rozwiązanie ####
Rozwiązanie zadania opiera się na algorytmie *"Floyd's tortoise and the hare algorithm"*: [Wikipedia](https://en.wikipedia.org/wiki/Cycle_detection#Tortoise_and_hare)
