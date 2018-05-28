program sumaotjeswiekodniego;
uses crt2;
const n=5;
type tablica=array[1..n,1..n] of integer;

function sasiedzi(var t:tablica):integer;
         var k,l,i,j,najw:integer;
         function suma(i,j:integer):integer;
                  var k,l,s:integer;
                  begin
                  s:=-t[i,j];
                  for k:=i-1 to i+1 do
                      for l:=j-1 to j+1 do
                          if (k>0) and (k<n) and (l>0) and (l<n) then
                          s:=s+t[k,l];
                  end;
         begin
         najw:=suma(0,0);
         k:=1;
         l:=1;
         for i:=0 to n do
             for j:=0 to n do
                 if suma(i,j)>najw then begin
                    najw:=suma(i,j);
                    k:=i;
                    l:=j;
                    end;
                 sasiedzi:=t[k,l];
         end;
begin
end.
