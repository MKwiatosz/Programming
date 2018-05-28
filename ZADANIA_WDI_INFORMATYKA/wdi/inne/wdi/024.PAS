program sumafibonnaciego;
uses crt2;
var licz:integer;
function fib(i:integer):integer;
        var f1,f2,f0,t:integer;
        begin
        if (i=0) then fib:=0
        else
            begin
            f0:=0;
            f1:=1;
            for t:=2 to i do
                begin
                f2:=f0+f1;
                f0:=f1;
                f1:=f2;
                end;
            fib:=f1;
            end;
        end;


function suma(x:integer):boolean;
         var i,t,pom:integer;
         begin
         suma:=false;
         for i:=1 to x do begin
             if fib(i)>x then break;
             if (fib(i)=x)
             or (fib(i)+fib(i+1)=x)
             or (fib(i)+fib(i+1)+fib(i+2)=x)
             or (fib(i)+fib(i+1)+fib(i+2)+fib(i+3)=x) then begin
                                                      suma:=true;
                                                      break
                                                      end;
         end;
         end;

begin
clrscr;
read(licz);
write(suma(licz));
repeat until keypressed;
end.


