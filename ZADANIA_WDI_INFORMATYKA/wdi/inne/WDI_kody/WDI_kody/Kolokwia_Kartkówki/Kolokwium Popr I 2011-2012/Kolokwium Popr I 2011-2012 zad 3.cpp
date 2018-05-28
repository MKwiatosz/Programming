

/* Mamy 2 uporz¹dkowane listy jednokierunkowe. Napisz funkcjê, która zwróci wskaŸnik na ró¿nicê 
symetryczn¹ z obu list (czyli taki XOR). */

struct Node*
{
 int value;
 Node* next;
};

Node* XOR(Node *list1, Node *list2)
{ 
  Node* list=NULL, *last=NULL;
  Node* empty1=new Node;
  Node* empty2=new Node;
  empty1->next=list1;
  empty2->next=list2;
  
  for(Node *p=empty1; p->next!=NULL; )
  {
    bool usunieto=false;
    for(Node *q=empty2; q->next!=NULL; )
    {
      if(p->next->value==q->next->value)
      {
        if(q->next==list2)    
        {
          list2=q->next->next;  
           // if(q->next->next!=NULL) list2=q->next->next;
           // else list2=NULL;
        }
        flaga=true;
        Node* tmp=q->next;
        q=tmp->next;
        delete tmp;
      }
      else q=q->next;
    }
    if(usunieto)
    {
      while(p->next->value==p->next->next->value)
      {
        Node* tmp=p->next->next;
        p->next=tmp->next;
        delete tmp;
      }
      if(p->next==list1) 
      {
        list1=p->next->next;
      }
      Node* tmp=p->next;
      p=tmp->next;
      delete tmp;  
    }
    else p=p->next;
  }
  
  while(list1!=NULL and list2!=NULL) 
  {
    int a=list1->value;
    int b=list2->value;
 
    if(a<b)
    {
      Node* tmp=list1;
      list1=tmp->next;
    }
    if(a>b)
    {
      Node* tmp=list2;
      list2=tmp->next; 
    }
    if(last!=NULL) last->next=tmp;
    else list=tmp;
    last=tmp;
  }
  last->next= list2==NULL ? list1 : list2;
  return list;
}
