program tab_6_sortowanieU2; {nagmatwane ale dziala}
uses crt2;
const max1=7;
      max2=5;
type  d1=array[1..max1] of boolean;
      d2=array[1..max2] of d1;

var x,y:integer;
    t1,t2:d2;
    but:boolean;

procedure sortuj(var inp,out:d2);
         var i,t,a,z,pozycja:integer;
             najw:d1;
             podleg:array[1..max2] of boolean;

         begin

         for i:=1 to max2 do podleg[i]:=true;

         a:=1;

         while (a<=max2) do
             begin
             for z:=1 to max2 do if podleg[z] then
                 begin
                 najw:=inp[z];
                 pozycja:=z;
                 break;
                 end;
             for i:=1 to max2 do if podleg[i] then
                begin
                for t:=1 to max1 do
                      begin
                      if (not najw[t]) and (inp[i][t]) then
                         begin
                         najw:=inp[i];
                         pozycja:=i;
                         break;
                         end;
                      if (najw[t]) and (not inp[i][t]) then break;
                      end;

                end;
             podleg[pozycja]:=false;
             out[a]:=inp[pozycja];
             a:=a+1;
             end;



         end;

begin
clrscr;
for x:=1 to max2 do
    begin
    for y:=1 to max1 do
        begin
        randomize;
        if random(2)=0 then but:=false else but:=true;
        t1[x][y]:=but;
        write(t1[x][y],'   ');
        delay(152);
        end;
    writeln;
    end;
writeln;
sortuj(t1,t2);

for x:=1 to max2 do begin
    for y:=1 to max1 do write(t2[x][y],'   ');
    writeln;
    end;

repeat until keypressed;
end.