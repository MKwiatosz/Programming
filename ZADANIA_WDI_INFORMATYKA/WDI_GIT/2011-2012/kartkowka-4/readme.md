### 2011/2012 - Kartkówka 4

Dana jest łańcuch zbudowany w oparciu o:
```cpp
struct node {
    int value;
    node* next;
};
```
Liczbę oznaczamy jako niskobitową, jeśli w reprezentacji binarnej liczba jedynek jest mniejsza niż `8`, średniobitową, gdy liczba jedynek pomiędzy `8 a 24`, wysokobitową, gdy liczba jedynek przekracza `24`.

Napisać funkcję, która podzieli dany łańcuch na trzy łańcuchy z liczbami nisko, średnio i wysokobitowymi, a następnie złączy te łańcuchy w jeden i zwróci wskaznik na niego.

#### Przykład: ####
Dla łańcucha:  
(`45` -> `33554431` -> `7035` -> `16777215` -> `1979` -> `1464`)  
Możliwą odpowiedzią jest:  
(`45` -> `1464` -> `7035` -> `16777215` -> `1979` -> `33554431`)  
Ponieważ:

| DEC | BIN | '1' | Typ |
| --- | --- | --- | --- |
| 45 | 101101 | 4 | nisko |
| 33554431 | 1111111111111111111111111 | 25 | wysoko |
| 7035 | 1101101111011 | 10 | średnio |
| 16777215 | 111111111111111111111111 | 24 | średnio |
| 1979 | 11110111011 | 9 | średnio |
| 1464 | 10110111000 | 6 | nisko |
