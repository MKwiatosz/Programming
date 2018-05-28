{procedyra ktora zmienna typu tablica wypelnia "po spirali" kolejnymi
wyrazami ciagu arytmetycznego o zadanym wyrazie poczatkowym i zadanej roznicy
ciagu. do procedury nalezy przekazac:wypelniana tablice, wyraz poczatkowy
i roznice ciagu}
program tab_7_spirala_arytmetyczna;
uses crt2;
const max=9;
type tablica=array[1..max,1..max] of integer;
var t:tablica;
    c,b,roz,pierw:integer;
procedure spirala(var t:tablica;a,r:integer);
          var x,y,zx,zy,prom,gr:integer;

          begin
          y:=(max+1) div 2;
          if ((max+1)mod 2)=0 then x:=(max+1)div 2 else x:=((max+1)div 2)+1;
          t[x,y]:=a;
          prom:=1;
          a:=a+r;
          zx:=x;
          zy:=y;
          while (zx<=max) and (zy<=max) and (prom<=(max div 2)) do
                begin

                      zx:=zx-1;

                      if zx<1 then break;

                      t[zx,zy]:=a;
                      a:=a+r;

                repeat
                      zy:=zy+1;
                      t[zx,zy]:=a;
                      a:=a+r;
                until zy=y+prom;

                repeat
                      zx:=zx+1;
                      t[zx,zy]:=a;
                      a:=a+r;
                until zx=x+prom;

                if zx>max then break;

                repeat
                      zy:=zy-1;
                      t[zx,zy]:=a;
                      a:=a+r;
                until zy=y-prom;

                repeat
                      zx:=zx-1;
                      t[zx,zy]:=a;
                      a:=a+r;
                until zx=x-prom;
                prom:=prom+1;
                end;
          end;


begin
clrscr;
read(pierw,roz);
spirala(t,pierw,roz);
for c:=1 to max do
    begin
    for b:=1 to max do write(t[b,c]:3,' ');
    writeln;
    writeln;
    end;
repeat until keypressed;
end.