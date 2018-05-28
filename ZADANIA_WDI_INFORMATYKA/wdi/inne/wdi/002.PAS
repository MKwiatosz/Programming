program dwienajwzwielu;
uses crt2;
var min,max1,max2:integer;
begin
clrscr;
if not eof then
   begin
   read(max1);
   max2:=max1;
   while not eof do begin
         read(min);
         if min>max1 then begin
            max2:=max1;
            max1:=min
            end
         else if (max2<min) and (max2<>max1) then max2:=min;
         end;
end;
writeln(max1,max2);
repeat until keypressed;
end.