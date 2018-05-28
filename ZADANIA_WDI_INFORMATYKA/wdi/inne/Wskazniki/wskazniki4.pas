program usuwanie;
type
        pwezel = ^wezel;
        wezel = record
                next : pwezel;
                prev : pwezel
        end;

procedure usun(var p : pwezel; n : integer);
var
        q : pwezel;
        i : integer;
begin
        q := p;
        if (p <> nil) then
                if n = 1 then
                begin
                        q := q^.next;
                        dispose(p);
                        end
                else
                begin
                        i := 2;
                        while (i <= n) and (q <> nil) do
                        begin
                                q := q^.next;
                                i := i + 1;
                        end;
                        if (q <> nil) then
                        begin
                                q^.prev^.next := q^.next;
                                if (q^.next <> nil) then
                                        q^.next^.prev := q^.prev;
                                dispose(q);
                                q := p;
                        end;
                end;
end;

begin
end.

