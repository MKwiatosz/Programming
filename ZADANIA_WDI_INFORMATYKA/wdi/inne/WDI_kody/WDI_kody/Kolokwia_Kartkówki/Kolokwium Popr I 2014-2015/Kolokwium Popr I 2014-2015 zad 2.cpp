/* Dana jest tablica booli N na N, która przyjmuje wartoœæ true w miejscu gdzie znajduje siê jakaœ figura
oraz false gdzie nie ma figury. Napisz funkcjê, która zwróci wartoœæ logiczn¹ odnoœnie tego czy skoczek z 0 wierszego i k'tej 
kolumny mo¿e dojœæ do N-1 wiersza.*/

const int N=10;
int jumps[8][2] = {
		{ -2, -1 },
		{ -2, 1 },
		{ -1, -2 },
		{ -1, 2 },
		{ 1, -2 },
		{ 1, 2 },
		{ 2, -1 },
		{ 2, 1 }
};
  
bool DFS(bool &T[N][N], int i, int j)
{
  if(i == N-1) return true;
  T[i][j] = true;
  // generuje wszystkie pary i1, j1 pól, do których skoczek mo¿e skoczyæ, ale nie s¹ zaznaczone na true (czyli nie zablokowane)  
  for(int p=0; p<8; p+=)
  {
    i1 = i + jumps[p][0];
	j1 = j + jumps[p][1];
    if(j1<N and j1>-1 and i1>-1 and i1<N and !T[i1][j1]) // sprawdza czy jest dobrze
      if(DFS(T, i1, j1)) return true;
  }
  T[i][j] = false;
  return false;
}
