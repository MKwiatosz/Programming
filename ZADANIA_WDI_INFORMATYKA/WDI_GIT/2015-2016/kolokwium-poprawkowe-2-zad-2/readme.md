### 2015/2016 - Kolokwium poprawkowe 2 - Zad. 2 - (5 lutego 2016)
### 2009/2010 - Kolokwium końcowe - Zad. 2 (28 stycznia 2010)

Dany jest zbiór `N` liczb naturalnych umieszczony w tablicy `int tab[N]`.

Proszę napisać funkcję, która zwraca informację, czy jest możliwy podział zbioru `N` liczb na trzy podzbiory, tak aby w każdym podzbiorze, łączna liczba jedynek użyta do zapisu elementów tego podzbioru w systemie dwójkowym była jednakowa.

#### Przykład ####
- *{2,3,5,7,15} -> true*, bo podzbiory *{2,7}* *{3,5}* *{15}* wymagają użycia *4* jedynek.
- *{5,7,15} -> false*, podział nie istnieje.

#### Uwagi ####
- Zawartość tablicy wejściowej nie może ulec  zmianie.
- Dodatkowe *2 pkt.* można otrzymać, jeżeli funkcja zamiast informacji logicznej, w efektywny sposób policzy i zwróci liczbę istotnie różnych podziałów zbioru na podzbiory.  
  Na przykład: *{2,3,5,7,11,15} -> 2*, bo *{2,15} {3,7} {5,11}* albo *{2,15} {3,11} {5,7}*
