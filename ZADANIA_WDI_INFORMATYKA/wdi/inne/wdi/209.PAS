program tablice5;
uses crt2;
const max=2;
type tablica=array[1..max,1..max] of integer;
var t:tablica;
    i,j:integer;
    function xxx(var t:tablica):boolean;
             var i,j,x,y,sum:integer;
             begin
             xxx:=false;
             sum:=0;
             for i:=1 to max do
                 for j:=1 to max do sum:=sum+t[i,j];

             for i:=1 to max do
                 for j:=1 to max do
                     begin
                     if i+1<=max then if max*max*(t[i,j]+t[i+1,j])=sum then
                        xxx:=true;
                     if j+1<=max then if max*max*(t[i,j]+t[i,j+1])=sum then
                        xxx:=true;
                     if (i+1<=max) and (j+1<=max) then
                        if max*
                        max*(t[i,j]+t[i+1,j+1])=sum then xxx:=true;
                     if (j-1>=1) and (i+1<=max) then
                        if max*max*(t[i,j]+t[i+1,j-1])=sum then xxx:=true;
                     end;


             end;


begin
clrscr;
for i:=1 to max do
    begin
    for j:=1 to max do
        begin
        randomize;

        t[i,j]:=random(5);
        write(t[i,j],' ');
        delay(153);
        end;
    writeln;
end;
write(xxx(t));


repeat until keypressed;
end.