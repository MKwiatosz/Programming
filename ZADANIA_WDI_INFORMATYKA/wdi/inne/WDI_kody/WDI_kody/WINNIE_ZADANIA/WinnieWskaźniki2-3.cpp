

/* Dane s¹ de?nicje opisuj¹ce listê dwukierunkow¹:
type 
pwezel = ^wezel;
wezel = record
next: pwezel;
prev: pwezel
end;
Dana jest zmienna globalna wskazuj¹ca na pocz¹tek listy. Proszê napisaæ procedurê, która
wstawia do powy¿szej listy nowy element typu wezel na n-t¹ pozycjê. Mo¿na za³o¿yæ, ¿e lista
posiada co najmniej n elementów. Do procedury nale¿y przekazaæ: wskaŸnik na pocz¹tek listy,
wstawiany element oraz pozycjê, na której nale¿y wstawiæ nowy element. */

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

/* Dane s¹ de?nicje opisuj¹ce listê dwukierunkow¹:
type 
pwezel = ^wezel;
wezel = record
next: pwezel;
prev: pwezel
end;
Dana jest zmienna globalna wskazuj¹ca na pocz¹tek listy. Proszê napisaæ procedurê, która z
powy¿szej listy usuwa z n-ty element, je¿eli lista posiada co najmniej n elementów; je¿eli lista
posiada mniej ni¿ n elementów procedura nie robi nic. Do procedury nale¿y przekazaæ
wskaŸnik na pocz¹tek listy oraz numer elementu do usuniêcia. */

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
