{w zmiennych typu tablica wiekszosc(np 95%) elementow jest rowna 0. prosze
zaproponowac strukture dynamiczna (wskaznikowa)przechowujaca w sposob
efektywny (pod wzgledem wykorzystania pamieci) zawartosc zmiennej typu
tablica.
-prosze napisac procedure przeksztalcajaca zmienna typu tablica na
zaproponowana strukture
-prosze napisac funkcje, ktora korzystajac z zaproponowanej struktury
zwraca zawartosc wybranego elementu (okreslonego przez pare indeksow (i,j))}
program wskazniki_8_struktura;
uses crt2;
const max=10;                              {i wiersz, j kolumna}
type tablica=array[1..max,1..max] of integer;
     pwezel=^wezel;
     wezel=record
                 next:pwezel;
                 i,j,wart:integer;
                 end;
var tab:tablica;
    first:pwezel;
    a,b:integer;
     procedure przeksztalc(var t:tablica;var f:pwezel);
               var p:pwezel;
               var x,y:integer;                 {tablica ->> lista}
               begin
               f:=nil;
               for y:=1 to max do
                   for x:=1 to max do
                       if t[y,x]<>0 then
                          begin
                          new(p);
                          p^.next:=f;
                          p^.i:=y;
                          p^.j:=x;
                          p^.wart:=t[y,x];
                          f:=p;
                          end;


               end;
    function wartosc(f:pwezel;y,x:integer):integer;
             begin
             wartosc:=0;
             while (f<>nil) and (f^.i>=y) do
                   begin
                   if (f^.i=y) and (f^.j=x) then
                      begin
                      wartosc:=f^.wart;
                      break;
                      end;
                   f:=f^.next;
                   end;
             end;

begin
clrscr;
for a:=1 to max do begin
    for b:=1 to max do begin
        randomize;
        if random(15)=10 then tab[a,b]:=random(100) else tab[a,b]:=0;
        write(tab[a,b]:2,' ');
        delay(153);
        end;
        writeln;
    end;
przeksztalc(tab,first);
read(a,b);
write(wartosc(first,a,b));

repeat until keypressed;
end.
