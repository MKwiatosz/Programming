
/*Dane s� deklaracje opisuj�ce list� jednokierunkow�:
type 
pwezel = ^wezel;
wezel = record
potega: integer;
wspolcz: integer;
next: pwezel
end;
Lista reprezentuje wielomian o wsp�czynnikach ca�kowitych. Elementy w li�cie u�o�one s�
wed�ug rosn�cych pot�g. Prosz� napisa� procedur� obliczaj�c� r�nic� dw�ch dowolnych wielomian�w. 
Wielomiany reprezentowane s� przez wy�ej opisane listy. Procedura powinna
zwraca� wska�nik do nowo utworzonej listy reprezentuj�cej wielomian wynikowy. Listy
wej�ciowe powinny pozosta� niezmienione.*/

struct Node
{
 int power;
 int coefficient;
 Node* next;
};

Node* PylonomialDifference(Node* list1, Node* list2)
{
  Node* list=NULL, * last=NULL;
  list=last;
  while(list1!=NULL and list2!=NULL)
  {
    int a=list1->power;
    int b=list2->power;
    Node* tmp=new Node;
    if(a>b)
    {
      tmp->power=list2->power;
      tmp->coefficient= -list2->coefficient;
      tmp->next=NULL;      
      last->next=tmp;
      last=last->next;
      list2=list2->next;       
    }
    if(a<b)
    {       
      tmp->power=list1->power;
      tmp->coefficient= list1->coefficient;
      tmp->next=NULL;      
      last->next=tmp;
      last=last->next;
      list1=list1->next;      
    }
    if(a==b)
    {
      tmp->power=a;
      tmp->coefficient= list1->coefficient-list2->coefficient;
      tmp->next=NULL;      
      last->next=tmp;
      last=last->next;
      list1=list1->next;
      list2=list2->next;
    }
    last=tmp;      
  }
  last->next = list2==NULL ? list1 : list2;
  return list;
}
