/* 3. Dane s� dwa niepuste �a�cuchy odsy�aczowe [jednokierunkowe] przechowuj�ce liczby naturalne. 
W pierwszym liczby s� uporz�dkowane rosn�co, a w drugim malej�co. Prosz� napisa� odpowiednie definicje typ�w 
oraz funkcj� scalaj�c� takie dwa �a�cuchy w jeden zawieraj�cy posortowane rosn�co elementy. 
Funkcja powinna zwr�ci� wska�nik do nowego �a�cucha.*/

struct node
{
  int val;
  node* next;
};

node* Scalanie(node* &list1, node* &list2) // list1 - rosn�ca , list2 - malej�ca.
{
  node* p=NULL;
  node* q=NULL;
  while(list2!=NULL) // odwr�cenie listy malej�cej
  {
    p=list2;
    list2=list2->next;
    p->next=q;
    q=p;
  }
  list2=q; // lista odwr�cona
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
