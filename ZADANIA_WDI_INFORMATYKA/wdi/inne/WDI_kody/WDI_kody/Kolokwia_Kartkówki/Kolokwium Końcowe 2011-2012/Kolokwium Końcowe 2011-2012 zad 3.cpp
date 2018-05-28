/*3.Mamy cykliczn� list� zawieraj�c� liczby ca�kowite. Ka�da pierwsza cyfra kolejnej liczby jest r�wna 
ostatniej cyfrze poprzedniej liczby.
np. 123 - 324 - 435 - 578 -> �a�cuch si� zap�tla
Napisz funkcj� wstawiaj�c� liczb� do listy. Liczba ma zast�pi� dwa ju� istniej�ce elementy cyklu.
dla przyk�adu tutaj, za (324 - 435) mo�na wstawi� 35
Funkcja powinna zwr�ci� warto�� logiczn� w zale�no�ci od tego czy pr�ba wstawiania zako�czy�a si� 
sukcesem*/

int abs(int a)
{
  return a>0 ? a : -a;
}

int FirstNumber(int a)  
{
  a=abs(a);
  int b;
  while(a>0)
  {
    b=a%10;
    a/=10;
  }
  return b;
}

int LastNumber(int a)
{
  return abs(a%10);
}

bool Wstaw(node* &list, int a)
{
  int firstN=FirstNumber(a);
  int lastN=LastNumber(a);
  node* p=list;
  
  while(p->next!=list)
  {
        if(FirstNumber(p->next->val)==firstN and lastN==LastNumber(p->next->next->val))
        {
          p->next->val=a;
          node* tmp=p->next->next;
          p->next->next=tmp->next;
          delete tmp;
          return true;
        }    
  p=p->next;
  }
  return false;  
}

  
