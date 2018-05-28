/*Proszê napisaæ procedurê rozdzielaj¹c¹ ³añcuch na 2 ³añcuchy wed³ug klucza, w taki sposób, 
¿e w pierwszym ³añcuchu znajd¹ siê liczby, które s¹ wielokrotnoœci¹ kwadratu
 liczby pierwszej, a w drugim pozosta³e.*/

struct node
{
  int klucz;
  node* next;
};

bool Wielekrotnosc(int a)
{
  if(a<2) return false;
  int i=2;
  while(i*i<a)
  {
    if(a%i==0)
    {
      int b=a/i;
      if(b%i==0) 
      {
        bool Prime=true; 
        for(int j=2; j*j<i and Prime; j++)
        { 
          if(i%j==0) Prime=false;
        }
        if(Prime) return true;  
      }
    }
    i++;
  }
  return false;
}

void Podzial(node* &list)
{
  node *list1=NULL, *last1=NULL, *list2=NULL, *last2=NULL;
  
  while(list!=NULL)
  {
    node* tmp=list;
    list=list->next;
    tmp->next=NULL;
 
    if(Wielokrotnosc(tmp->klucz))
    {
      if(last1!=NULL) last1->next=tmp;
      else list1=tmp;
      last1=tmp;
    }
    else
    {  
      if(last2!=NULL) last2->next=tmp;
      else list2=tmp;
      last2=tmp;
    }
  }
}
