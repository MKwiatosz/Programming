program listawielomian;
uses crt2;
type link=^node;
     node=record
                wsp:integer;
                wyk:integer;
                next:link;
                end;

procedure wypisz(p:link);
          begin
          while p<>nil do
                begin
                if p^.wsp>0 then write('+');
                write(p^.wsp,'x^',p^.wyk);
                p:=p^.next;
                end;
          end;

var first,w:link;
    wspo,wykl:integer;
begin
clrscr;
first:=nil;
wspo:=0;
while wspo<>-1 do begin
      read(wspo,wykl);
      writeln('next');
      new(w);
      w^.next:=first;
      w^.wsp:=wspo;
      w^.wyk:=wykl;
      first:=w;
end;

wypisz(w);
repeat until keypressed;
end.