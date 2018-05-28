### 2016/2017 - Kartkówka 1 - Grupa B - Zad 1 - *środa, 9 listopada 2016*

Dane są ciągi `a_n`, `b_n` i `c_n` określone następująco:
```math
a_n = 1 dla n=1,2
b_n = 1 dla n=1,2,3
a_n = a_{n-1} + a_{n-2} dla n > 2
b_n = b_{n-1} + b_{n-2} + b_{n-3} dla n > 3
```
Wyrazy ciągu `c_n` są kolejnymi liczbami naturalnymi należącymi do ciągu `a_n` lub `b_n`.
Ciągi te przyjmują wartości:
```math
(a_n) = (1, 1, 2, 3, 5, 8, 13, 21, ...)
(b_n) = (1, 1, 1, 3, 5, 9, 17, 31, ...)
(c_n) = (1, 2, 3, 5, 8, 9, 13, 17, ...)
```
Proszę napisać program który wczytuje wprowadzoną z klawiatury liczbę naturalną `k` i wypisuje `k`-ty
wyraz ciągu `c_n`.
