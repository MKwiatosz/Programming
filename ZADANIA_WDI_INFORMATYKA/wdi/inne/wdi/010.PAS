program kolos1podzielniki;
uses crt2;
var licz,max,pom,lpom:integer;
function podzielniki(x:integer):integer;
         var i,l:integer;
         begin
         l:=0;
         for i:=1 to x do if x mod i=0 then l:=l+1;
         end;
begin
clrscr;
max:=0;
while not eof do
      begin
      read(licz);
      pom:=podzielniki(licz);
      if pom>max then begin
         max:=pom;
         lpom:=licz;
      end;
if pom=max then if lpom>licz then lpom:=licz;
end;
write(lpom);ÿ
repeat until keypressed;
end.
