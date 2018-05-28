### 2009/2010 - Kolokwium poprawkowe 2 - Zad. 3 (22 lutego 2010)

Dany jest łańcuch,  zawierający liczby naturalne,  zbudowany w oparciu o elementy typu:
```cpp
struct node {
    int val;
    node* next;
};
```
Proszę napisać funkcję, która rozdziela elementy łańcucha wejściowego do 10 łańcuchów, według ostatniej cyfry pola `val`.
W drugim kroku powstałe łańcuchy należy połączyć w jeden łańcuch, który jest posortowany niemalejąco według ostatniej cyfry.

Do funkcji należy przekazać wskazanie na łańcuch wejściowy, funkcja powinna zwrócić wskazanie na powstały łańcuch.

#### Przykład ####
> Dla łańcucha:  
> (`2` -> `3` -> `5` -> `7` -> `10` -> `11` -> `23` -> `13` -> `17` -> `24`)  
> Odpowiedzią może być:  
> (`10` -> `11` -> `2` -> `13` -> `3` -> `23` -> `24` -> `5` -> `17` -> `7`)

- - - - -

> Dla łańcucha:  
> (`76` -> `11` -> `234` -> `6` -> `33` -> `91` -> `120` -> `23` -> `44` -> `97` -> `56`)  
> Odpowiedzią może być:  
> (`120` -> `11` -> `91` -> `33` -> `23` -> `234` -> `44` -> `76` -> `6` -> `56` -> `97`)

#### Uwagi ####
- **Wskazówka:** Należy skorzystać z typu `node* t[10]`
