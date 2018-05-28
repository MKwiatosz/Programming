var i,j,k,a,n,licznik:integer;
begin
    readln(n); licznik:=-1;
    i:=1;j:=1;k:=1;
    while i<=n do begin
       while i*j<=n do begin
          while i*j*k<=n do begin
                a:=i*j*k;
                if a<> 1 then writeln(a);
                k:=k*5;
                inc(licznik);
          end;
          j:=j*3;
          k:=1;
       end;
       i:=i*2;
       j:=1;
    end;
    writeln('ilosc: ',licznik);
end.
