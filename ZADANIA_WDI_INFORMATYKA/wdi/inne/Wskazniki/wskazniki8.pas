program struktura;
const
        max = 3;
type
        pwezel = ^element;
        element = record
                w : integer;
                i : integer;
                j : integer;
                next : pwezel
        end;
        tablica = array[1..max, 1..max] of integer;
var
        T : tablica = ((1,0,7),(0,2,0),(3,1,0));
        x : pwezel;

function przeksztalc (var T : tablica) : pwezel;
var
        p, q : pwezel;
        i, j : integer;
begin
        przeksztalc := nil;
        for i := 1 to max do
                for j := 1 to max do
                begin
                        if przeksztalc = nil then
                        begin
                                new(p);
                                przeksztalc := p;
                        end
                        else
                        begin
                                new(p^.next);
                                p := p^.next;
                        end;
                        p^.next := nil;
                        if T[i,j] <> 0 then
                        begin
                                p^.w := T[i,j];
                                p^.i := i;
                                p^.j := j;
                        end;
                end;
end;


function zwroc(i, j : integer; tab : pwezel) : integer;
begin
        zwroc := 0;
        while (tab <> nil) and (zwroc = 0) do
        begin
                if (tab^.i = i) and (tab^.j = j) then
                        zwroc := tab^.w;
                tab := tab^.next
        end;
end;

begin
        x := przeksztalc(T);
        writeln(zwroc(1, 3, x));
        writeln(zwroc(2, 1, x));
end.






