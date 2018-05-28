
/* Dane s¹ definicje:
type 
pwezel = ^wezel;
wezel = record
val: integer;
next: pwezel
end;
Globalna zmienna typu pwezel wskazuje na listê cykliczn¹. Proszê napisaæ procedurê,
usuwaj¹c¹ nadmiarowe (tj. o powtarzaj¹cych siê wartoœciach) elementy z listy. Mo¿na za³o¿yæ,
¿e lista zawiera co najmniej 2 ró¿ne elementy. */

struct Node
{
  int val;
  Node* next;
};


  {
    {
      if(p->val=q->next->val)
      {
        Node* tmp=q->next;
        q->next=tmp->next;
        delete tmp;
      }
      else q=q->next;
    }    
}

int DeleteAllDuplicatedInCycle(Node* &list)  // usuwa wszystkie takie same
{

  for(Node* p=list; p->next!=list; )   // list wskazuje na pusty element pomocniczy
  {
    bool Duplicated=false;
    for(Node* q=p->next; q->next!=list; )
    {
      if(p->next->val==q->next->val)
      {
        Node* tmp=q->next;
        q->next=tmp->next;
        delete tmp;
        Duplicated=true;
      }
      else q=q->next;
    }    
    if(Duplicated)
    {      
      Node* tmp=p->next;
      p->next=tmp->next;
      delete tmp;
    }
    else p=p->next;
  }

}
