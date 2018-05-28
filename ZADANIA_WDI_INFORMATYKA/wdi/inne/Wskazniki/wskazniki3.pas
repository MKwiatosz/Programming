program wskaznikii;
type
        pwezel = ^wezel;
        wezel = record
                next : pwezel;
                prev : pwezel
        end;

procedure wstaw(var p : pwezel; element : pwezel; n : integer);
var
        i : integer;
        q : pwezel;
begin
        if n = 1 then
        begin
                element^.prev := nil;
                element^.next := p^.next;
                p^.prev := element;
                p := element;
        end
        else
        begin
                q := p;
                for i := 1 to n-1 do
                        q := q^.next;
                q^.prev^.next := element;
                element^.prev := q^.prev;
                q^.prev := element;
                element^.next := q;
        end;
end;

begin
end.


