{dana jest zmienna globalna wskazujaca na poczatek listy.
prosze napisac procedure ktora wstawia do powyzszej listy nowy element
typu wezel na n-ta pozycje. mozna zalozyc, ze lista posiada co najmniej
n elementow. do proceury nalezy przekazac: wskaznik na poczatek listy,
wstawiany element oraz pozycje a ktorej nalezy wstawic nowy element}
program wskazniki_1_wstawianie;
uses crt2;
type
    pwezel=^wezel;
    wezel=record
                next:pwezel;
                nr:integer;
                prev:pwezel;
    end;
var first,lista,niu:pwezel;


procedure stworz(var l,f:pwezel;n:integer);
          var i,licz:integer;
          begin
          f:=nil;
          for i:=1 to n do
              begin
              read(licz);
              new(l);
              l^.next:=f;
              if i<>1 then l^.next^.prev:=l;
              l^.prev:=nil;
              l^.nr:=licz;
              f:=l;
              end;
          end;

procedure wypisz(var l,f:pwezel);
          var i:integer;
          begin
          l:=f;
          while l^.next<>nil do
                begin
                write(l^.nr,' ');
                l:=l^.next;
                end;
          writeln(l^.nr,' |nazad:');

          while l<>nil do
                begin
                write(l^.nr,' ');
                l:=l^.prev;
                end;
          l:=f;
          end;

procedure wstaw(first,nowy:pwezel;n:integer);
          var i:integer;

          begin
          if n=1 then
             begin
             nowy^.next:=first;
             nowy^.prev:=nil;
             first:=nowy;
             end
          else
              begin
              for i:=1 to n-1 do first:=first^.next;
              nowy^.next:=first;
              nowy^.prev:=first^.prev;
              first^.prev^.next:=nowy;
              first^.prev:=nowy;

              end;
          end;

begin
clrscr;
stworz(lista,first,5);
writeln;
wypisz(lista,first);
writeln;
new(niu);
niu^.nr:=13;
wstaw(first,niu,3);
wypisz(lista,first);
repeat until keypressed;
end.



