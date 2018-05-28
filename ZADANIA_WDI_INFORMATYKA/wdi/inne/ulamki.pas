program fractions;
	
uses crt,linux;

type
	frac = record
		numer,denom:integer;
	end;

{ greatest common factor - najwiekszy wspolny dzielnik }
function gcf(a,b: integer): integer;
var
	c:integer;
begin        
	while b <> 0 do begin
    	c:=a mod b;        
        a:=b;
        b:=c;
	end;
    gcf:=a;
end;

{ najmniejsza wspolna wielokrotnosc }
function lcm(a,b:integer):integer;
begin
	b:=b div gcf(a,b);
	lcm:=a*b;
end;

{ odwracanie }
procedure inv(var a:frac);
var
	c:integer;
begin	
	c:=a.numer;
	a.numer:=a.denom;
	a.denom:=c;
end;

{ skracanie ulamkow }
procedure cut(var a:frac);
var
	d:integer;
begin
	d:=gcf(a.numer,a.denom);
	a.numer:=a.numer div d;
	a.denom:=a.denom div d;
	if a.denom<0 then begin
		a.denom:=a.denom*-1;
		a.numer:=a.numer*-1;
	end;
end;

{ dodawanie ulamkow }
function sum(var a,b: frac):frac;
begin
	sum.denom:=lcm(a.denom,b.denom);
	sum.numer:=(sum.denom div a.denom)*a.numer
	+(sum.denom div b.denom)*b.numer;
end;

{ dodawanie ulamkow }
function sub(var a,b: frac):frac;
begin
	sub.denom:=lcm(a.denom,b.denom);
	sub.numer:=(sub.denom div a.denom)*a.numer
	-(sub.denom div b.denom)*b.numer;
end;

function mul(var a,b:frac):frac;
begin
	mul.numer:=a.numer*b.numer;
	mul.denom:=a.denom*b.denom;
	cut(mul);
end;

function dvd(var a:frac;b:frac):frac;	{ nie mozna dac div :/ }
begin
	inv(b);
	dvd:=mul(a,b);
	if dvd.denom=0 then begin write('dzielenie przez 0!'); halt; end;
end;

{ wypisywanie ulamkow }
procedure wrt(var a:frac);
begin
	write(a.numer);
	if (a.denom<>1) and (a.numer<>0) then write('/',a.denom);
end;

{ czytanie }
function rdf:frac;
var
	s:string;
	i,n,er:integer;
	need_white,denom:Boolean;
begin
	rdf.denom:=1; 	{ domyslny mianownik }
	n:=1;
	er:=0;
	
	need_white:=false;	{ znaleziono juz poczatek liczby? }
	denom:=false;		{ szukanie mianownika? }
	
	readln(s);	{ no to jadziem! }
	
	{ przeskakujemy caly napis }
	for i:=1 to ord(s[0]) do begin	
		{ omijanie bialych znakow }
{		if (s[i]=' ') or (s[i]=#11) or (s[i]='/') then begin
			if need_white then begin	 potrzebujemy bialego znaku 
				need_white:=false;
				 znaleziono koniec liczby wiec ja kopiujemy 
				if denom then val(copy(s,n,i-n-1),rdf.denom,er)
				else begin
					val(copy(s,n,i-n),rdf.numer,er);
					denom:=true;			
				end;			
			end;
			continue;
		end;		
}
		{ sprawdzanie cyfr }
		if ((s[i]>='0') and (s[i]<='9')) or (s[i]='+') or (s[i]='-') then
		begin	{ hurra! mamy cyfre :) }
			{ brzydkie znaki w srodku liczby }
			if need_white and ((s[i]<#48) or (s[i]>#57)) then begin
				writeln('podales zly znak! ( ',s[i],' )');
				halt;			
			end;
			
			{ wlasnie znalezliszmy poczatek liczby }
			if not need_white then begin
				need_white:=true;	{ szukamy do "bialego znaku" }
				n:=i;
			end;
			continue;
			{ jezeli found=true i funkcja jest tutaj to znaczy ze nie
				wystapily bledy i jedziemy dalej }
		end;{ else begin
			writeln('podales zly znak! ( ',s[i],' )');
			halt;		
		end; }	
		
		if need_white then begin	{ potrzebujemy bialego znaku }
			need_white:=false;
			{ znaleziono koniec liczby wiec ja kopiujemy }
			if denom then val(copy(s,n,i-n-1),rdf.denom,er)
			else begin
				val(copy(s,n,i-n),rdf.numer,er);
				denom:=true;			
			end;			
		end;
	end; 
	
	{ to w razie tego jesli nie ma mianownika tzn jest 1 }
	if denom and not need_white then rdf.denom:=1;
	
	{ w przypadku kiedy liczba sie nie skonczyla musimy jeszcze skopiowac
		liczbe aktualnie szukana }
	if true then begin
		if denom then val(copy(s,n,ord(s[0])-n+1),rdf.denom,er)
		else val(copy(s,n,ord(s[0])-n+1),rdf.numer,er);
	end;
	
	cut(rdf);
end;


var
	a,b,c,d,e,f,w,w1,w2,x,y:frac;
	
begin
	writeln('Porgram rozwiazuje uklad rownan postaci:');
	writeln('Ax+By=C');
	writeln('Dx+Ey=F');
	writeln('Wspolczynniki podaj w kolejnosci alfabetycznej: ');
	
	a:=rdf;
	b:=rdf; 
	c:=rdf;
	d:=rdf; 
	e:=rdf; 
	f:=rdf;
	writeln('Mamy uklad postaci:');
	wrt(a); write('x '); if b.numer>=0 then write('+ '); wrt(b); write('y = '); wrt(c); writeln;
	wrt(d); write('x '); if e.numer>=0 then write('+ '); wrt(e); write('y = '); wrt(f); writeln;
	
	x:=mul(a,e);
	y:=mul(b,d);	
	w:=sub(x,y);
	
	x:=mul(c,e);
	y:=mul(b,f);
	w1:=sub(x,y);
	if w.numer=0 then begin
		if w1.numer=0 then writeln('Rownanie ma nieskonczenie wiele rozwiazan!')
		else writeln('Rownanie nie ma rozwiazan :(');
		halt;	
	end;
	
	x:=mul(a,f);
	y:=mul(c,b);
	w2:=sub(x,y);
	
	x:=dvd(w1,w);
	y:=dvd(w2,w);
	cut(x);
	cut(y);
	
	write('Wyniki: x=');
	wrt(x);
	write(' y=');
	wrt(y);
	writeln;
	readln;
	
end.
