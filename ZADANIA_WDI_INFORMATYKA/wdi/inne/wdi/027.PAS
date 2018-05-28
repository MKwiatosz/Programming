program ciagi;
uses crt2;
var licz:integer;

function fib2(n:integer):integer;
         var i,f0,f1,f2:integer;
         begin
         f0:=0;
         f1:=1;
         for i:=2 to n do
             begin
             f2:=f1+f0;
             f0:=f1;
             f1:=f2;
             end;
         fib2:=f1;
         end;

function fib3(n:integer):integer;
         var i,f0,f1,f2,f3:integer;
         begin
         f0:=1;
         f1:=1;
         f2:=1;
         f3:=1;
         for i:=4 to n do
             begin
             f3:=f0+f1+f2;
             f0:=f1;
             f1:=f2;
             f2:=f3;
             end;
         fib3:=f2;

         end;

procedure wypisz(n:integer);
          var zbior:set of 1..250;
              i:integer;
          begin
          zbior:=[ ];
          i:=1;
          while fib2(i)<=n do
                begin
                zbior:=zbior+[fib2(i)];
                i:=i+1;
                end;
          i:=1;
          while fib3(i)<=n do
                begin
                zbior:=zbior+[fib3(i)];
                i:=i+1;
                end;

          for i:=1 to n do if (i in zbior) then write(i,' ');
          end;

procedure wypisz2(n:integer);
          var i,t,pom:integer;
          begin
          if n=1 then write('1 ') else
             if n=2 then write('1 2 ') else begin
          i:=3;
          repeat

                t:=3;
                while fib2(t)<fib3(i) do
                      begin
                      if (fib2(t)>fib3(i-1)) and (fib2(t)<=n) then write(fib2(t),' ');
                      t:=t+1;



                      end;
                if fib3(i)<=n then write(fib3(i),' ');
                i:=i+1;
          until (fib3(i)>n) and (fib2(i)>n);
          end;
          end;

begin
clrscr;
read(licz);
wypisz(licz);
writeln;
wypisz2(licz);
repeat until keypressed;
end.
