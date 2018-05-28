program xsystem;
uses crt2;
var dzies,licz,sys,wyn:integer;
begin
clrscr;
dzies:=1;
wyn:=0;
read(licz,sys);
while licz>0 do begin
      wyn:=(licz mod sys)*dzies+wyn;
      licz:=licz div sys;
      dzies:=dzies*10;
      end;
write(wyn);
repeat until keypressed;
end.