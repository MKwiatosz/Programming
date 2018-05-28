program najwzwielu;
uses crt2;
var min,max:integer;
begin
clrscr;
if not eof then begin
   read(max);
   while not eof do begin
         read(min);
         if min>max then max:=min;
         end
   end;
repeat until keypressed;
end.
