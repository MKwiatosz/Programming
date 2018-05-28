program korlikifibonacciego;
uses crt2;
var f0,f1,f2,pok,i:integer;
begin
clrscr;
read(pok);
f0:=0;
f1:=1;
if pok=0 then write(f0) else begin
for i:=2 to pok do
    begin
    f2:=f1+f0;
    f0:=f1;
    f1:=f2;
    end;
write(f1);
end;
repeat until keypressed;
end.
