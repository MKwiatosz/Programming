

/*Dane s� deklaracje opisuj�ce list� jednokierunkow�:
type 
pwezel = ^wezel;
wezel = record
next: pwezel
end;
Prosz� napisa� procedur�, kt�ra w li�cie wskazywanej przez zmienn� typu pwezel odwraca
kolejno�� jej element�w. Mo�na za�o�y�, �e lista jest niepusta.*/

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
