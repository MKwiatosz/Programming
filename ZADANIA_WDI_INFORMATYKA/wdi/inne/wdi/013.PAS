program najdluzszyciagwtablicy;
uses crt2;
const n=20;
type tab=array[1..n] of integer;
var tablica:tab;
    t:integer;

    function ciag(var t:tab):integer;
             var i,pom,max:integer;
             begin
             max:=0;pom:=1;
             for i:=1 to n-1 do begin
                 if t[i]<t[i+1] then pom:=pom+1 else
                    begin if max<pom then max:=pom;
                    pom:=1;
                    end;
                 end;
             if pom>max then max:=pom;
             ciag:=max;
             end;

    procedure wstawianie(var t:tab);
              var i,j,x:integer;
              begin
              for i:=2 to n do begin
                  x:=t[i];
                  j:=i-1;
                  while (j>0) and (x<t[j]) do
                        begin
                        t[j+1]:=t[j];
                        j:=j-1;
                        end;
                  t[j+1]:=x;
                  end;
              end;


    function binarne(var t:tab;szuk:integer):integer;
             var poc,kon,sro:integer;
             begin
             poc:=1;
             kon:=n;
             binarne:=-1;
             repeat
                   sro:=(poc+kon) div 2;
                   if t[sro]=szuk then binarne:=sro;
                   if t[sro]>szuk then kon:=sro-1;
                   if t[sro]<szuk then poc:=sro+1;
             until (poc>kon) or (t[sro]=szuk);
             end;

    procedure wybieranie(var t:tab);
              var gdzie,min,i,j:integer;
              begin
              for i:=1 to n-1 do begin
                  min:=t[i];
                  gdzie:=i;
                  for j:=i+1 to n do
                      if min>t[j] then begin
                         min:=t[j];
                         gdzie:=j;
                         end;
                         t[gdzie]:=t[i];
                         t[i]:=min;

              end;
              end;

    procedure babelkowe(var t:tab);
              var i,j,pom:integer;
              begin
              for i:=2 to n do
                  for j:=n downto i do begin
                      if t[j-1]>t[j] then
                         begin
                         pom:=t[j-1];
                         t[j-1]:=t[j];
                         t[j]:=pom;
                         end;
              end;
              end;

begin
clrscr;
for t:=1 to n do
    begin
    randomize;
    tablica[t]:=random(16);
    delay(151);
    end;
for t:=1 to n do write(tablica[t],' ');
writeln;
writeln('ciag: ',ciag(tablica));
{wstawianie(tablica);}
{wybieranie(tablica);}
babelkowe(tablica);
for t:=1 to n do write(tablica[t],' ');
writeln;
writeln('wyszukiwanie: ',binarne(tablica,12));
repeat until keypressed;
end.
