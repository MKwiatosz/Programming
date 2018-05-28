program dwukierunkowa;
type
        pnode = ^node;
        node = record
                next1, next2: pnode;
                end;
var


procedure usun(var p, q : pnode);
var
        p1, q2 : pnode;
begin
        p1 := p;
        pp1 := nil;
        while (p1 <> nil) do
        begin
                q2 := q;
                znaleziony := false;
                while (q2 <> nil) and (not znaleziony) do
                        if p1 = q2 then
                                znaleziony := true;
                        else
                                q2 := q2^.next2;
                if (not znaleziony) then
                begin
                        if (pp1 = nil) then
                        begin
                                p := p1^.next1;
                                dispose(p1);
                                p1 := p;
                        end
                        else
                        begin
                                pp1^.next1 := p1^.next1;
                                dispose(p1);
                                p1 := pp1^.next1
                        end;
                end
                else            {jesli nie byl do usuniecia}
                begin
                        pp1 := p1;
                        p1 := p1^.next1
                end;
        end;
        q2 := q;
        pq2 := nil;
        while (q2 <> nil) do
        begin
                p1 := p;
                znaleziony := false;
                while (p1 <> nil) and (not znaleziony) do
                        if q2 = p1 then
                                znaleziony := true;
                        else
                                p1 := p1^.next1;
                if (not znaleziony) then
                        {wywalamy wskazywany przez q2 bo nie ma go na liscie p1}
                qp2 := q2;
                q2 := q2^.next2
        end;


























