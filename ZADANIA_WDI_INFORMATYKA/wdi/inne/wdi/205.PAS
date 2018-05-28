{procedura ktora zwroci warosc elementu dla ktorego suma otaczajacych
go elementow jest wieksza od niego}
program sumaelement;
uses crt2;
const x=3;
      y=6;
type tablica=array[1..y,1..x] of integer;
var t:tablica;
    i,j:integer;
procedure wypisz(var t:tablica);
          var sum,xx,yy,k,l:integer;
          begin
          for xx:=1 to x do
              begin
              for yy:=1 to y do
                  begin
                  sum:=-t[yy,xx];
                  for k:=xx-1 to xx+1 do
                      for l:=yy-1 to yy+1 do
                          if (k>0) and (l>0) and (k<=x) and (l<=y) then
                             sum:=sum+t[l,k];
                  if sum>t[yy,xx] then write(t[yy,xx]:2);
                  end;
              end;
          end;

begin
clrscr;
for i:=1 to y do
    begin
    for j:=1 to x do
        begin
        randomize;
        t[i,j]:=0;
        if random(2)=0 then t[i,j]:=random(6);
        write(t[i,j]:2);
        delay(153);
        end;
    writeln;
    end;
writeln;

wypisz(t);
repeat until keypressed
end.