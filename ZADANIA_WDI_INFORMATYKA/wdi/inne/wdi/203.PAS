program pointery;
uses crt2;
const n=10;
type pnode=^node;
     node=record
                next:pnode;
                w:integer;
                end;
type plink=^link;
     link=record
                next:plink;
                pot,wsp:integer;
                end;


var f:pnode;
    g:plink;

     procedure tworz(var f:pnode);
               var i:integer;
                   p:pnode;
               begin
               f:=nil;
               for i:=1 to n do
                   begin
                   new(p);
                   p^.next:=f;
                   p^.w:=i;
                   f:=p;
                   end;
               end;


     procedure tworzw(var g:plink);
               var i,zn:integer;
                   p:plink;
               begin
               g:=nil;
               zn:=1;
               for i:=1 to n do
                   begin
                   new(p);
                   p^.next:=g;
                   p^.wsp:=zn*i;
                   p^.pot:=n-i;
                   g:=p;
                   zn:=-zn;
                   end;
               end;

     procedure wypiszj(f:pnode);
               begin
               while f<>nil do begin
                     write(f^.w,' ');
                     f:=f^.next;
                     end;
               end;

     procedure wypiszw(g:plink);
               begin
               while g<>nil do
                     begin
                     if g^.wsp>=0 then write('+');
                     write(g^.wsp,'x^',g^.pot);

                     g:=g^.next;
                     end;
               end;

     procedure wstawza(var f:pnode);
               var p,fir:pnode;
               begin
               fir:=f;
               f:=nil;
               if f=nil then
                  begin
                  new(p);
                  p^.next:=f;
                  p^.w:=13;
                  f:=p;
                  end
               else
                   begin
                   new(p);
                   p^.next:=f^.next;
                   p^.w:=13;
                   f^.next:=p;
                   f:=fir;
                   end;

               end;

     procedure usun(var f:pnode);
               var r,p:pnode;
               begin
               p:=f^.next^.next;
               if f=nil then halt;
               if p=nil then
                  begin  {usun pierwszy}
                  r:=f;
                  f:=f^.next;
                  dispose(r);
                  end
               else
                   begin
                   r:=p^.next;
                   if r=nil then halt;
                   p^.next:=p^.next^.next;
                   dispose(r);

                   end;
               end;

begin
clrscr;
tworz(f);
wypiszj(f);
writeln;{
tworzw(g);
wypiszw(g);
wstawza(f); }
usun(f);
wypiszj(f);
repeat until keypressed;
end.