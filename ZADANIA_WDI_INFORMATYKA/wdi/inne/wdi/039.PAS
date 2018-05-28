{procedura ktora dla zmiennej typu table zwraca numer wiersza
i kolumny elementu dal ktorego suma otaczjacych go elementow
jest najmniejsza}
program tab_10_sasiedzi;
uses crt2;
const max1=5;
      max2=4;
type  table=array[1..max1,1..max2] of real;
var tab:table;
    c,d:integer;

procedure najmniejsza(var t:table);
          var i,u,wiersz,kolumna:integer;
              najm:real;
          function suma(x,y:integer):real;
                   var a,b:integer;
                       sum:real;
                   begin
                   sum:=-t[x,y];
                   for a:=x-1 to x+1 do
                       for b:=y-1 to y+1 do
                           if (a>=1) and (b>=1) and (a<=max1) and (b<=max2)
                              then sum:=sum+t[a,b];
                   suma:=sum;
                   end;
          begin
          najm:=suma(1,1);
          wiersz:=1;
          kolumna:=1;
          for i:=1 to max1 do
              for u:=1 to max2 do
                  if suma(i,u)<najm then
                     begin
                     najm:=suma(i,u);
                     wiersz:=i;
                     kolumna:=u;
                     end;
          writeln('w',wiersz,' k',kolumna);
          end;


begin
clrscr;
for c:=1 to max1 do begin
    for d:=1 to max2 do
        begin
        randomize;
        tab[c,d]:=random(4);
        write(tab[c,d]:1:0,' ');
        delay(153);
        end;
    writeln;
    end;
najmniejsza(tab);
repeat until keypressed;
end.