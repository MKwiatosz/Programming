/*1. Mamy tablicê [1..max,1..max]. Napisz funkcjê, która zwraca d³ugoœæ najd³u¿szego podci¹gu rosn¹cego 
znajduj¹cego siê w dowolnym (jednym) wierszu, którego wszystkie elementy s¹ ze sob¹ wzglêdnie 
pierwsze.*/

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
int PodciagRosnacy(int T[N][N])
{
  int max=0;
  int w;
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; )
    {
      int k;
      CoPrime=true;
      for(k=j; k<N-1 and t[i][k]<t[i][k+1] and CoPrime; k++)         
      {
        CoPrime=true;
        for(int p=j; p<=k; p++)
          if(NWD(t[i][k+1], t[i][p])!=1) CoPrime=false;   
      }
    //od indeksu j zaczyna sie ciag o dlugosci k-j+1
    if(max<k-j+1){ max=k-j+1, w=i}
    j=k+1;  
    }
  }
  return max;  
}
