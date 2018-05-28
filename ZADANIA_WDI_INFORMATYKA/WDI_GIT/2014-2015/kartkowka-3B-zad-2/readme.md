### 2014/2015 - Kartkówka 3 - Grupa B - Zad. 2

Dane są dwa jednokierunkowe łańcuchy odsyłaczowe (listy) zbudowane z elementów:

```cpp
struct node {
    int w;
    node* next;
};
```

Każdy łańcuch zawiera niepowtarzające się liczby naturalne. W obu łańcuchach liczby są posortowane rosnąco.
Proszę napisać funkcję usuwającą z każdego łańcucha liczby nie występujące w drugim. Do funkcji należy przekazać
wskazania na oba łańcuchy, funkcja powinna zwrócić łączną liczbę usuniętych elementów.
