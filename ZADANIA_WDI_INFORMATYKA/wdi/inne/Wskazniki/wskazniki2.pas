program dwukierunkowa1;
const
        n = 10;
type
        pwezel = ^wezel;
        wezel = record
                next : pwezel;
                prev : pwezel
        end;

procedure usun(var p : pwezel; n : integer);
var
        i : integer;
begin
        i := 1;
        while (p <> nil) and (i < n) do
        begin
                        i := i + 1;
                        p := p^.next;
        end;
        if (p <> nil) then
        begin
                if (p^.next <> nil) then
                        p^.next^.prev := p^.prev;
                if (p^.prev <> nil) then
                        p^.prev^.next := p^.next;
                dispose(p);
        end;
end;


