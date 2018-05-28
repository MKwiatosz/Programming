
/*Zad. 1 Dana jest du¿a tablica typu tab=array[1..n] of integer. Proszê napisaæ funkcjê, która 
zwraca sumê cyfr elementów tablicy zapisanych w systemie o podstawie 7, których indeks nie jest 
liczb¹ pierwsz¹. Wskazówka: rozwa¿yæ metodê sita.*/

int const N=100;

int Suma7(int k)
{
  int suma=0;
  while(k!=0)
  {
    suma+=k%7;
    k/=7;
  }
  return suma;
}

int DziwnaFunkcja48(int t[N])
{
    
  bool IsNotPrime[N];
  for(int i=0; i<N; i++)
    IsNotPrime[i]=false;
  IsNotPrime[0]=true;
  IsNotPrime[1]=true;;
  for(int i=2; i<N; i++)
  {
    if(IsNotPrime[i]) continue;
    for(int j=2*i; j<N; j+=i)
      IsNotPrime[j]=true;
  }
  int suma=0;
  for(int i=0; i<N; i++)
    if(IsNotPrime[i])
      suma+=Suma7(t[i]);
 return suma;
}
