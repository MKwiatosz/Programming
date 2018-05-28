{procedura wypisujaca wartosc ulamka A/B z dokladnoscia
do N cyfr dziesietnych. do procedury przekazac:licznik,mianownik
oraz liczbe okreslajaca liczbe miejsc po przecinku}
program ulamekz;
uses crt2;
var a,b,d:integer;
procedure ulamek(licz,mian,n:integer);
          var i:integer;
              wyn,dzies:real;
          begin

          wyn:=licz div mian;
          licz:=licz mod mian;
          dzies:=0.1;
          i:=0;
          if licz<>0 then
          for i:=1 to n do begin
              if licz=0 then break;
              wyn:=wyn+((licz*10) div (mian))*dzies;
              licz:=(licz*10) mod mian;
              dzies:=dzies*0.1;
              end;
          write(wyn:10:i);
          end;

procedure ulamek2(licz,mian,n:integer);
          var i:integer;

          begin
          write(licz div mian);

          licz:=licz mod mian;
          if licz<>0 then begin
             write(',');
             for i:=1 to n do begin
                 if licz=0 then break;
                 write((licz*10) div mian);
                 licz:=(licz*10) mod mian;
                 end;
                 end;

          end;

begin
clrscr;
read(a,b,d);
ulamek2(a,b,d);
repeat until keypressed;
end.