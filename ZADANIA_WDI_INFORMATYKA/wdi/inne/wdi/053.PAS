{program, ktory rozwiazuje problem 8 hetmanow ustawionych na szachownicy tak
aby zaden nie atakowal innego}
program rozne_1_8hetmanow;
uses crt2;
var i:integer;
    q:boolean;
    a:array[1..8] of boolean;                   {nie dziala}
    b:array[2..16] of boolean;
    c:array[-7..7] of boolean;
    x:array[1..8] of integer;

    procedure probuj(i:integer; var q:boolean);
              var j:integer;
              begin
              j:=0;
              repeat
                    j:=j+1;
                    q:=false;
                    if a[j] and b[i+j] and c[i-j] then
                       begin
                       x[i]:=j;
                       a[j]:=false;
                       b[i+j]:=false;
                       c[i-j]:=false;
                       if i<8 then
                          begin
                          probuj(i+1,q);
                          if not q then
                             begin
                             a[j]:=true;
                             b[i+j]:=true;
                             b[i-j]:=true;
                             end;
                          end
                       else q:=true;
                    end;
              until q or (j=8);
              end;

begin
clrscr;
for i:=1 to 8 do a[i]:=true;
for i:=2 to 16 do b[i]:=true;
for i:=-7 to 7 do c[i]:=true;
probuj(1,q);
if q then for i:=1 to 8 do write(x[i]:3);
repeat until keypressed;
end.