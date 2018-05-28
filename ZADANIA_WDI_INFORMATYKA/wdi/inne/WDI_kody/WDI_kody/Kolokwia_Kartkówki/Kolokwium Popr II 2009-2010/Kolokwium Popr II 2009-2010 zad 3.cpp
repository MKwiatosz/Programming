/* Zad. 3 Dany jest ³añcuch, zawieraj¹cy liczby naturalne, zbudowany w oparciu o elementy typu:
pnode = ^ node;
node = record
val : integer;
next : pnode;
end;
Proszê napisaæ funkcjê, która rozdziela elementy ³añcucha wejœciowego do 10 ³añcuchów, wed³ug
ostatniej cyfry pola val. W drugim kroku powsta³e ³añcuchy nale¿y po³¹czyæ w jeden ³añcuch, który
jest posortowany niemalej¹co wed³ug ostatniej cyfry. Do funkcji nale¿y przekazaæ wskazanie na
³añcuch wejœciowy, funkcja powinna zwróciæ wskazanie na powsta³y ³añcuch.
Na przyk³ad dla ³añcucha:
2 -> 3 -> 5 ->7-> 10-> 11->23->13->17->24
£añcuch wyjœciowy mo¿e wygl¹daæ nastêpuj¹co:
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
  for(int i=0; i<10; i++) // tworzê wartowniki w tablicy ³añcuchów
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
