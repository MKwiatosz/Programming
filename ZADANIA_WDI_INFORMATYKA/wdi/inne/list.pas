program lancuch_odsylaczowy; { :P }

type
	list = ^node;
	node= record
			key:integer;
			next: list;
		end;

procedure display(l:list);
begin
	while l<>nil do begin
		write(l^.key,' ');
		l:=l^.next;
	end;
end;

{ dodaje na poczatek }
procedure add(var l:list;k:integer);
var temp:list;
begin
	new(temp);
	temp^.key:=k;
	temp^.next:=l;
	l:=temp;
end;

{ numerowanie od 1 do dlugosci listy, jesli n>dlugosc to na koniec }
procedure insert(var l:list;n:integer;k:integer);
var p,temp:list;
begin
	p:=nil;
	temp:=l;
	{ jesli podane jest jeden to znaczy ze dodajemy na poczatek, czyli 
		petla konczy sie od razu }
	while (temp<> nil) and (n>1) do begin
		dec(n);
		p:=temp;
		temp:=temp^.next;	
	end;
	add(temp,k);
	if p <> nil then p^.next:=temp
	else l:=temp;
end;

{ usuwa 1 }
procedure pop(var l:list);
var temp:list;
begin
	temp:=l;
	l:=l^.next;
	dispose(temp);
end;

procedure remove(var l:list;n:integer);
var p,temp:list;
begin
	p:=nil;
	temp:=l;
	while (temp^.next<> nil) and (n>1) do begin
		dec(n);
		p:=temp;
		temp:=temp^.next;	
	end;
	
	pop(temp);
	if p=nil then l:=temp
	else begin
		p^.next:=temp;	
	end;
end;

procedure clear(var l:list);
var temp:list;
begin
	while l<>nil do begin
		temp:=l;
		l:=l^.next;
		dispose(temp);
	end;
	l:=nil;
end;

var 
	l:list;
	i:integer;
begin
	l:=nil;
	for i:=0 to 10 do add(l,i);
	
	insert(l,1,20);
	insert(l,2,30);
	insert(l,5,40);
	insert(l,100,50);
	
	remove(l,1);
	remove(l,2);
	remove(l,200);
	
	display(l);
	clear(l);
	display(l);
end.
