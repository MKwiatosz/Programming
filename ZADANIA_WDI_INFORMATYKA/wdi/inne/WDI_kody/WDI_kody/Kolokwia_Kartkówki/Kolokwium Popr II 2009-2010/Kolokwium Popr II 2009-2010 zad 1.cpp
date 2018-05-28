/* Zad. 1 Dana jest du¿a tablica typu tab=array [1..max, 1..max] of integer wype³niona liczbami 
naturalnymi. Proszê napisaæ funkcjê, która sprawdza czy w tablicy istniej¹ dwa elementy odleg³e o 
jeden ruch skoczka szachowego, których wartoœci s¹ liczbami wzglêdnie pierwszymi. */

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

bool Check(int t[N][N])
{
  int ruchy[8][2]={
		  { -2, -1 },
	   	  { -2, 1 },
		  { -1, -2 },
		  { -1, 2 },
		  { 1, -2 },
		  { 1, 2 },
		  { 2, -1 },
		  { 2, 1 }
  };
  
  for(int i=0; i<N; i++)
  for(int j=0; j<N; j++)
  for(int p=0; p<8; p++)
  {
    int i1=i + ruchy[p][0];
    int j1=j + ruchy[p][1];
    if(i1<N and i1>-1 and j1<N and j1>-1 and NWD(t[i][j], t[i1][j1])==1) return true;
  }
  return false;
}
