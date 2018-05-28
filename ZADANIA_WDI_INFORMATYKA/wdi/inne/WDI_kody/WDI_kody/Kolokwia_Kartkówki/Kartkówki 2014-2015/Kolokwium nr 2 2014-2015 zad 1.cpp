
/* 1. Na szachownicy o wymiarach 201 wierszy i 201 kolumn umieszczamy 100 króli szachowych. Proszê napisaæ program, 
który wczytuje z klawiatury po³o¿enia 100 króli (wiersz, kolumna), odnajduje dwa króle jednakowo odleg³e od œrodka 
szachownicy i wypisuje ich pozycjê (wiersz, kolumna). W przypadku gdy ¿adna para króli nie spe³nia warunku program 
koñczy siê stosownym komunikatem. Odleg³oœæ króla od œrodka to liczba jego ruchów, które musi wykonaæ aby dotrzeæ 
do œrodka szachownicy.
Uwagi:
1. Król mo¿e przesun¹æ siê na dowolne z 8 s¹siednich pól
2. Mo¿na za³o¿yæ, ¿e dane wprowadzone z klawiatury bêd¹ poprawne
3. Licz¹c drogê króla zak³adamy, ¿e szachownica jest pusta */

int main()
{
  int X[100], Y[100], D[100];
  
  for(int i=0; i<100; i++)
  {
    std::cin >> X[i];
    std::cin >> Y[i];
    int dx=abs(X[i]-100);
    int dy=abs(Y[i]-100);
    D[i]= (dx>dy) ? dx : dy ;
  }
  
  for(int i=0; i<100; i++)
   for(int j=i+1; j<100; j++)
    if(D[i]==D[j])
    {
      std::cout << X[i] << "," << Y[i] << std::endl << X[j] << "," << Y[j] << std::endl;
      return 0;
    }
  std::cout << "Brak takowych kroli.";
  
  return 0;
}


