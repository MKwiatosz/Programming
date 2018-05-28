program cutpowdwukier;
uses crt2;
type pwezel=^node;
     node=record
                next,prev:pwezel;
                nr:integer;
                end;
var f:pwezel;

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




procedure usun(var head:pwezel);
          var wart:integer;
              n,p,r:pwezel;
          begin
          p:=head;
          while p^.next<>nil do
                begin
                n:=p^.next;
                wart:=p^.nr;
                while n<>nil do
                      begin
                      if n^.nr=wart then
                         begin
                         if n^.next=nil then
                            begin
                            r:=n;
                            n^.prev^.next:=nil;
                            dispose(r);
                            break;
                            end
                         else
                            begin
                            r:=n;
                            n^.prev^.next:=n^.next;
                            n^.next^.prev:=n^.prev;
                            n:=n^.next;
                            dispose(r);
                            end
                         end

                      else n:=n^.next;
                      end;
                      p:=p^.next;
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


begin
clrscr;
stworz(f,6);
wypisz(f);
usun(f);
writeln;
wypisz(f);


repeat until keypressed;
end.