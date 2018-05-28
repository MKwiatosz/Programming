{pojedyncza, niepusta lista zakonczona jest cyklem. prosze napisac funkcje
ktora zwraca dla danejlisty ilosc elementow w cyklu. do funkcji nalezy
przekazac wskaznik na poczatek listy. mozna zalozyc, ze ilosc elementow
w liscie nie przekracza 100. [mozna rozwazyc takze przypadek, ze nie znamy
ilosci elementow w liscie]}
program wskazniki_4_cykl;
uses crt2;
type
    pwezel=^wezel;
    wezel=record
                nr:integer;
                next:pwezel;
                end;

function cykl(f:pwezel):integer;      {liczba elementow nie przekracza 100}
         var i,stol,licznik:integer;
             sto:pwezel;
         begin
         for i:=1 to 99 do f:=f^.next;
         stol:=f^.nr;
         sto:=f;
         licznik:=1;
         for i:=1 to 100 do
             begin
             f:=f^.next;
             if (f=sto) and (f^.nr=stol) then break;
             end;
         cykl:=i;
         end;

begin
clrscr;

repeat until keypressed;
end.