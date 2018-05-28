program generuj;
{ generuje wszystkie napisy, podzbiory z tablic }
	
const max=3;
type tab = array [1..max] of integer;

procedure sgen(i,o:string;n:byte);
begin
	if n<=length(i) then begin
		sgen(i,o,n+1);
		sgen(i,o+i[n],n+1);	
	end else writeln(o);
end;

procedure igen(var input:tab;var output:tab;n:integer);
var i:integer;
begin
	if n>max then begin
		for i:=1 to max do if output[i]<>0 then write(output[i]);
		writeln;
	end else begin
		{ generuj bez liczby }
		igen(input,output,n+1);
		output[n]:=input[n];
		igen(input,output,n+1);
		output[n]:=0;
	end;
end;

{ n- oznacza ilosc elementow permutacji czyli wywolanie poczatkowe to
	permutate(t,max);
}
procedure permutate(var t:tab;n:integer);
var i,j,temp:integer;
begin
	if n=0 then begin
		for i:=1 to max do write(t[i]);
		writeln;	
	end else
		{ bedzie en przesuniec }
		for i:=1 to n do begin
			permutate(t,n-1);
			{ przesuwane sa elementy od max-n+1 do max }
			temp:=t[max-n+1];
			for j:=max-n+1 to max-1 do t[j]:=t[j+1];
			t[max]:=temp;			
		end;
end;

var t,o:tab;
	i:integer;
begin
	for i:=1 to max do begin
		t[i]:=i;
	 	o[i]:=0;
	end;
	sgen('abc','',1);
	igen(t,o,1);
	writeln;
	permutate(t,max);
end.

