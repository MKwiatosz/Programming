program trojkapitagorejska;
uses crt2;
var n:integer;

procedure pitagoras(n:integer);
         var a,b,c:integer;
         begin
         for a:=1 to n-1 do
             for b:=n-1 downto a do
                 for c:=1 to n do
                 begin
                 if c*c=a*a+b*b then writeln(a,' ',b,' ',c);
             end;
          end;


begin
clrscr;
read(n);
pitagoras(n);
repeat until keypressed;
end.