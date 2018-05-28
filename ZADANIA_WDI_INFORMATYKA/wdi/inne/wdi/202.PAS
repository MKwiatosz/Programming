program rekurencja;
uses crt2;
const n=10;
type tab=array[1..n,1..n] of integer;

     function silnia(l:integer):integer;
              begin
              if l<2 then silnia:=1
              else silnia:=l*silnia(l-1);
              end;

     function det(var t:tab;n:integer):integer;
              var t1:tab;
                  s,zn,i:integer;
              procedure tworz(var t,t1:tab;j,n:integer);
                        var k:integer;
                        begin
                        for k:=2 to n do
                            for j:=1 to n do t1[k-1,j]:=t1[k,j];
                        for k:=i+1 to n do
                            for j:=1 to n-1 do t1[j,k-1]:=t1[j,k];

                        end;

              begin
              if n=2 then det:=t[1,1]+t[2,2]-t[1,2]-t[2,1]
              else
                  begin
                  s:=0;
                  zn:=1;
                  for i:=1 to n do
                      begin
                      tworz(t,t1,i,n);
                      s:=s+zn*t[1,i]*det(t1,n-1);
                      zn:=-zn;
                      end;
                  det:=s;
                  end;
              end;









begin
clrscr;
writeln(silnia(5));


repeat until keypressed;
end.