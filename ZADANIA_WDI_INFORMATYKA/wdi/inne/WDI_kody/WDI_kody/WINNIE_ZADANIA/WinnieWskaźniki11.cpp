

/*Dane s¹ deklaracje opisuj¹ce listê jednokierunkow¹:
type 
pwezel = ^wezel;
wezel = record
next: pwezel
end;
Proszê napisaæ procedurê, która w liœcie wskazywanej przez zmienn¹ typu pwezel odwraca
kolejnoœæ jej elementów. Mo¿na za³o¿yæ, ¿e lista jest niepusta.*/

struct Node
{
  Node* next;
};


void ListInversion(Node* &list)
{
  Node *p=NULL;
  Node *q=NULL;
  
  while(list!=NULL)
  {
    p=list;
    list=list->next;
    p->next=q;
    q=p;
  }
  list=q; 
  return list;
}
