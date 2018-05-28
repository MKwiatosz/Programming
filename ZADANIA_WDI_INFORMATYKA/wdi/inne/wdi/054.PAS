program osiem_hetamnow_2;
uses crt2;
var i:integer;
    a:array[1..8] of boolean;
    b:array[2..16] of boolean;
    c:array[-7..7] of boolean;     {nie dziala}
    x:array[1..8] of integer;

procedure drukuj;
          var k:integer;
          begin
          for k:=1 to 8 do write(x[k]:3);
          writeln;
          end;

procedure probuj(i:integer);
          var j:integer;
          begin
          for j:=1 to 8 do
              if a[j] and b[i+j] and c[i-j] then
                 begin
                 x[i]:=1;
                 a[j]:=false;
                 b[i+j]:=false;
                 c[i-j]:=false;
                 if i<8 then probuj(i+1) else drukuj;
                 a[j]:=true;
                 b[i+j]:=true;
                 c[i-j]:=true;
                 end;
          end;

begin
clrscr;

for i:=1 to 8 do a[i]:=true;
for i:=2 to 16 do a[i]:=true;
for i:=-7 to 7 do c[i]:=true;
probuj(1);
repeat until keypressed;
end.