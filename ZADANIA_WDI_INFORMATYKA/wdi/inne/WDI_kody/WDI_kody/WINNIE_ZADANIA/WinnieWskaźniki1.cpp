#include <iostream>

/* Dane s¹ deklaracje opisuj¹ce listê jednokierunkow¹:
type 
pwezel = ^wezel;
wezel = record
val: integer;
next: pwezel
end;
Proszê napisaæ procedurê, która w liœcie wskazywanej przez zmienna typu pwezel usuwa
powtarzaj¹ce siê elementy. Mo¿na za³o¿yæ, ¿e lista jest niepusta. */

struct wezel
{
  int val;
  wezel * next;
};

void DeleteDuplicates(wezel* list)
{
  
  for(wezel* p=list; p->next!=NULL; p=p->next)
  {
    for(wezel* q=p; q->next!=NULL; )
    {
      if(p->val==q->next->val)
      {
        wezel* tmp=q->next;
        q->next=tmp->next; // q->next->next
        delete tmp;
      }
      else q=q->next;
    }
  }
}

void DeleteAllTheSame(wezel* list)
{
  for(wezel* p=list; p->next!=NULL; )
  {
  bool Duplicated=false;        
    for(wezel* q=p->next; q->!=NULL; )
    {
      if(p->next->val==q->next->val)
      {
        Duplicated=true;    
        wezel* tmp=q->next;
        q->next=tmp->next; // q->next->next
        delete tmp;
      }
      else q=q->next;
    }
    if(Duplicated) 
    {
    wezel* tmp=p->next;
    p->next=tmp->next; // q->next->next
    delete tmp;
    }
    else p=p->next;
  }
}
