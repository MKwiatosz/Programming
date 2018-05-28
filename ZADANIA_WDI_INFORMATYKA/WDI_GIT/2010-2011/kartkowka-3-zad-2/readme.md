### 2010/2011 - Kartkówka 3 - Zad. 2 - (11 stycznia 2011)

Dany jest łańcuch zawierający liczby naturalne, zbudowany w oparciu o elementy typu:

```cpp
struct node {
    int value;
    node* next;
};
```

Proszę napisać funkcję, która rozdziela elementy łańcucha wejściowego do 2 łańcuchów, zależnie od reszty dzielenia pola `value` przez `3`. Dla reszty równej `1` lub `2`, element należy umieścić odpowiednio w łańcuchu pierwszym lub drugim. Pozostałe elementy łańcucha wejściowego należy usunąć z pamięci.

Doprocedury należy przekazać wskazanie na łańcuch wejściowy, oraz wskazania na powstałe łańcuchy.

#### Przykład ####
> Dla łańcucha:  
> (`0` -> `1` -> `2` -> `3` -> `18` -> `21` -> `37` -> `13` -> `8` -> `5` -> `100`)  
> Odpowiedzią może być:  
> (`100` -> `13` -> `37` -> `1`)  (`5` -> `8` -> `2`)  

#### Uwagi ####
- Łańcuch wejściowy może być pusty
- Kolejność elementów w łańcuchach wyjściowych nie ma znaczenia
