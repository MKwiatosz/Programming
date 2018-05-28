program tab1_najmznajw;    {zwraca numer wiersza w ktorym najwieksza wartosc
                           jest najmniejsza}
uses crt2;
const max1=5;   {wiersze x}
      max2=10;   {elementy wiersza y}
type  table=array[1..max1] of array[1..max2] of real;
var i,t:integer;
    tab:table;

function najmniejsza(var t:table):integer;
         var i,wiersz:integer;
             najm:real;
         function max(x:integer):real;
                  var najw:real;
                      i:integer;
                  begin
                  najw:=t[x][1];
                  i:=2;
                  while i<=max2 do
                        begin
                        if t[x][i]>najw then najw:=t[x][i];
                        i:=i+1;
                        end;
                  max:=najw;
                  end;

         begin
         najm:=max(1);
         wiersz:=1;
         i:=2;
         while i<=max1 do begin
               if max(i)<najm then
                  begin
                  najm:=max(i);
                  wiersz:=i;
                  end;
               i:=i+1;
               end;
               najmniejsza:=wiersz;
         end;


begin
clrscr;
for i:=1 to max1 do begin
    for t:=1 to max2 do
        begin
        randomize;
        tab[i][t]:=random(99);
        write(tab[i][t]:2:0,' ');
        delay(157);
        end;
    writeln;
    end;
write(najmniejsza(tab));

repeat until keypressed;
end.