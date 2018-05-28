{zakladamy, ze zmienna typu tablica jest wypelniona przypadkowymi wartosciami
prosze napisac procedure ktora dla zmiennej typu tablica zwraca
wspolrzedne i,j elementu t[i,j]dla ktorego suma elementow w ukosnych
rzedach jest najwieksza}
program tab_8_ukosne_suma;
uses crt2;
const max=4;
type tablica=array[1..max,1..max] of integer;
var t:tablica;
    a,b:integer;
procedure sumax(var t:tablica);
          var x,y,najw,xx,yy:integer;


      function rosnaca(x1,y1:integer):integer;
          var zx1,zy1,suma1:integer;
          begin
          zx1:=x1;
          zy1:=y1;
          while (zx1>1) and (zy1<max) do
                begin
                zx1:=zx1-1;
                zy1:=zy1+1;
                end;

          suma1:=0;
          while (zx1<=max) and (zy1>=1) do
                begin
                suma1:=suma1+t[zx1,zy1];
                zx1:=zx1+1;
                zy1:=zy1-1;
                end;
          rosnaca:=suma1;
          end;

      function malejaca(x2,y2:integer):integer;
          var zx2,zy2,suma2:integer;
          begin
          zx2:=x2;
          zy2:=y2;
          while (zy2>1) and (zx2>1) do
             begin
             zy2:=zy2-1;
             zx2:=zx2-1;
             end;
          suma2:=0;

          while (zx2<=max) and (zy2<=max) do
                begin
                suma2:=suma2+t[zx2,zy2];
                zx2:=zx2+1;
                zy2:=zy2+1;
                end;

          malejaca:=suma2;

          end;

          begin
          najw:=rosnaca(1,1)+malejaca(1,1);
          xx:=1;yy:=1;
          for x:=1 to max do
              for y:=1 to max do
                  begin
                  if najw<rosnaca(x,y)+malejaca(x,y) then
                     begin
                     najw:=rosnaca(x,y)+malejaca(x,y);
                     xx:=x;
                     yy:=y;
                     end;
                  end;


                writeln(xx,' ',yy);
                write(rosnaca(xx,yy),'/  \',malejaca(xx,yy));
          end;

begin
clrscr;
for a:=1 to max do begin
    for b:=1 to max do begin
        randomize;
        t[a,b]:=random(4);
        write(t[a,b],' ');
        delay(154);
        end;
        writeln;
        end;
sumax(t);

repeat until keypressed;
end.