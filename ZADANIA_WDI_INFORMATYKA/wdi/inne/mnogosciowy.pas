program mnogosciowy;

type
	pnode = ^node;
	node = record
		val : integer;
		next : pnode;
		end;

{ rzeczona funkcja }
function merge(list1,list2:pnode):pnode;

{ usuwa zawsze z przodu i automatycznie sie przesuwa }
procedure move(var l:pnode);
var temp:pnode;
begin
	temp:=l;
	l:=l^.next;
	dispose(temp);
end;

var
	temp: pnode;
	last:integer;
begin
	merge:=nil;
	while (list1<>nil) and (list2<> nil) do begin
		{ jesli wartosci ktorejs z list sa mniejsze niz w drugiej
			liscie to znaczy ze ta lista musi dogonic ta druga
			i jednoczesnie oznacza to ze wartosc wystepuje tylko w 
			jednym ze zbiorow }
		if list1^.val < list2^.val then move(list1);
		if list2^.val < list1^.val then move(list2);
		
		{ dodawanie do listy }
		if list2^.val = list1^.val then begin
			last:=list1^.val;
			
			{ przepisam elem. z 1 listy }
			temp:=list1;
			temp^.next:=merge;
			list1:=list1^.next;	{ uwaga! nie moge usunac poniewaz uzywam elelmentu }
			merge:=temp;
			
			{ uwaga2! nie usuwam elementow z 2 listy poniewaz robia to za mnie 2 petle dalej }
			
			{ w razie gdyby wystapily elementy kilkakrotnie }			
			while last=list1^.val do move(list1);
			while last=list2^.val do move(list2);
		end	
	end;
end;


begin


end.
