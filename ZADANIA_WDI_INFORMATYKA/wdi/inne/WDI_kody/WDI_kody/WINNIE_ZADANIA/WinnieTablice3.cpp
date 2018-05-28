/* Dane s� definicje:
const 
max1 = 100;
max2 = 200;
type
wiersz = array[1..max1] of integer;
tablica = array[1..max2] of wiersz;
Zak�adamy, �e zmienna typu tablica jest wype�niona przypadkowymi warto�ciami. Prosz�
napisa� funkcj�, kt�ra dla zmiennej typu tablica zwraca numer wiersza w kt�rym wyst�puje
najd�u�szy sp�jny fragment z�o�ony z liczb o tej samej warto�ci. W przypadku kilku
fragment�w o tej samej d�ugo�ci nale�y zwr�ci� pozycj� pierwszego z nich. */ 

int const N=10;
int const M=10;

int najdPodciag(int row[M])
{
  int max=0;  
  for(int i=0; i<M;)
  {
    int j=i+1;    
    while(j<M and row[i]==row[j])
      j++;
    if(j-i>max) max=j-i;
    i=j;
  }
  return max;
}

int solution(int t[N][M])
{
  int max=0;
  int k=0;  
  for(int i=0; i<N; i++)
  {    
    if(najdPodciag(t[i])>max) 
    {
      max=najdPodciag(t[i]);
      k=i;
    }  
  }
  return k;
}
#if 0
int k=0;
for(int i=0; i<N; i++)
{
  if(najdPodciag(t[i])>t[k] l=i;
}
#endif

int main()
{
}


       
    
