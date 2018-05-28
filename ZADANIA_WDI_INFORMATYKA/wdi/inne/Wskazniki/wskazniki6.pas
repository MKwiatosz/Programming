program nadmiar;
type
        pwezel = ^wezel;
        wezel = record
                val : integer;
                next : pwezel
        end;

procedure usun(p : pwezel);
var
        q, s, tmp : pwezel;
        usuwany : integer;
begin
        q := p;
        repeat
                usuwany := q^.val;
                s := q;
                repeat
                        tmp := s;
                        s := s^.next;
                        if s^.val = usuwany then
                        begin
                                tmp^.next := s^.next;
                                dispose(s);
                                s := tmp^.next;
                        end;
                until s = q;
                q := q^.next;
        until p = q
end;

begin
end.