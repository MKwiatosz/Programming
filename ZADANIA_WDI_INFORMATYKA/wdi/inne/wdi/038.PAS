{typ table opisuje tablice zawierajaca max1 wierszy po max2 elementow
prosze napidac funkcje ktora dla zmiennej typu table zwraca ilosc wierszy
w ktorych liczby stanowia ciagi arytmetyczne}
program tab_9_ciagi;
uses crt2;
const max1=10;
      max2=3;
type  wiersz=array[1..max2] of integer;
      table=array[1..max1] of wiersz;
      var tab:table;
          a,b:integer;
function ciagi(t:table):integer;
         var i,x,z,licznik,roz,a1,a2,wynik,pom:integer;
         begin

         wynik:=0;

      for x:=1 to max1 do
         begin
         a1:=t[x][1];
         a2:=t[x][2];
         if a1>a2 then
            begin
            pom:=a1;
            a1:=a2;
            a2:=pom;
            end;
         if a1=a2 then {dokonczyc dla ciagu stalego}

         else begin
         for i:=2 to max2 do
             begin
             if t[x][i]<a1 then
                begin
                a2:=a1;
                a1:=t[x][i];
                end
             else
                if (t[x][i]<a2) and (t[x][i]<>a1)then a2:=t[x][i];
             end;
         roz:=a2-a1;
         licznik:=2;
         a2:=a2+roz;
         for i:=1 to max2 do if (t[x][i]=a2) then
             begin
             licznik:=licznik+1;
             a2:=a2+roz;
             end;
         if licznik=max2 then wynik:=wynik+1;
         end;
         end;

         ciagi:=wynik;
         end;

begin
clrscr;
for a:=1 to max1 do begin
    for b:=1 to max2 do
        begin
        randomize;
        tab[a][b]:=random(4);
        write(tab[a][b],' ');
        delay(153);
        end;
        writeln;
    end;

write(ciagi(tab));
repeat until keypressed;
end.