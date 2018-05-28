program tabliceod6;
uses crt2;
const max1=7;
      max2=5;
type
    d1=array[1..max1] of boolean;
    d2=array[1..max2] of d1;

procedure sortuj(var inp,out:d2);
          var i,j,najw:integer;
              najw:d1;
              sprawdz:array[1..max2] of boolean;
          begin
          for i:=1 to max2 do sprawdz[i]:=true;
          i:=1;
          najw:=out[]
          while (i<=max2) and sprawdz[i] then
                begin



                i:=inc(i);
                end;
          end;




begin
clrscr;

repeat until keypressed
end.