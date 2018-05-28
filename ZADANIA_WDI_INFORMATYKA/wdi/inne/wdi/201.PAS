program zeszyt2;
uses crt2;
const n=10;
type tablica=array[1..n] of integer;
var t:tablica;
    i:integer;

procedure najcwt(var t:tablica);
          var dlug,najw,i:integer;
          begin
          najw:=1;
          dlug:=1;
          for i:=1 to n-1 do
              begin
              if t[i]<t[i+1] then dlug:=dlug+1
              else
                  begin
                  if dlug>najw then najw:=dlug;
                  dlug:=1;
                  end;
              end;
          if dlug>najw then najw:=dlug;
          write(najw);
          end;


procedure wstawianie(var t:tablica);
          var i,j,x:integer;
          begin
          for i:=2 to n do
              begin
              x:=t[i];
              j:=i-1;
              while (j>0) and (t[j]>x) do
                    begin
                    t[j+1]:=t[j];
                    j:=j-1;
                    end;
              t[j+1]:=x;
              end;
          end;


procedure wybieranie(var t:tablica);
          var i,j,gdzie,min:integer;
          begin
          for i:=1 to n-1 do
              begin
              min:=t[i];
              gdzie:=i;
              for j:=i+1 to n do
                  begin
                  if min>t[j] then
                     begin
                     min:=t[j];
                     gdzie:=j;
                     end;
                  end;
                  t[gdzie]:=t[i];
                  t[i]:=min;
              end;
          end;

procedure babelkowe(var t:tablica);
          var i,j,pom:integer;
          begin
          for i:=2 to n do
              for j:=n downto i do
                  if t[j-1]>t[j] then
                     begin
                     pom:=t[j-1];
                     t[j-1]:=t[j];
                     t[j]:=pom;
                     end;
          end;


begin
clrscr;
for i:=1 to n do
    begin
    randomize;
    t[i]:=random(10);
    write(t[i],' ');
    delay(273);
    end;
writeln;
najcwt(t);
{
wstawianie(t);
wybieranie(t);
}babelkowe(t);


writeln;
for i:=1 to n do write(t[i],' ');
repeat until keypressed;
end.
