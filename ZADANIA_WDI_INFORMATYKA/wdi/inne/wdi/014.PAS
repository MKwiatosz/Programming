program silniax;
uses crt2;
var licz:integer;
function silnia(n:integer):integer;
         begin
         if n<2 then silnia:=1
         else
         silnia:=n*silnia(n-1);
         end;
begin
clrscr;
read(licz);
write(silnia(licz));
repeat until keypressed;
end.