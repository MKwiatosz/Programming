{procedura ktora dla zmiejjej typu tablica zwraca wspolrzedne elementu t[i,j]
dla ktorego iloraz miedzy suma elementow w i-tej kolumnie
a suma elementow w wierszu j-tym jest okreslony(uwaga na div 0)
i najwiekszy}
program tab2_ilrazkolumnwierszy;
uses crt2;
const max1=5;
      max2=2;
type  tablica=array[1..max1,1..max2] of integer;
var t:tablica;
    k,w:integer;
procedure nilo(var tab:tablica;var wspi,wspj:integer);{metoda czolgowa}
          var i,j:integer;
              najw:real;
          function iloraz(x,y:integer):real;
                   var b,a,sumax,sumay:integer;
                   begin
                   sumax:=0;
                   sumay:=0;
                   for b:=1 to max1 do sumax:=sumax+tab[b,y];
                   for a:=1 to max2 do sumay:=sumay+tab[x,a];
                   if sumay=0 then iloraz:=-1
                   else iloraz:=sumax/sumay;

                   end;

          begin
          najw:=iloraz(1,1);
          wspi:=1;
          wspj:=1;
          for i:=1 to max1 do
              for j:=1 to max2 do
                  if iloraz(i,j)>najw then
                     begin
                     wspi:=i;
                     wspj:=j;
                     najw:=iloraz(i,j);
                     end;

          end;
begin
clrscr;
for k:=0 to max1 do
    begin
    for w:=1 to max2 do
        begin
        randomize;
        t[k,w]:=random(6);
        write(t[k,w],' ');
        delay(153);
        end;
        writeln;
    end;

nilo(t,k,w);
write('t[',k,',',w,']');

repeat until keypressed;
end.