program sitoerastostenesa;
uses crt2;
const n=100;
var sito,pierwsze:set of 2..n;
    next,i:integer;
begin
clrscr;
sito:=[2..n];
pierwsze:=[ ];
next:=2;
repeat
while not(next in sito) do next:=succ(next);
pierwsze:=pierwsze+[next];
i:=next;
while i<=n do begin
      sito:=sito-[i];
      i:=i+next;
      end;
until sito=[ ];
for i:=2 to n do if i in pierwsze then write(i,' ');
repeat until keypressed;
end.