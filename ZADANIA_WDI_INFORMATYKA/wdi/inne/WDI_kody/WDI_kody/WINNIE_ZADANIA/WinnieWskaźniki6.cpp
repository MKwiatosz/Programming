

/* Dane s� deklaracje opisuj�ce list� jednokierunkow�:
type
pwezel = ^wezel;
wezel = record
val: integer;
next: pwezel
end;
Pojedyncza lista zawiera niepowtarzaj�ce si� liczby naturalne uporz�dkowane rosn�co. Prosz�
napisa� procedur�, kt�ra dwie niepuste listy wej�ciowe przekszta�ca w jedn� list� wynikow�
tak, �e elementy listy wynikowej stanowi� sum� mnogo�ciow� list wej�ciowych. Listy
wej�ciowe s� usuwane z pami�ci. */

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
