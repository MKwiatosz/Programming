
/* 1. Mamy tablicê [1..max,1..max] of integer. Wyzeruj w niej wszystkie liczby które nie maj¹ w tablicy innej 
liczby, która powsta³aby poprzez przestawienie jej cyfr. (uwa¿aj¹c na 1000 i 0100 - nie dziala). */


const int N=100;

bool FineNumbers(int a, int b)
{
  int ra=0;
  int ta[10]={0,0,0,0,0,0,0,0,0,0};
  while(a>0)
  {
    ta[a%10]++;
    ra++;
    a/=10;
  }
  int rb=0;
  int tb[10]={0,0,0,0,0,0,0,0,0,0};
  while(b>0)
  {
    tb[b%10]++;
    rb++;
    b/=10;
  }
  if(ra!=rb) return false;
  for(int i=0; i<10; i++)
    if(ta[i]!=tb[i]) return false;          
  return true;
}

void ZerujemyTablice(int &t[N][N])
{
  bool r[N][N];  
  for(int i=0; i<N; i++)
  for(int j=0; j<N; j++)
    r[i][j]=false;
  for(int i=0; i<N; i++)
  for(int j=0; j<N; j++)
    for(int i1=0; i1<N; i1++)
    for(int j1=0; j1<N; j1++)    
      if(FineNumbers(t[i][j], t[i1][j1])) r[i][j]=true;
  int counter=0; // licznik zerowanych liczb
  for(int i=0; i<N; i++)
  for(int j=0; j<N; j++)
  if(!r[i][j])  // (!r[i][j]) - nie maj¹ takiej liczby | (r[i][j]) - maja taka liczbe
  { 
    t[i][j]=0; 
    counter++;
  }  
  return counter;
}
