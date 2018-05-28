/*Zr�b funkcje, kt�ra z listy sk�adaj�cej si� z liczb ca�kowitych robi 2 listy sk�adaj�ce si� z
 liczb NATURALNYCH. Jedna lista do element�w parzystych, druga nieparzystych. 
 Pozosta�e elementy usun�� z listy wej�ciowej. Zachowa� wzgl�dn� kolejno�� element�w.*/

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
