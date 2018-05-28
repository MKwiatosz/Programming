program pierwiastekcalkowity;
uses crt2;
var licz,n,x:integer;
begin
clrscr;
read(licz);
x:=0;
n:=1;
while x<=licz do begin
      x:=x+2*n+1;
      n:=n+1;
      end;
write(n-1);
repeat until keypressed;
end.