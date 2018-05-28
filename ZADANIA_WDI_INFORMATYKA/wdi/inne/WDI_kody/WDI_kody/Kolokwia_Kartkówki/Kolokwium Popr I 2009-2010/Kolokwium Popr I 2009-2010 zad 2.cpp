
/*Zad. 2 Dana jest tablica typu tab=array[1..n] of integer. Proszê napisaæ funkcjê, która znajdzie 
najmniejszy (w sensie liczebnoœci) podzbiór elementów tablicy, dla którego suma elementów jest 
równa sumie indeksów tych elementów. Do funkcji nale¿y przekazaæ tablicê, funkcja powinna 
zwróciæ sumê elementów znalezionego podzbioru. Na przyk³ad dla tablicy: [ 7, 3, 5, 11, 2 ] 
rozwi¹zaniem jest liczba 10.*/

int const N=100;

void Rek(int *t, bool *r, int N, int n, int k)  // jak to dokladnie dziala?
{
  if(n==0) 
  {
    int sumaInd=0, suma=0;    
    for(int i=0; i<N; i++)
      if(r[i])
      {
        sumaInd+=i;
        suma+=t[i];
      }
    if(sumaInd==suma)
    {
      for(int i=0; i<N; i++)
        if(r[i]) std::cout << i << ' ';
      return true;
    }
        
  }
  if(k>0)
  {
    r[n-1]=true;
    if( Rek(t, r, N, n-1, k-1) ) return true;
  }
  if(k<n)
  {
    r[n-1]=false;
    if( Rek(t, r, N, n-1, k) ) return true;  
  }
  return false;
}

int FunkcjaDziwna49(int t[N])  // *t
{
  bool r[N];  
  for(int k=1; k<N; k++)
    if( Rek(t, r, N, N, k) ) break;
}



void Rek(int &M, int &S, int *t, int p=0, int sum=0, int sumi=0, int k=0)
{
  if(p==N) // jesli jestem w lisciu rekursji to: 
  {
    if(k>0 and sum==sumi) // jest okej, wiec
    {
      M=k;  // zwracamy moc podzbioru
      S=sum; // i sume
    }
    else // jesli zle to
    {
      M=N+1; // ustawiam M na wartosc wieksza niz wszystkie mozliwe.
      S=0; // cokolwiek
    }
    return; // wychodze
  }
  int M1, M2, S1, S2; // wyniki wywolac rekurencyjnych
  Rek(M1, S1, t, p+1, sum, sumi, k); 
  Rek(M2, S2, t, p+1, sum+t[p], sumi+p, k+1);     
  
  M= (M1<M2)? M1 : M2; // minimalny pozdbior
  S= (M1<M2)? S1 : S2; // suma z minimalnego podzbioru
}
       
