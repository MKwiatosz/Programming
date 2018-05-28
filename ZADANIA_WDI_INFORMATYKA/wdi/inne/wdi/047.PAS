{globala zmienna typu pwezel wskazuje na liste cykliczna. prosze napisac
procedure usuwajaca nadmiarowe elementy z listy. mozna zalozyc ze lista
zawiera co najmniej 2 rozne elementy}
program wskazniki_5_usun_nadmiar;
uses crt2;
type
    pwezel=^wezel;
    wezel=record
                nr:integer;
                next:pwezel;
                end;
var cykl:pwezel;


    procedure usun(var cykl:pwezel);        {nie wiem czy dziala}
              var poczatek,pop,wsk:pwezel;
                  wart:integer;
              begin
              poczatek:=cykl;
              while cykl^.next<>poczatek do
                    begin
                    wart:=cykl^.nr;
                    pop:=cykl;
                    wsk:=cykl^.next;
                    while wsk<>poczatek do
                          begin
                          if wart=wsk^.nr then
                             begin
                             pop^.next:=wsk^.next;
                             dispose(wsk);
                             wsk:=pop^.next;
                             end
                          else
                              begin
                              pop:=wsk;
                              wsk:=wsk^.next;
                              end;
                          end;
                    cykl:=cykl^.next;
                    end;
              end;



begin
clrscr;


repeat until keypressed;
end.