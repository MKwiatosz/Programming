program stack;

type
	pnode = ^node;
	node = record
			w :integer;
			next : pnode;
		end;

procedure init(var stack: pnode); begin stack:=nil; end;

function empty(var stack:pnode): Boolean;
begin	empty:=(stack = nil); end;

procedure push(var stack:pnode;key:integer);
var temp: pnode;
begin
	new(temp);
	temp^.w:=key;
	temp^.next:=stack;
	stack:=temp;
end;

function pop(var stack:pnode):integer;
var temp:pnode;
begin
	if not empty(stack) then begin
		pop:=stack^.w;
		temp:=stack;
		stack:=stack^.next;
		dispose(temp);
	end else begin
		writeln('nie mozna zdejmowac z pustego stosu!');
		halt;
	end;
end;

var 
	s:pnode;
	i:integer;

begin
	init(s);
	for i:=0 to 10 do push(s,i);
 	while not empty(s) do
  		write(pop(s),' ');
end.
