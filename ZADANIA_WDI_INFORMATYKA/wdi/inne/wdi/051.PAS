{prosze napisac procedure ktora w liscie wskazywanej przez zmienna
typy pwezel odwraca kolejnosc jej elementow. mozna zalozyc ze lista jest
niepusta}
program wskazniki_11_odwracanie;
uses crt2;
const max=5;
type
    pwezel=^wezel;
    wezel=record
                next:pwezel;
                nr:integer;
                end;
var l:pwezel;

    procedure stworz(var p:pwezel);
              var r:pwezel;
                  a,licz:integer;
              begin
              p:=nil;
              for a:=1 to max do
                  begin
                  new(r);
                  r^.next:=p;
                  r^.nr:=a;
                  p:=r;
                  end;
              end;
    procedure wypisz(p:pwezel);
              begin
              while p<>nil do
                    begin
                    write(p^.nr,' ');
                    p:=p^.next;
                    delay(153);
                    end;
              end;

    procedure odwroc(var p:pwezel);     {metoda czolgowa}
              var first,pop,ost,last:pwezel;
              begin
              first:=p;
              while p^.next<>nil do p:=p^.next;
              ost:=p;
              last:=ost;
              p:=first;
              while ost<>first do
                    begin
                    p:=first;
                    while p^.next<>ost do p:=p^.next;
                    ost:=p;
                    p^.next^.next:=p;

                    end;
              if ost=first then first^.next:=nil;
              p:=last;
              end;

begin
clrscr;
stworz(l);
wypisz(l);
writeln;
odwroc(l);
wypisz(l);
repeat until keypressed;
end.