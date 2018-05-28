program big_int;

const max=40;

type 
	digits = 0..9;
	number = array[0..max] of digits;	{ zero przechowuje dlugosc }
	
procedure init(var n:number);
var i:integer;
begin
	for i:=1 to max do n[i]:=0;
	n[0]:=1;
end;

procedure print(var n:number);
var i:integer;
begin	
	for i:=n[0] downto 1 do write(n[i]);
end;


function add(var l,r:number):number;
var
	v,sm,i,mem:integer;
	bigger,smaller:^number;
begin
	if l[0]>r[0] then begin
		bigger:=@l;
		smaller:=@r
	end else begin
		bigger:=@l;
		smaller:=@r;	
	end;
	
	mem:=0;
	add[0]:=bigger^[0];
	for i:=1 to bigger^[0] do begin
		if i>smaller^[0] then sm:=0
		else sm:=smaller^[i];
		v:=sm+bigger^[i]+mem;
		add[i]:=v mod 10;
		mem:=v div 10;
	end;
	
	if mem>0 then begin
		inc(add[0]);
		if add[0]>max then begin
			writeln('poza zakresem');
			halt;		
		end else add[add[0]]:=mem;	
	end
end;


var a,b,c:number;
begin
	init(a);
	init(b); 
	init(c);
	
	b[0]:=3;
	b[1]:=5;
	b[2]:=1;
	b[3]:=2;
	
	c[0]:=1;
	c[1]:=7;
	
	a:=add(b,c);
	print(a);
end.
