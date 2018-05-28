program zadaniaproste;
uses crt2;
var a:integer;

procedure pitagolas(n:integer);
          var a,b,c,l:integer;
          begin
          l:=0;
          for c:=5 to n do
              begin
              a:=3;
              while (a<c) do
                  begin
                  b:=c-1;
                  while (b>a) and (a*a+b*b>=c*c) do
                      begin
                      l:=l+1;
                      if a*a+b*b=c*c then writeln(a:3,b:3,c:3);
                      b:=b-1;
                      end;
                  a:=a+1;
                  end;
              end;
          writeln(l);
          end;


procedure kwasz;
          var l,i,t,x:integer;
              wyn:boolean;
          begin
          read(l);
          x:=0;
          wyn:=false;
          for i:=2 to trunc(sqrt(l)) do
          begin
          x:=x+1;
          if (l mod (i*i))=0 then
             begin
             t:=2;
             wyn:=true;
             while (t<=i) and (wyn=true) do
                   begin
                   if (l mod (t*t*t))=0 then wyn:=false;

                   t:=t+1;
                   x:=x+1;
                   end;
             end;
          end;
          if wyn then write('tia');
          write(x);
          end;

function  fib(p:integer):integer;
          var i,f0,f1,f2:integer;
          begin
          if p<2 then fib:=1
          else
              begin
              f0:=0;
              f1:=1;
              f2:=1;
              for i:=2 to p do
                  begin
                  f2:=f1+f0;
                  f0:=f1;
                  f1:=f2;
                  end;
              fib:=f1;
              end;
          end;

procedure sumfib(p:integer);
          var t:integer;
          begin
          t:=1;
          while fib(t)<=p do
              begin
              if (fib(t)=p)
                 or (fib(t)+fib(t+1)=p)
                 or (fib(t)+fib(t+1)+fib(t+2)=p)
                 or (fib(t)+fib(t+1)+fib(t+2)+fib(t+3)=p)
                 then begin
                      writeln(p,'no');
                      break;
                      end;
              t:=t+1;
              end;
          end;

procedure systemx(var l:integer;sys:integer);
          var dzies,wyn:integer;
          begin
          dzies:=1;
          wyn:=0;
          while l>0 do
                begin
                wyn:=wyn+dzies*(l mod sys);
                l:=l div sys;
                dzies:=dzies*10;
                end;
          l:=wyn;
          end;

procedure ulamek(licznik,mianownik,dokl:integer);
          var i:integer;
          begin
          write(licznik div mianownik,',');
          i:=0;
          licznik:=licznik mod mianownik;
          while (i<dokl) and (licznik<>0) do
                begin
                licznik:=licznik*10;
                write(licznik div mianownik);
                licznik:=licznik mod mianownik;
                i:=i+1;
                end;
          writeln;
          end;

function  fib3(p:integer):integer;
          var i,f4,f1,f2,f3:integer;
          begin
          if p<4 then fib3:=1
          else
              begin
              f1:=1;
              f2:=1;
              f3:=1;
              for i:=4 to p do
                  begin
                  f4:=f1+f2+f3;
                  f1:=f2;
                  f2:=f3;
                  f3:=f4;
                  end;
              fib3:=f3;
              end;
          end;


procedure wypciag(l:integer);
          var i2,i3,max:integer;
          begin
          i2:=2;
          i3:=2;
          max:=fib(i2);
          write(max,' ');
          while (fib3(i3)<=l) or (fib(i2)<=l) do
                begin
                if fib3(i3)=fib(i2) then
                   begin
                   if (fib(i2)>max) and (fib(i2)<=l) then
                   begin
                        max:=fib(i2);
                        write(max,' ');
                   end;
                   i2:=i2+1;
                   i3:=i3+1;
                   end;
                if fib3(i3)>fib(i2) then
                   begin
                   if (fib(i2)>max) and (fib(i2)<=l) then
                      begin
                      max:=fib(i2);
                      write(max,' ');
                      i2:=i2+1;
                      end
                   else
                       if (fib3(i3)<=l) then
                          begin
                          max:=fib3(i3);
                          write(max,' ');
                          i3:=i3+1;
                          i2:=i2+1;
                          end;
                   end;
                if fib3(i3)<fib(i2) then
                   begin
                   if (fib3(i3)>max) and (fib3(i3)<=l) then
                      begin
                      max:=fib3(i3);
                      write(max,' ');
                      i3:=i3+1;
                      end
                   else
                       if fib(i2)<=l then
                          begin
                          max:=fib(i2);
                          write(max,' ');
                          i2:=i2+1;
                          i3:=i3+1;
                          end;
                   end;
                end;
          end;


begin
clrscr;
writeln(fib3(7));
wypciag(40);
{pitagolas(40);
kwasz;
write(fib(6));
for a:=1 to 21 do sumfib(a);

a:=6;
systemx(a,2);
write(a);
ulamek(5,1,4);
ulamek(13,2,11);
ulamek(100,3,5);  }

repeat until keypressed
end.