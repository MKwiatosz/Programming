/*
By MF57 - jest na zmiennych globalnych, jak siê komus chce poprawic, to droga wolna ;)
*/
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

struct node
{
	node *next;
	int dana;	
};

//srand(static_cast<unsigned>(time(NULL)));

node *p = NULL;
node *r = NULL;
node *q = NULL;
node *s = NULL;
node *first = NULL;
node *first1 = NULL;

void utworz(int n)
{
	for(int i = n; i > 0; i--)
	{
		r = new node;
		q = new node;
		r->dana = i;
		q->dana = 3*i;
		r->next = p;
		q->next = s;
		p = r;
		s = q;
	}
	first = r;
	first1 = q;
}

void wyswietl()
{
	p=NULL;
	r=first;
	while(r!=NULL)
	{
		cout << r->dana << ' ';
		r=r->next;
	}
}
void dodaj_na_koniec(int n)
{
	p=NULL;
	r=first;
	while(r!=NULL)
	{
		p=r;
		r=r->next;
	}
	if(p!=NULL)
	{
		r = new node;
		r->dana = n;
		r->next=NULL;
		p->next=r;
	}
	else
	{
		first= new node;
		first->next = NULL;
		first->dana = n;
	}
}

void dodaj_na_poczatek(int n)
{
	p=first;
	first = new node;
	first->dana=n;
	first->next=p;
}

void usun_z_pocz()
{
	p = first;
	if(p!=NULL)
	{
		first=p->next;
		delete p;
	}
	else
	{
		cout << "Lancuch jest pusty!";
	}
}

void usun_z_konca()
{
	p=NULL;
	q=NULL;
	r=first;
	while(r!=NULL)
	{
		q=p;
		p=r;
		r=r->next;
	}
	if(p!=NULL && q!=NULL)
	{	
		q->next=NULL;
		delete p;
	}
	if(p==NULL)
	{
		cout << "Lancuch jest pusty";
	}
	if(p!=NULL&&q==NULL)usun_z_pocz();
}

void dodaj_w_srodek(int gdzie, int n)
{
	p=NULL;
	q=NULL;
	r=first;
	while(gdzie>0 && r!=NULL)
	{
		p=r;
		r=r->next;
		gdzie--;
	}
	if(r==NULL)dodaj_na_koniec(n);
	else
	{
		q=new node;
		q->dana=n;
		p->next=q;
		q->next=r;
	}
}

void usun_ze_srodka(int skad)
{
	p=NULL;
	r=first;
	while(skad>0 && r!=NULL)
	{
		p=r;
		r=r->next;
		skad--;
	}
	if(r==NULL)usun_z_konca();
	else
	{
		p->next=r->next;
		delete r;
	}
}

void polacz_listy()
{
	p=NULL;
	r=first;
	while(r!=NULL)
	{
		p=r;
		r=r->next;
	}
	if(p!=NULL)
	{
		p->next=first1;
	}
	else
	{
		first=first1;
	}
}
void usun_parzyste()
{
	p=NULL;
	q=NULL;
	r=first;
	while(r!=NULL)
	{
		if(r!=NULL && r->dana%2==0)
		{
			if(p!=NULL)
			{
				q=r;
				r=r->next;
				p->next=r;
				delete q;
			}
			else
			{
				q=r;
				r=r->next;
				first = r;
				delete q;
			}
		}
		else
		{
			p=r;
			r=r->next;
		}
	}
}

void odwroc()
{
	p=NULL;
	q=NULL;
  if(first!=NULL)
  {
    q = first;
    while(q->next)
    {
      p = q->next;
      q->next = p->next;
      p->next = first;
      first = p;
    }
  }
	
}

void usun()
{
	while(first!=NULL)usun_z_pocz();
}
		

int main()
{
	int n;
	cout << "Jak dluga ma byc lancuch: ";
	cin >> n;
	utworz(n);
	wyswietl();
	dodaj_na_koniec(6);
	cout << endl;
	wyswietl();
	dodaj_na_poczatek(0);
	cout << endl;
	wyswietl();
	usun_z_pocz();
	cout << endl;
	wyswietl();
	usun_z_konca();
	cout << endl;
	wyswietl();
	dodaj_w_srodek(3, 12);
	cout << endl;
	wyswietl();
	usun_ze_srodka(3);
	cout << endl;
	wyswietl();
	polacz_listy();
	cout << endl;
	wyswietl();
	usun_parzyste();
	cout << endl;
	wyswietl();
	odwroc();
	cout << endl;
	wyswietl();
	usun();
	cout << endl;
	wyswietl();
}
