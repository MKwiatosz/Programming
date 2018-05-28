
/* Dane s� de?nicje opisuj�ce list� jednokierunkow�:
type 
pwezel = ^wezel;
wezel = record
nr: integer;
next: pwezel
end;
Pojedyncza, niepusta lista zako�czona jest cyklem. Prosz� napisa� funkcj�, kt�ra zwraca dla
danej listy ilo�� element�w w cyklu. Do funkcji nale�y przekaza� wska�nik na pocz�tek listy.
Mo�na za�o�y�, �e ilo�� element�w w li�cie nie przekracza 100 [Mo�na rozwa�y� tak�e
przypadek, kiedy nie znamy a priori ograniczenia ilo�ci element�w w li�cie]. */

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
