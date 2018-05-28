program wstawianiedolancucha;
uses crt2;
type pnode=^node;
     node=record
                w:integer;
                next:pnode;
                end;
var first:pnode;
procedure wstaw(var f:pnode;w:integer;p:pnode);
          var r:pnode;
          begin
          new(r);
          r^.w=w;
          if p=nil then begin
             r^.next:=f;
             f:=r
             end
          else begin
               r^.next:=p^.next;
               p^.next:=r;
               end
          end;
procedure usun(var f:pnode);
          var r:pnode;
          begin
          if f=nil then halt;
          if p=nil then begin
             r:=f;
             f:=f^.next;
             disopse(r);
             end
          else begin
               r:=p^.next
               if r=nil then halt;
               p^.next:=p^.next^.next;
               dispose(r);
               end;
          end;
