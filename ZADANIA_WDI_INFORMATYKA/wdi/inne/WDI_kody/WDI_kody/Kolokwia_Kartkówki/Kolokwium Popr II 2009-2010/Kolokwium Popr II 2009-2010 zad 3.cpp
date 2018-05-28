/* Zad. 3 Dany jest �a�cuch, zawieraj�cy liczby naturalne, zbudowany w oparciu o elementy typu:
pnode = ^ node;
node = record
val : integer;
next : pnode;
end;
Prosz� napisa� funkcj�, kt�ra rozdziela elementy �a�cucha wej�ciowego do 10 �a�cuch�w, wed�ug
ostatniej cyfry pola val. W drugim kroku powsta�e �a�cuchy nale�y po��czy� w jeden �a�cuch, kt�ry
jest posortowany niemalej�co wed�ug ostatniej cyfry. Do funkcji nale�y przekaza� wskazanie na
�a�cuch wej�ciowy, funkcja powinna zwr�ci� wskazanie na powsta�y �a�cuch.
Na przyk�ad dla �a�cucha:
2 -> 3 -> 5 ->7-> 10-> 11->23->13->17->24
�a�cuch wyj�ciowy mo�e wygl�da� nast�puj�co:
10 -> 11 -> 2 -> 13 -> 3 -> 24 -> 5 -> 17 -> 7 */
 
struct node
{
  int val;
  node* next;
};
 
int LastDigit(int a)
{
  return a%10;
}
 
node* RozdzielanieScalanie(node *&list)
{
  node* t[10];
  node* s[10];
  for(int i=0; i<10; i++) // tworz� wartowniki w tablicy �a�cuch�w
  {  
    t[i]=new node;
    t[i]->next=NULL;  
    s[i]=t[i];
  }
 
  while(list!=NULL)
  {    
    for(int i=0; i<10; i++)
    {  
      if((LastDigit(list->val)==i)
      {
        node* tmp=list;
        list=list->next;
        tmp->next=NULL;
        if(t[i]->next!=NULL) s[i]->next=tmp;
        else t[i]->next=tmp;
        s[i]=tmp;
      }
    }
  }
 
  node* list2=NULL;
  node* empty2=new node;
  node* p=empty2;
 
  for(int i=0; i<10; i++)
  {
    if(t[i]->next!=NULL)
    {
      node* tmp=t[i]->next;
      empty2->next=tmp;
      delete t[i];
      while(empty2->next!=NULL)
        empty2=empty2->next;
    }
  }
  list2=p->next;
  delete empty2;
  return list2
}
