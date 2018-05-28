program funkcjaah;
uses crt2;
var va,vb:integer;
    function ah(a,b:integer):integer;
             begin
             if a=0 then ah:=b+1 else
                if b=0 then ah:=ah(a-1,1) else
                   ah:=ah(a-1,ah(a,b-1));

             end;
begin
clrscr;
read(va,vb);
write(ah(va,vb));
repeat until keypressed;
end.