/*2. Dany jest typ:
type
kwadrat = record
x1,x2,y1,y2 : integer;
end;
kwadraty = array [1..max] of kwadrat;
gdzie x1,x2,y1,y2 oznaczaj¹ proste ograniczaj¹ce kwadrat (x1<x2,y1<y2).
Proszê napisaæ funkcjê, która zwraca wartoœæ logiczn¹ true, jeœli danej tablicy mo¿na znaleŸæ 
13 nienachodz¹cych na siebie kwadratów, których suma pól jest równa 2012 i false 
w przeciwnym przypadku. */

bool separate(kwadrat &*T, int &*squares, int i) {

	for(int k = 0; k < 13 && squares[k] != -1; k++) 
	{
		if( t[k].y2<t[i].y1 or t[k].y1>t[i].y1 or t[k].x2<t[i].x1 or t[k].x1>t[i].x2)
        /* sprawdzanie czy któryœ z 4 punktów jest wewn¹trz obecnego kwadratu, 
        strasznie du¿o warunków, nie chce mi siê tego pisaæ	*/ 
        return false;
	}
	return true;	
}


bool search(kwadrat &*T, int &*squares, int squareNumber, int sum, int i) 
{
	if(squareNumber == 13 && sum == 2012) return true;

	for(; i < (N - 12 + squaresNumber), ++i) 
	{
		if(separate(T, squares, i))
		{
			int thisSum = abs(x2 - x1) * abs(y2 - y1);
			squares[squareNumber] = i;
			if(search(T, squares, squareNumber + 1, sum + thisSum, i + 1) return true;
			squares[squareNumber] = -1;
		}		
	}
	return false;
}

bool init (kwadrat &*T) {
	int squares[13];
	for(int k = 0; k < 13; k++) squares[i] = -1;
	return search(T, squares, 0, 0, 0);
}
