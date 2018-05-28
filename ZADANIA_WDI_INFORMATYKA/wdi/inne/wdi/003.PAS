program podzielniki;
uses crt2;
var licz,podziel:integer;
begin
clrscr;
read(licz);
for podziel:=1 to trunc(sqrt(licz)) do
    if licz mod podziel=0 then
       write(podziel, licz div podziel);

repeat until keypressed
end.