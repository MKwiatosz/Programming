program cykl;
type
        pwezel = ^wezel;
        wezel = record
                nr : integer;
                next : pwezel
        end;

function dlugosc(p : pwezel) : integer;
var
        q : pwezel;
begin
        q := p;
        repeat
                q := q^.next;
                p := p^.next^.next;
        until p = q;
        dlugosc := 1;
        repeat
                dlugosc := dlugosc + 1;
                p := p^.next;
        until p = q
end;

begin
end.
