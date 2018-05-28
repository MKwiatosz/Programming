
/*Dane s¹ definicje:
const 
max = 500;
type
tablica = array[1..max, 1..max] of integer;
W zmiennych typu tablica wiêkszoœæ (np. 95%) elementów jest równa 0. Proszê zaproponowaæ
strukturê dynamiczn¹ (wskaŸnikow¹) przechowuj¹c¹ w sposób efektywny (pod wzglêdem
wykorzystania pamiêci) zawartoœæ zmiennej typu tablica.
Proszê napisaæ procedurê przekszta³caj¹c¹ zmienn¹ typu tablica na zaproponowan¹
strukturê;
Proszê napisaæ funkcjê, która korzystaj¹c z zaproponowanej struktury zwraca wartoœæ
wybranego elementu (okreœlonego przez parê indeksów (i, j)).*/

const int N=500;
struct Node 
{
  int i;
  int j;
  int a;
  Node* next;
};

Node* Convert(int t[N][N])
{
  Node* list=NULL;
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      if(t[i][j]!=0) 
      {
        Node* tmp=new Node;
        tmp->i=i;
        tmp->j=j;
        tmp->a=t[i][j];
        tmp->next=list;
        list=tmp;
      }
  return list;
}

int GetValue(Node* list, int i, int j)
{
    for(Node* p=list; p!=NULL; p=p->next)
      if(p->i==i and p->j==j) return p->a;
    return 0;
}
