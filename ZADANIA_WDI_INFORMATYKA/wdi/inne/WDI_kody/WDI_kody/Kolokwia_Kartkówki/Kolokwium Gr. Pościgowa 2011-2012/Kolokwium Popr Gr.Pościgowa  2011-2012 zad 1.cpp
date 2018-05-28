/*1. Dana jest tablica typu tab1 = array [1..100,1..100] of integer wype³niona liczbami naturalnymi. 
Proszê napisaæ procedurê, która wyznacza 100 najwiêkszych wartoœci wystêpuj¹cych w tablicy, z których ka¿de dwie 
s¹ wzglêdnie pierwsze. Procedura powinna sygnalizowaæ brak mo¿liwoœci wyznaczenia takich liczb.*/

int NWD(int a, int b)
{
  while(b!=0)
  {
    int tmp=b;
    b=a%b;
    a=tmp;
  }
  return a;
}

int const N=100;
void Max100(int t[N][N])
{
  int r[N];
  for(int i=0; i<N; i++)
    r[i]=-1;
  int k;  
  for(k=0; k<100; k++)
  {
    int max=-1;
    for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
        if(t[i][j]>max) max=t[i][j];
    if(max==-1) break;
    r[k]=max;
    for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
        if( t[i][j]!=-1 and NWD(t[i][j], max)!=1 )
          t[i][j]=-1;
  }
  if(k<100)
  { 
  std::cout << "FAIL - brak 100 takich liczb";
  return;  
  }
  for(int i=0; i<N; i++)
    std::cout << r[i] << ' ';
}
