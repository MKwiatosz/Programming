

/* Dane s� de?nicje opisuj�ce list� dwukierunkow�:
type 
pwezel = ^wezel;
wezel = record
next: pwezel;
prev: pwezel
end;
Dana jest zmienna globalna wskazuj�ca na pocz�tek listy. Prosz� napisa� procedur�, kt�ra
wstawia do powy�szej listy nowy element typu wezel na n-t� pozycj�. Mo�na za�o�y�, �e lista
posiada co najmniej n element�w. Do procedury nale�y przekaza�: wska�nik na pocz�tek listy,
wstawiany element oraz pozycj�, na kt�rej nale�y wstawi� nowy element. */

struct Node
{
  int val;
  Node* next;
  Node* prev;
};

void Insert(Node* &list, int n, int a)
{
  Node* p=list;  
  for(int i=0; i<n; i++)
    p=p->next;
  Node* nowy=new Node;
  nowy->val=a;
  nowy->next=p;
  nowy->prev=p->prev;
  p->prev=nowy;
  if(nowy->prev!=NULL) nowy->prev->next=nowy;  // if(n==0) ... 
  else list=nowy;
}

/* Dane s� de?nicje opisuj�ce list� dwukierunkow�:
type 
pwezel = ^wezel;
wezel = record
next: pwezel;
prev: pwezel
end;
Dana jest zmienna globalna wskazuj�ca na pocz�tek listy. Prosz� napisa� procedur�, kt�ra z
powy�szej listy usuwa z n-ty element, je�eli lista posiada co najmniej n element�w; je�eli lista
posiada mniej ni� n element�w procedura nie robi nic. Do procedury nale�y przekaza�
wska�nik na pocz�tek listy oraz numer elementu do usuni�cia. */

void Delete(Node* &list, int n)
{
  Node* p=list;  
  for(int i=0; i<n and p!=NULL; i++)
    p=p->next;  
  if(p==NULL) return;
  if(p->prev!=NULL) p->prev->next=p->next;
  if(p->next!=NULL) p->next->prev=p->prev;
  delete p;
}  
