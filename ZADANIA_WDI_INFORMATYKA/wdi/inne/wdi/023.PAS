program kwadratnieszescian;
uses crt2;
const z=20;
var licz:integer;

procedure kwasz(n:integer);
          var i,t:integer;
              pom:boolean;
          begin
          pom:=false;
          for i:=2 to trunc(sqrt(n)) do
              if (n mod (i*i)=0) then
                 begin
                 pom:=true;
                 for t:=2 to i do if (n mod (t*t*t)=0) then pom:=false;
                 end;
          write(pom);
          end;

begin
clrscr;
for licz:=1 to z do begin
write(licz);
kwasz(licz);
writeln;
end;

repeat until keypressed;
end.