program sortowania;

const max=10;
type
	tab = array [1..max] of integer;

procedure print(var t:tab);
var i:integer;
begin
	for i:=1 to max do write(t[i],' ');
	writeln;
end;

procedure swap(var a,b,c:integer);
var temp:integer;
begin
	temp:=b;
	b:=a;
	a:=temp;
	inc(c);
end;

{ uwaga! wszedzie przekazuje tablice bez wara swiadomie bo chce ja wydrukowac
	za kazdym razem i miec po wyjsciu z funckji taka jaka dalem do funkcji! }
{ to jest banal }
procedure bublesort(t:tab);
var i,n,shift,comp:integer;
begin
	shift:=0;
	comp:=0;
	for n:=max-1 downto 1 do begin
		for i:=1 to n do begin
			if t[i]>t[i+1] then begin
				swap(t[i],t[i+1],shift);
			end;
			inc(comp);
		end;			
	end;
	print(t);
	writeln('przesuniec: ',shift,' porownan: ',comp);
end;

procedure selectionsort(t:tab);
var i,j,k,shift,comp:integer;
begin
	shift:=0;
	comp:=0;
	for i:=1 to max do begin
		k:=i;
		for j:=i+1 to max do begin
			if t[k]>t[j] then k:=j;
			inc(comp);
		end;
		swap(t[i],t[k],shift);
	end;
//	print(t);
	writeln('przesuniec: ',shift,' porownan: ',comp);
end;

procedure insertionsort(t:tab);
var i,j,k,shift,comp:integer;
begin
	shift:=0;
	comp:=0;
	for i:=2 to max do begin
		j:=i;
		k:=t[i];
		while (j>1) and (k<t[j-1]) do begin
			inc(comp);
			t[j]:=t[j-1];
			inc(shift);
			dec(j);
		end;
		t[j]:=k;
		inc(shift);
	end;
//	print(t);
	writeln('przesuniec ( podstawien ): ',shift,' porownan: ',comp);
end;

var i:integer;
	t:tab;
	comp,shift:integer;
procedure quicksort(var t:tab);
  procedure sortuj(l, p : integer);
  var i,j,x : integer;
  begin
    i := l; j := p;
    x := t[(l+p) div 2];
    repeat
      while t[i] < x do i := i+1;
      while t[j] > x do j := j-1;
      if i <= j then begin
      	swap(t[j],t[i],shift);
        i := i+1;
        j := j-1;
      end;
      inc(comp);
    until i > j;
    if l < j then sortuj(l, j);
    if i < p then sortuj(i, p);
  end;
begin
  sortuj(1, max);
end;


begin
	randomize;
	for i:=1 to max do t[i]:=random(10);
	print(t);
	writeln('bublesort');
	bublesort(t);	
	write('wybieranie ');
	selectionsort(t);
	write('wstawianie ');
	insertionsort(t);
	comp:=0; shift:=0;
	write('szybkie ');
	quicksort(t);
//	print(t);
	writeln('przesuniec: ',shift,' porownan: ',comp);	
end.
