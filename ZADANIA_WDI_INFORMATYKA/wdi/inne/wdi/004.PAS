program NWD;
uses crt2;
var a,b:integer;
begin
clrscr;
read(a,b);
while a<>b do if a>b then a:=a-b else b:=b-a;
write(a);
repeat until keypressed;
end.