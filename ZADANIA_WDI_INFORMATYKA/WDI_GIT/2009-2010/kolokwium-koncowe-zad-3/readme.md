### 2009/2010 - Kolokwium końcowe - Zad. 3

Dany jest łańcuch zbudowany w oparciu o elementy typu:

(Pascal)
```
pnode = ^ node;
node = record
    val : integer;
    next : pnode;
end;
```
(C/C++)
```
struct Node {
    int val;
    Node* next;
};
```
Kolejne elementy łańcucha o zwiększającej się wartości pola  `val` nazywamy podłańcuchem rosnącym.

Proszę napisać procedurę, która usuwa z łańcucha wejściowego najdłuższy podłańcuch rosnący. Warunkiem usunięcia jest istnienie w łańcuchu dokładnie jednego najdłuższego podłańcucha rosnącego.
