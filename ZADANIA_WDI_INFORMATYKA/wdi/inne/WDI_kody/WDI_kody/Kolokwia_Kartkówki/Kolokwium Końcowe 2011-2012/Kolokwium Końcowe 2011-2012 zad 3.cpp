/*3.Mamy cykliczn¹ listê zawieraj¹c¹ liczby ca³kowite. Ka¿da pierwsza cyfra kolejnej liczby jest równa 
ostatniej cyfrze poprzedniej liczby.
np. 123 - 324 - 435 - 578 -> ³añcuch siê zapêtla
Napisz funkcjê wstawiaj¹c¹ liczbê do listy. Liczba ma zast¹piæ dwa ju¿ istniej¹ce elementy cyklu.
dla przyk³adu tutaj, za (324 - 435) mo¿na wstawiæ 35
Funkcja powinna zwróciæ wartoœæ logiczn¹ w zale¿noœci od tego czy próba wstawiania zakoñczy³a siê 
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

  
