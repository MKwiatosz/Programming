/*2. Dany jest typ:
type
kwadrat = record
x1,x2,y1,y2 : integer;
end;
kwadraty = array [1..max] of kwadrat;
gdzie x1,x2,y1,y2 oznaczaj� proste ograniczaj�ce kwadrat (x1<x2,y1<y2).
Prosz� napisa� funkcj�, kt�ra zwraca warto�� logiczn� true, je�li danej tablicy mo�na znale�� 
13 nienachodz�cych na siebie kwadrat�w, kt�rych suma p�l jest r�wna 2012 i false 
w przeciwnym przypadku. */

bool separate(kwadrat &*T, int &*squares, int i) {

	for(int k = 0; k < 13 && squares[k] != -1; k++) 
	{
		if( t[k].y2<t[i].y1 or t[k].y1>t[i].y1 or t[k].x2<t[i].x1 or t[k].x1>t[i].x2)
        /* sprawdzanie czy kt�ry� z 4 punkt�w jest wewn�trz obecnego kwadratu, 
        strasznie du�o warunk�w, nie chce mi si� tego pisa�	*/ 
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
