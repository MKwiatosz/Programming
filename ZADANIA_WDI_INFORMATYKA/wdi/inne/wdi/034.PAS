{typ d1 opisuje dluga, dodatnia liczbe calkowita. najbardziej znaczacy bit
znajduje sie na pozycji 1. Prosze napisac procedure, poszadkujaca tablice
opisana typem d2 wg rosnacych wartosci liczb metoda przepisywania ich do
drugiej tablicy. do procedury nalezy przekazac dwie tablice typu d2}
program tab_6_sort_u2;
uses crt2;
const
     max1=7;
     max2=5;
type
    d1=array[1..max1] of boolean;
    d2=array[1..max2] of d1;
var t1,t2:d2;
    i,t,m:integer;
    roz:boolean;

procedure sortuj(var inp,out:d2);
          var najw:d1;
              skreslone:array[1..max2] of boolean;
              i,t:integer;
          begin
          for i:=1 to max2 do skreslone[i]:=true;
          najw:=inp[1];

          for i:=1 to max2 do
              if skreslone[i]=true then
              begin
              for t:=1 to max1 do
                  begin
                  if (inp[i][t]=true) and (najw[t]=false) then
                     begin
                     najw:=inp[i];
                     break;
                     end;
              end;
              out[i]:=najw;
              skreslone[i]:=false;
          end;

end;

begin
clrscr;
for i:=1 to max2 do begin
    for t:=1 to max1 do
        begin
        randomize;
        m:=random(2);
        roz:=true;
        if m=1 then roz:=TRUE;
        if m=0 then roz:=false;
        t1[i][t]:=roz;
        write(t1[i][t],' ');
        delay(153);
        end;
    writeln;
    end;
writeln;
sortuj(t1,t2);
for i:=1 to max2 do begin
    for t:=1 to max1 do write(t2[i][t],' ');
    writeln;
    end;


repeat until keypressed;
end.