{funkcja ktora dla zmiennej typu tablica zwraca numer wiersza w ktorym
wystepuje najdluzszy podciag zlozony z tych samych liczb
w przypadku kilku podciagow o tej samej dlugosci nalezy zwrocic pozycje
pierwszego z nich}
program tab_2podciagi;
uses crt2;
const
     max1=7;
     max2=4;
type
    wiersz=array[1..max1] of integer;
    tablica=array[1..max2] of wiersz;
var tab:tablica;
    a,b:integer;

function nrw(var t:tablica):integer;
         var max,i:integer;
         function podciag(wier:integer):integer;
                  var najdl,i,pom:integer;
                  begin
                  najdl:=1;
                  pom:=1;
                  for i:=1 to max1-1 do
                      begin
                      if t[wier][i]=t[wier][i+1] then najdl:=najdl+1
                      else
                           begin
                           if najdl>pom then pom:=najdl;
                           najdl:=1;
                           end;
                      end;
                      podciag:=pom;
                  end;
         begin
         max:=podciag(1);
         nrw:=1;
         for i:=2 to max2 do if podciag(i)>max then
             begin
             max:=podciag(i);
             nrw:=i;
             end;
         end;
begin
clrscr;
for a:=1 to max2 do
    begin
    for b:=1 to max1 do
        begin
        randomize;
        tab[a][b]:=random(3);
        write(tab[a][b],' ');
        delay(153);
        end;
    writeln;
    end;
write(nrw(tab));
repeat until keypressed;
end.

