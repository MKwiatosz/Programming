#include <iostream>


struct wezel
{
  int val;
  wezel * next;
};


void push(wezel* s, int a)  // STOS DODAJ
{
  wezel* pnowy=new wezel;
  (*pnowy).val=a;  // pnowy->val=a;
  (*pnowy).next=s;
  s=pnowy;  
}

int pop(wezel* s)  // STOS USUN
{
  wezel* pstary=s;
  s=(*s).next;
  int a=(*pstary).val;
  delete pstary;
  
  return a;
}

struct queue
{
    wezel *front;
    wezel *back;
};

void enqueue(queue* q, int a) // KOLEJKA - DODAJ
{
  wezel* nowy=new wezel;
  (*nowy).val=a;
  (*nowy).next=NULL;
  if((*q).back) (*(*q).back).next=nowy;
  else front=nowy;
  back=nowy;
}
void enqueue(queue* q, int a)  // KOLEJKA - DODAJ
{
  wezel* nowy=new wezel;
  nowy->val=a;
  nowy->next=NULL;
  if(q->back) q->back->next=nowy;
  else front=nowy;
  back=nowy;
}

int dequeue(queue* q) // KOLEJKA - USUN
{
  if(!front) throw "Kolejka pusta"; 
  
  wezel* nowy=q->front;
  q->front= q->front->next;
  if(q->front==NULL) q->back=NULL;
  int a=nowy->val;
  delete nowy; 
  return a;
}
