/* 3. Dane s¹ dwa niepuste ³añcuchy odsy³aczowe [jednokierunkowe] przechowuj¹ce liczby naturalne. 
W pierwszym liczby s¹ uporz¹dkowane rosn¹co, a w drugim malej¹co. Proszê napisaæ odpowiednie definicje typów 
oraz funkcjê scalaj¹c¹ takie dwa ³añcuchy w jeden zawieraj¹cy posortowane rosn¹co elementy. 
Funkcja powinna zwróciæ wskaŸnik do nowego ³añcucha.*/

struct node
{
  int val;
  node* next;
};

node* Scalanie(node* &list1, node* &list2) // list1 - rosn¹ca , list2 - malej¹ca.
{
  node* p=NULL;
  node* q=NULL;
  while(list2!=NULL) // odwrócenie listy malej¹cej
  {
    p=list2;
    list2=list2->next;
    p->next=q;
    q=p;
  }
  list2=q; // lista odwrócona
  node* list=NULL, *last=NULL;
  
  while(list1!=NULL and list2!=NULL)
  {
    int a=list1->val;
    int b=list2->val;
    
    if(a<b)
    {
      node* tmp=list1;
      list1=list1->next;
      tmp->next=NULL;
      if(last!=NULL) last->next=tmp;
      else list=tmp;
      last=tmp;
    }
    if(a>b)
    {
      node* tmp=list2;
      list2=list2->next;
      tmp->next=NULL;
      if(last!=NULL) last->next=tmp;
      else list=tmp;
      last=tmp;
        
    }
    if(a==b)
    {
      node* tmp=list1;
      list1=list1->next;
      tmp->next=NULL;
      if(last!=NULL) last->next=tmp;
      else list=tmp;
      last=tmp;
      node* tmp2=list2;
      list2=list2->next;
      delete tmp2;
    }
    last->next= list2==NULL ? list1 : list2;
  }
  list1=NULL;
  list2=NULL;
  return list;
}
