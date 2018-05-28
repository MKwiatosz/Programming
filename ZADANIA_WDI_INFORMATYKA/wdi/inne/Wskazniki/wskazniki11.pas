program odwroconalista;
type
        pwezel = ^wezel;
        wezel = record
                val : integer;
                next : pwezel
        end;

procedure odwroc(var q : pwezel);
var
        nastepny, poprzedni : pwezel;
begin
        poprzedni := nil;
        while (q^.next <> nil) do
        begin
                nastepny := q^.next;
                q^.next := poprzedni;
                poprzedni := q;
                q := nastepny
        end;
        nastepny^.next := poprzedni;
end;

begin
end.