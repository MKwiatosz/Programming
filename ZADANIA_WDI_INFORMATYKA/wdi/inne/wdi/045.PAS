{dana jest zmienna globalna wskazujaca na poczatek listy.
prosze napisac procedure, ktora dla powyzszej listy usuwa z niej n-ty element
jezeli lista posiada co najmeniej n elementow, jezeli lista posiada mniej
niz n elementow procedura nie robi nic. do procedury nalezy przekazac:
wskaznik na poczatek listy oraz numer elementu do usuniecia}
program wskazniki_3_usuniecie_z_listy;
uses crt2;
type
    pwezel=^wezel;
    wezel=record
                next:pwezel;
                nr:integer;
                prev:pwezel;
                end;
var first:pwezel;

procedure stworz(var first:pwezel;n:integer);
          var i,licz:integer;
              l:pwezel;
          begin
          first:=nil;
          for i:=1 to n do
              begin
              read(licz);
              new(l);
              l^.next:=first;
              l^.nr:=licz;
              if i<>1 then l^.next^.prev:=l;
              l^.prev:=nil;
              first:=l;
              end;
          end;


procedure wypisz(first:pwezel);
          var f:pwezel;
              i:integer;
          begin
          f:=first;
          while f^.next<>nil do
                begin
                write(f^.nr,' ');
                f:=f^.next;
                end;
                writeln(f^.nr,' ');
          while f<>nil do
                begin
                write(f^.nr,' ');
                f:=f^.prev;
                end;

          end;

procedure usun(var first:pwezel;n:integer);
          var i:integer;
              r:pwezel;
          begin
          r:=first;
          if r=nil then halt;
          if n=1 then
             if r^.next=nil then dispose(r)
             else
                 begin
                 r^.next^.prev:=nil;
                 first:=r^.next;
                 dispose(r);
                 end
          else
              for i:=1 to n-1 do
                  begin
                  r:=r^.next;
                  if r=nil then
                     begin
                     i:=0;
                     break;
                     end;
                  end;
              if i=n-1 then
                 begin
                 if r^.next=nil then r^.prev^.next:=nil
                 else
                     begin
                     r^.prev^.next:=r^.next;
                     r^.next^.prev:=r^.prev;
                     end;
                 dispose(r);
                 end;
          end;


begin
clrscr;
stworz(first,5);
wypisz(first);
writeln;
usun(first,6);


wypisz(first);
repeat until keypressed;
end.