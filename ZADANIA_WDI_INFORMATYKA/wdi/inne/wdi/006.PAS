program liczbypierwsze;
uses crt2;
const n=200;
var i,t:integer;
    tab:array[2..n] of boolean;
begin
clrscr;
for i:=2 to n do tab[i]:=true;
i:=2;
while i<=sqrt(n) do
      begin
      t:=i*i;
      while t<=n do begin
          tab[t]:=false;
          t:=t+i;
          end;
      i:=i+1;
      end;
for i:=2 to n do if tab[i] then write(i,' ');
repeat until keypressed
end.
