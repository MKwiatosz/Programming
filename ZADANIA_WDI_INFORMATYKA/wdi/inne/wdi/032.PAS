{typ longint opisuje liczbe staloprzecinkowa kodowana w kodzie U2
bit znaku znajduje sie na pozycji 0
prosze napisac procdure zmieniajaca znak liczby typu longint na
procedura powinna sygnalizowac wystapienie nadmiaru}
program tab_4_zmianaznakuU2;
uses crt2;
const max=7;
type  bit=0..1;
      longint=array[0..max] of bit;
var licz:longint;
    z,x:integer;

procedure zmien(var t:longint);
          var i:integer;
              ost:bit;
          begin
          ost:=t[0];
          for i:=max downto 0 do  {zmiana 0 na 1 i odwrotnie}
              if t[i]=0 then t[i]:=1 else t[i]:=0;

          for i:=max downto 0 do
              if t[i]=0 then
                 begin
                 t[i]:=1;
                 break;
                 end
              else t[i]:=0;
          if (ost=t[0]) and (t[0]=1) then write('dupa ');

          end;


begin
clrscr;
for z:=0 to max do
    begin
    read(x);
    licz[z]:=x;
    end;
zmien(licz);
for z:=0 to max do write(licz[z]);

repeat until keypressed;
end.