{mantysa jest reprezentowana w kodzie U2, kropka polozona jest na prawo
od mantysy. mantysa jest znormalizowana gdy najbardziej znaczacy bit
mantysy jest rowny 1. cecha dana jest w postaci liczby typu integer.
zmienna typu integer zajmuje 2 bajty. prosze napisac procedure dodajaca dwie
znormalizowane liczby typu bigfloat. procedura powinna sygnalizowac
wystapienie nadmiaru zmiennoprzecinkowego}
program tab_12_zmienno_dod;
uses crt2;
const max=6;
type bit=0..1;
     bigfloat=record
                    m:array[0..max] of bit;
                    c:integer;
                    end;
var u,o:integer;
    qq,qqq,qqqq:bigfloat;

procedure suma(var l1,l2,l:bigfloat);   {tylko dodatnie}
          var i,t,roz:integer;

          procedure sum(var l11,l22,lww:bigfloat);
                    var x,s:integer;
                        next:bit;

                    begin
                    repeat
                    next:=0;
                    for x:=max downto 0 do lww.m[x]:=0;
                    for x:=max downto 0 do
                        begin
                        s:=l11.m[x]+l22.m[x]+next;
                        if ((s div 2))=1 then next:=1 else next:=0;
                        if ((s mod 2))=1 then lww.m[x]:=1;
                        end;

                    if lww.m[0]=0 then
                      if lww.c=32767 then
                         begin
                         lww.c:=-1313;
                         break;
                         end
                      else
                       begin
                       if l11.c>=l22.c then
                          lww.c:=l11.c+1
                       else lww.c:=l22.c+1;
                       for x:=max downto 1 do
                           begin
                           l11.m[x]:=l11.m[x-1];
                           l22.m[x]:=l22.m[x-1];
                           end;
                       l11.m[0]:=0;
                       l22.m[0]:=0;
                       end;
                    until lww.m[0]=1;
                    end;


          begin
          if l1.c=l2.c then
             begin
             l.c:=l1.c+1;
             if l1.c=32767 then l.c:=-1313;
             for i:=max downto 1 do
                 begin
                 l1.m[i]:=l1.m[i-1];
                 l2.m[i]:=l2.m[i-1];
                 end;
             l1.m[0]:=0;
             l2.m[0]:=0;
             sum(l1,l2,l);
             end;

          if l1.c>l2.c then
             begin
             roz:=l1.c-l2.c;
             l.c:=l1.c;
             for i:=max downto roz do
                 begin
                 l2.m[i]:=l2.m[i-roz]
                 end;
             for i:=0 to roz-1 do l2.m[i]:=0;
             sum(l1,l2,l);
             end;

          if l1.c<l2.c then
             begin
             roz:=l2.c-l1.c;
             l.c:=l2.c;
             for i:=max downto roz do
                 begin
                 l1.m[i]:=l1.m[i-roz]
                 end;
             for i:=0 to roz-1 do l1.m[i]:=0;
             sum(l1,l2,l);
             end;

          end;

begin
clrscr;
qq.m[0]:=1;
qqq.m[0]:=1;
qq.c:=32767;
qqq.c:=32766;
for u:=1 to max do
    begin
    read(o);
    qq.m[u]:=o;
    end;
writeln;
for u:=1 to max do
    begin
    read(o);
    qqq.m[u]:=o;
    end;

suma(qq,qqq,qqqq);
for u:=0 to max do write(qqqq.m[u]);
write(' 2^',qqqq.c);

repeat until keypressed;
end.