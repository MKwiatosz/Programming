
/* Dane s¹ de?nicje opisuj¹ce listê jednokierunkow¹:
type 
pwezel = ^wezel;
wezel = record
nr: integer;
next: pwezel
end;
Pojedyncza, niepusta lista zakoñczona jest cyklem. Proszê napisaæ funkcjê, która zwraca dla
danej listy iloœæ elementów w cyklu. Do funkcji nale¿y przekazaæ wskaŸnik na pocz¹tek listy.
Mo¿na za³o¿yæ, ¿e iloœæ elementów w liœcie nie przekracza 100 [Mo¿na rozwa¿yæ tak¿e
przypadek, kiedy nie znamy a priori ograniczenia iloœci elementów w liœcie]. */

struct Node
{
  int nr;
  Node* next;
};


int CycleLength(Node* &list)
{
  Node* p=list, q=list;
  
  do
  {
    p=p->next;
    q=q->next->next;  
  }
  while(p!=q);
  int a=0;
  
  do
  {
    p=p->next;
    a++;
  }
  while(p!=q);  
  return a;
}
