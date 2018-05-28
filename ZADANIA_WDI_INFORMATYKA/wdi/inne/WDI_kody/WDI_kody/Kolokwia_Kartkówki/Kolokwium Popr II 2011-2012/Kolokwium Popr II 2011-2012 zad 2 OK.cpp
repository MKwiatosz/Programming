/*2. Dany jest typ:
type
kwadrat = record
x1,x2,y1,y2 : integer;
end;
kwadraty = array [1..max] of kwadrat;
gdzie x1,x2,y1,y2 oznaczaj¹ proste ograniczaj¹ce kwadrat (x1<x2,y1<y2).
Proszê napisaæ funkcjê, która zwraca wartoœæ logiczn¹ true, jeœli danej tablicy mo¿na znaleŸæ 
13 nienachodz¹cych na siebie kwadratów, których suma pól jest równa 2012 i false 
w przeciwnym przypadku. */

// WERSJA 1
bool NieNachodza(kwadrat k1, kwadrat k2) // sprawdzanie czy kwadraty nachodz¹ na siebie
{
  return (k1.x2<k2.x1 or k1.x1>k2.x2 or k1.y2<k2.y1 or k1.y1>k2.y2);
}

int Pole(kwadrat k) // liczenie Pola
{
  return (abs(k.x2-k.x1) * abs(k.y2-k.y1));
}

bool IsGood(kwadrat *t, bool *r)
{
  int ile=0;
  for(int i=0; i<N; i++)
    if(r[i]) ile++;
  if(ile!=13) return false;
  
  for(int i=0; i<N; i++)
  if(r[i])
   for(int j=i+1; j<N; j++)   
   if(r[j]) 
     if(!NieNachodza(t[i], t[j])) return false;
  
  int suma=0; 
  for(int i=0; i<N; i++)
  if(r[i])
    suma+=Pole(t[i]);
  if(suma!=2012) return false;
  
  return true;
} 

bool Rek(kwadrat *t, bool *r, int p)
{
  if(p==N)
    return IsGood(t, r);
  
  r[p]=false;  
  bool b1=Rek(t, r, p+1);
  r[p]=true;
  bool b2=Rek(t, r, p+1);
  
  return b1 or b2;
}


bool MojaFunkcja49(kwadrat *t)
{
  bool r[N];
  return Rek(t, r, 0);    
}


//WERSJA 2

bool IsGood(kwadrat *t, int *kwInd, int c)
{
  if(c!=13) return false;  
  int suma=0;  
  for(int i=0; i<13; i++)
    suma+=Pole(t[kwInd[i]]);
  if(suma!=2012) return false;
  
  for(int i=0; i<13; i++)
  for(int j=i+1; j<13; j++)
    if(!NieNachodza(t[kwInd[i]], t[kwInd[j]])) return false;
  return true;  
}

bool Rek(kwadrat *t, int p, int c, int *kwInd)
{
  if(c==13 or p==N) return IsGood(t, kwInd, int c);
  
  // c<13
  kwInd[c]=p;
  return Rek(t, p+1, c+1, kwInd) or Rek(t, p+1, c, kwInd);      
}


bool MojeFunkcja50(kwadrat *t)
{
  int kwInd[13];
  return Rek(t, 0, 0, kwInd);
}
