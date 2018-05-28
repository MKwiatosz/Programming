program kolos_2_usunidentyczne;
uses crt2;
const n=10;
type table=array[1..n] of integer;
var tab:table;
    i,j:integer;
    pom:boolean;
begin
clrscr;
for i:=1 to n do
    begin
    randomize;
    tab[i]:=random(9);
    write(tab[i],' ');
    delay(153);
    end;

writeln;
for i:=1 to n do
    begin
    pom:=false;
    for j:=i+1 to n do
        if tab[j]=tab[i] then
           begin
           tab[j]:=0;
           if pom=false then pom:=true;
           end;
    if pom then tab[i]:=0;
    end;

for i:=1 to n do write(tab[i],' ');
repeat until keypressed;
end.
