{funkcja ktrora zwraca wartosc true jezeli w zmiennej typu tablica
suma dwoch dowolnych sosiednich elementow jest rowna sredniej
arytmetycznej wszystkich elementow tablicy}
program tab_5;
uses crt2;
const max=2;
type tablica=array[1..max,1..max] of integer;
var t:tablica;

function xxx(var tab:tablica):boolean;
         var i,j,x,y,sum:integer;
         begin
         xxx:=false;
         sum:=0;
         for i:=1 to max do
             for j:=1 to max do sum:=sum+tab[i,j];

         for x:=1 to max do
             for y:=1 to max do
                 begin

                 if (x+1<=max) and ((tab[x,y]+tab[x+1,y])*max*max=sum)
                 then xxx:=true;
                 if (y+1<=max) and((tab[x,y]+tab[x,y+1])*max*max=sum)
                 then xxx:=true;
                 if (x+1<=max) and (y+1<=max) and
                 ((tab[x,y]+tab[x+1,y+1])*max*max=sum) then xxx:=true;

                 end;


         end;
begin
clrscr;
t[1,1]:=5;
t[2,2]:=1;
t[1,2]:=7;
t[2,1]:=3;
write(xxx(t));

repeat until keypressed;
end.
