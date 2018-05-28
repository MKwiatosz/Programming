
/* Dane s¹ dwie tablice mog¹ce pomieœciæ tak¹ sam¹ liczbê elementów:
 int t1[N][N];
 int t2[M]; // M = N*N
W ka¿dym wierszu tablicy t1 znajduj¹ siê uporz¹dkowane niemalej¹co (w obrêbie wiersza) liczby
naturalne. Proszê napisaæ fragment programu przepisuj¹cy wszystkie liczby z tablicy t1 do t2, tak aby
liczby w tablicy t2 by³y uporz¹dkowane niemalej¹co.*/



void przepisz(int t1[N][N], int t2[N*N])
{
  for(int i=0; i<N*N; i++) // przepisuje do docelowej tablicy t2 znalezion¹ wartoœæ
  {
    // szukam najmniejszej wartosci w t1
    int min_index=-1;
    for(int j=0; j<N; j++)
    {
      if(t1[j][0]!=-1)  // sprawdzam czy pole nie puste
        if( min_index==-1 or t1[j][0]<t1[min_index][0]) //
          min_index=j;
    }
    t2[i]=t1[min_index][0];
    for(int j=1; j<N ;j++)
      t1[min_index][j-1]=t1[min_index][j];
    t1[min_index][N-1]=-1;
  }
}


