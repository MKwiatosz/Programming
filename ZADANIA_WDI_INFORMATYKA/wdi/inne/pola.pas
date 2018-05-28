program pola;

const max=10;
type tab = array[1..max,1..max] of integer;
function sprawdz(var t:tab):integer;

{ sprawdza czy liczba jest pierwsza }
function pierwsza(n:integer):boolean;
var i:integer;
begin
	pierwsza:=true;
	if odd(n) then begin
		i:=3;
		while i<=sqrt(n) do begin
			if n mod i = 0 then begin
				pierwsza:=false;
				break;
			end;
			inc(i,2);
		end;
	end else pierwsza:=false;
end;

{ x i y wspolrzedna pola, pola liczone sa od zara! }
function przepelnione(x,y:integer):boolean;
var i,j,k:integer;
begin
	k:=0;
	for i:=x*10+1 to 10*(x+1) do 
		for j:=y*10+1 to 10*(y+1) do if pierwsza(t[i,j]) then inc(k);
	przepelnione:=k>50;
end;

var x,y,k:integer;
begin
	k:=0;
	for x:=0 to 9 do 
		for y:=0 to 9 do
			if przepelnione(x,y) then inc(k);
	sprawdz:=k;
end;

begin
	writeln(not odd(2));
end.
