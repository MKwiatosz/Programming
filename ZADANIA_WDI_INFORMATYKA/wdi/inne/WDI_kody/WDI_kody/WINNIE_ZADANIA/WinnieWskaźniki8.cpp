
/*Dane s� definicje:
const 
max = 500;
type
tablica = array[1..max, 1..max] of integer;
W zmiennych typu tablica wi�kszo�� (np. 95%) element�w jest r�wna 0. Prosz� zaproponowa�
struktur� dynamiczn� (wska�nikow�) przechowuj�c� w spos�b efektywny (pod wzgl�dem
wykorzystania pami�ci) zawarto�� zmiennej typu tablica.
Prosz� napisa� procedur� przekszta�caj�c� zmienn� typu tablica na zaproponowan�
struktur�;
Prosz� napisa� funkcj�, kt�ra korzystaj�c z zaproponowanej struktury zwraca warto��
wybranego elementu (okre�lonego przez par� indeks�w (i, j)).*/

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
