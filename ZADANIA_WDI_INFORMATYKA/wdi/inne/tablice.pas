program tablice;

const max1=10;
		max2=5;
	
type
	duza_t = array[1..max1,1..max1] of boolean;
	mala_t = array[1..max2,1..max2] of boolean;

{ rzeczona funkcja 
	wywolanie:
		szukaj(duza,mala);
}
function szukaj(var duza:duza_t; var mala:mala_t):boolean;

{ pomocnicza funkcja sprawdza czy mozna polozyc tablice w odpowiednim
	miejscu }
function check(x,y:integer):boolean;
var i,j,k:integer;
begin
	check:=false;
	if (x+max2<=max1) and (y+max2<=max1) then begin
		k:=0; { zero elem. pasuje }
		for i:=y to y+max2 do 
			for j:=x to x+max2 do
				if duza[x,y]=mala[x,y] then inc(k);
		check:=(k<max2*max2/2); { mniej niz polowa calej malej tablicy }
	end;
end;

var i,j:integer;
{ cialo glownej funckji }
begin
	szukaj:=false;
	for i:=1 to max1-max2 do
		for j:=1 to max1-max2 do
			if check(i,j) then szukaj:=true;
end;

begin

end.
