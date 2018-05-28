### 2014/2015 - Kartkówka 3 - Grupa A - Zad. 2 - *wtorek, 20 stycznia 2015*

Dane są dwa jednokierunkowe łańcuchy odsyłaczowe (listy) zbudowane z elementów:

```cpp
struct node {
    int w;
    node* next;
};
```
Każdy łańcuch zawiera niepowtarzające się liczby naturalne. W pierwszym łańcuchu liczby są posortowane rosnąco, a w drugim nie. Proszę napisać funkcję usuwającą z obu łańcuchów liczby występujące w obu łańcuchach. Do funkcji należy przekazać wskazania na oba łańcuchy, funkcja powinna zwrócić łączną liczbę usuniętych elementów.

*Uwaga:* W zadaniu rozważyć użycie wartownika.
