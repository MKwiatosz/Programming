program pierwiasteknewtona;
uses crt2;
var licz,dokl,x,y:real;
begin
clrscr;
read(licz,dokl);
x:=licz/2;
repeat
y:=x;
x:=0.5*(y+licz/y)
until abs(x-y)<dokl;
write(x);
repeat until keypressed;
end.