program kolejka;

{ zwroc uwage na elegancje tego wykonania! za value podstawiasz dowlny
	typ i masz kolejke jak w stl'u, dodatkowo jest prosta w obsludze
	i dodawanie i usuwanie elementow jest robione w czasie stalym! i 
	ze stala pamiecia! }

type 
	value = integer; { mozna podstawic cokolwiek i tylko raz podmienic }
	pnode = ^node;
	node = record
			val :value;
			next:pnode;
		end;
	queue = record
			last,first:pnode;	{ do first dodajemy a od last usuwamy, last->...->first}
		end;
		
procedure reset(var q:queue);
begin
	q.first:=nil;
	q.last:=nil;
end;

function empty(var q:queue):boolean;
begin	
	empty:=(q.first=nil) or (q.last=nil);
end;

{ usuwanie elementu z poczatku, tu mozna zwracac rekord jesli trzeba }
function pop(var q:queue):value;
var temp:pnode;
begin
	if not empty(q) then begin
		temp:=q.last;
		pop:=temp^.val;
		q.last:=q.last^.next;	
		dispose(temp);
		{ tylko jesli lista sie skasowala to wskaznik na pierwszy element
			 jest usuwany }
		if empty(q) then q.first:=nil;
	end else pop:=-1;
end;

{ dodawanie elementu na koniec }
procedure push(var q:queue;v:value);
var temp:pnode;
begin
	new(temp);
	temp^.val:=v;
	temp^.next:=nil;
	{ pusta kolejka }
	if empty(q) then begin
		{ last jest modyfikowany tylko wtedy kiedy kolejka byla pusta,
		w innym wypadku last pozostaje taki sam bo nic nie usuwamy }
		q.last:=temp;
		q.first:=temp;
	end else q.first^.next:=temp;	
end;

{ kasowanie kolejki }
procedure clear(var q:queue);
var temp,temp2:pnode;
begin
	temp:=q.last;
	while temp<>nil do begin
		temp2:=temp;
		temp:=temp^.next;
		dispose(temp2);
	end;
	reset(q);
end;

var q:queue;
begin
	reset(q);
	writeln(pop(q));	{ tez wyrzuca -1 co oznacza ze jednak istnieje 
								inicjalizacja wartosciami nil! :) }
	
	push(q,1);
	push(q,2);
	writeln(pop(q));
	writeln(pop(q));
	writeln(pop(q));	{ wyrzuci -1 }
end.
