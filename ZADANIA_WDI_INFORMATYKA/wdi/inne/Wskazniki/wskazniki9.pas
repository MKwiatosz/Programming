program iloczynmnogosciowy;
type
        pwezel = ^wezel;
        wezel = record
                val : integer;
                next : pwezel
        end;

procedure iloczyn(var p, q, pocz : pwezel);
var
        s, a : pwezel;
begin
        pocz := nil;
        while (p <> nil) or (q <> nil) do
        begin
                if q^.val = p^.val then
                begin
                        if pocz = nil then
                        begin
                                new(s);
                                pocz := s;
                        end
                        else
                        begin
                                new(s^.next);
                                s := s^.next;
                        end;
                        s^.next := nil;
                        s^.val := q^.val;
                        a := q^.next;
                        dispose(q);
                        q := a;
                        a := p^.next;
                        dispose(q);
                        q := a;
                end
                else
                begin
                        if q^.val > p^.val then
                        begin
                                a := p^.next;
                                dispose(p);
                                p := a;
                        end;
                        if q^.val < p^.val then
                        begin
                                a := q^.next;
                                dispose(q);
                                q := a;
                        end;
                end;
        end;
end;

begin
end.






