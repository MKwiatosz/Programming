
/* 1. Na szachownicy o wymiarach 201 wierszy i 201 kolumn umieszczamy 100 kr�li szachowych. Prosz� napisa� program, 
kt�ry wczytuje z klawiatury po�o�enia 100 kr�li (wiersz, kolumna), odnajduje dwa kr�le jednakowo odleg�e od �rodka 
szachownicy i wypisuje ich pozycj� (wiersz, kolumna). W przypadku gdy �adna para kr�li nie spe�nia warunku program 
ko�czy si� stosownym komunikatem. Odleg�o�� kr�la od �rodka to liczba jego ruch�w, kt�re musi wykona� aby dotrze� 
do �rodka szachownicy.
Uwagi:
1. Kr�l mo�e przesun�� si� na dowolne z 8 s�siednich p�l
2. Mo�na za�o�y�, �e dane wprowadzone z klawiatury b�d� poprawne
3. Licz�c drog� kr�la zak�adamy, �e szachownica jest pusta */

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


