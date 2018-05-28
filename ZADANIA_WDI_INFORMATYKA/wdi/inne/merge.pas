type
	pnode = ^node;
	node = record
		key : integer;
		next : pnode;
	end;
	

function merge(a,b:pnode):pnode;
var temp:pnode;	{ wskaznik na kolejny element w licie }
begin
	merge:=nil;
	while (a<>nil) and (b<>nil) do begin
		if a^.key<b^.key then begin
			
			a^.next:=merge;
			merge:=a;		
		end else if a^.key>b^.key then begin
			b^.next:=merge;
			merge:=b;		
		end 
	
	end;
end;
