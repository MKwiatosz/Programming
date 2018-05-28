program lista;
uses crt2;
const n=10;
type pnode=^node;
     node=record
               w:integer;
               next:pnode;
               end;
var first,p:pnode;
    i,s:integer;
begin
clrscr;
first:=nil;
for i:=1 to n do begin
    read(s);
    new(p);
    p^.next:=first;
    p^.w:=s;
    first:=p;
    end;
end.

