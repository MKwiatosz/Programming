{procedura zamieniajaca niejemna kiczbe calkowita na system o podstawie p
i wypisujaca jej wartosc w nowym systemie.}
program systemxx;
uses crt2;
var liczb,syste:integer;
procedure systemz(var licz:integer;sys:integer);
          var dzies,wyn:integer;
          begin
          dzies:=1;
          wyn:=0;
          while licz>0 do begin
                wyn:=(licz mod sys)*dzies+wyn;
                licz:=licz div sys;
                dzies:=dzies*10;
                end;
          licz:=wyn;
          end;
begin
clrscr;
read(liczb,syste);
systemz(liczb,syste);
write(liczb);
repeat until keypressed;
end.