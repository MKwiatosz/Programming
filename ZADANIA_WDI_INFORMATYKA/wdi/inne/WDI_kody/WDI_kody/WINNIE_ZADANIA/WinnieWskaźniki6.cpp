

/* Dane s¹ deklaracje opisuj¹ce listê jednokierunkow¹:
type
pwezel = ^wezel;
wezel = record
val: integer;
next: pwezel
end;
Pojedyncza lista zawiera niepowtarzaj¹ce siê liczby naturalne uporz¹dkowane rosn¹co. Proszê
napisaæ procedurê, która dwie niepuste listy wejœciowe przekszta³ca w jedn¹ listê wynikow¹
tak, ¿e elementy listy wynikowej stanowi¹ sumê mnogoœciow¹ list wejœciowych. Listy
wejœciowe s¹ usuwane z pamiêci. */

struct Node
{
  int val;
  Node* next;
};

Node* MergeList(Node* &list1, Node* &list2)
{
  Node* list, * last;
  list=new Node;
  last=list;
  while(list1!=NULL and list2!=NULL)
  {
    int a=list1->val;
    int b=list2->val;
    
    if(a<b) 
    {
      Node* tmp=list1;
      list1=tmp->next;
      last->next=tmp;
      last=last->next; // =tmp
    }
    if(a>b)
    {
      Node* tmp=list2;
      list2=tmp->next;
      last->next=tmp;
      last=last->next; // =tmp
    }
    if(a==b)
    {
      Node* tmp=list1;
      list1=tmp->next;
      Node* tmp2=list2;
      list2=tmp2->next;
      delete tmp2;
      last->next=tmp;
      last=last->next; // =tmp
    }    
  }
  last->next= list2==NULL ? list1 : list2;    
  Node* tmp=list;
  list=tmp->next;
  delete tmp;
  list1=NULL;
  list2=NULL;
  return list;
}
