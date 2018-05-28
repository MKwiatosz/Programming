### 2011/2012 - Kolokwium poprawkowe 2 - Zad. 3

Dana jest łańcuch zbudowany w oparciu o:
```cpp
struct node {
    int value;
    node* next;
};
```  
Proszę napisać funkcję rozdzielającą łańcuch na 2 łańcuchy według wartości, w taki sposób, że w pierwszym łańcuchu znajdą się liczby, które są wielokrotnością kwadratu liczby pierwszej, a w drugim pozostałe.

#### Przykład: ####
> Dla łańcucha:  
> (`0` -> `1` -> `2` -> `3` -> `18` -> `75` -> `37` -> `13` -> `8` -> `5` -> `100`)  
> Możliwą odpowiedzią jest:  
> (`100` -> `8` -> `75` -> `18`) (`5` -> `13` -> `37` -> `3` -> `2` -> `1` -> `0`)  
> Ponieważ:  
> `100` i `75` - wielokrotności `5^2=25`  
> `8` - wielokrotność `2^2=4`  
> `18` - wielokrotność `3^2=9`  
