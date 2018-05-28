{program ktory wczytuje wprowadzony z klawiatury ciag liczb rzeczywistych
dodatnich zakonczony liczba -1 bedaca znacznikiem konca i umieszcza
max najwiekszych elementow w tablicy tab.
mozna zalozyc ze ciag zawiera co najmniej max liczb}
program tab_11_max;
uses crt2;
const max=5;
var tab:array[1..max] of real;
    licz,najm:real;
    i,t,wsp:integer;


begin
clrscr;
for i:=1 to max do tab[i]:=0;
licz:=0;
i:=1;
while licz<>-1 do
      begin
      read(licz);
      if licz>0 then
      begin
      if i<max then tab[i]:=licz
      else
          begin
          najm:=tab[1];
          wsp:=1;
          for t:=2 to max-1 do if tab[t]<najm then
              begin
              wsp:=t;
              najm:=tab[t];
              end;

          if licz>najm then tab[wsp]:=licz;
          tab[max]:=-1;
          end;
      i:=i+1;
      end;
      end;


for i:=1 to max do write(tab[i]:3:0,' ');
repeat until keypressed;
end.