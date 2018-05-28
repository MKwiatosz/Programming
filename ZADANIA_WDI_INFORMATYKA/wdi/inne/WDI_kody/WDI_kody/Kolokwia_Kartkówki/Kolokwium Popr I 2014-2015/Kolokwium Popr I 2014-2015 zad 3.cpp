/*Zrób funkcje, która z listy sk³adaj¹cej siê z liczb ca³kowitych robi 2 listy sk³adaj¹ce siê z
 liczb NATURALNYCH. Jedna lista do elementów parzystych, druga nieparzystych. 
 Pozosta³e elementy usun¹æ z listy wejœciowej. Zachowaæ wzglêdn¹ kolejnoœæ elementów.*/

void Lista(node* &list)
{
  node* listP=NULL;
  node* listNP=NULL;
  node* lastP=NULL;
  node* lastNP=NULL;
  node* empty=new node; // wartownik na poczatku
  empty->next=list;
  
  for(node* p=empty; p->next!=NULL; )
  {
    int a=p->next->val;
    
  
    if(a<=0)
    {
      node* tmp=p->next;  
      p->next=tmp->next;  // element przed list przepinam na element po list
      delete tmp;       
    }
    if(a>0 and a%2==0)
    {
      node* tmp=new node;
      tmp->val=a;
      tmp->next=NULL;
      if(lastP!=NULL) lastP->next=tmp;
      else listP=tmp;
      lastP=tmp;
      p=p->next;
    }
    if(a>0 and a%2==1)
    {
      node* tmp=new node;
      tmp->val=a;
      tmp->next=NULL;
      if(lastNP!=NULL) lastNP->next=tmp;
      else listNP=tmp;
      lastNP=tmp;
      p=p->next;
    }
  }
  list=empty->next;
  delete empty;
}
