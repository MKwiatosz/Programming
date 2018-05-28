function merge(a,b:pnode):pnode;
var tmp:pnode;
begin
	new(tmp); merge:=tmp;
	while (a<>nil) and (b<>nil) do begin
		if(a^.klucz=b^.klucz) then b:=b^.next;
		if(a^.klucz<b^.klucz) then begin
			tmp^.next:=a;
			a:=a^.next;
		end
		else begin
			tmp^.next:=b;
			b:=b^.next;
		end;
		tmp:=tmp^.next;
	end;
	if a=nil then tmp^.next:=b
	else tmp^.next:=a;
	merge:=merge^.next;
end;

{  }
