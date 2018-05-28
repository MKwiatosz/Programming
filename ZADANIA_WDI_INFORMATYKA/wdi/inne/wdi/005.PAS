program czynnikipierwsze;
uses crt2;
var licz,i:integer;
begin
clrscr;
read(licz);
i:=2;
while licz>1 do
      if licz mod i=0 then begin
         write(i);
         licz:=licz div i;
         end
      else i:=i+1;
repeat until keypressed;
end.