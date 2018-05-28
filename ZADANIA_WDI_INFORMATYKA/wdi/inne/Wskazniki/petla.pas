program petla;

type
        wskaznik_elementu = ^element;
        element = record
                  wartosc : integer;
                  next : wskaznik_elementu;
                  end;

var
        p, q, s : wskaznik_elementu;
        i : integer;

begin
        q := p;
        s := p;
        repeat                  {szukamy gdzie wskazniki sie spotkaja}
                q := q^.next;
                s := s^.next^.next
        until q = s;
        i := 0;                 {zapetlenie na dlugosc 0}
        repeat
                q := q^.next;   {sprawdz dlugosc petli}
                i := i + 1;
        until q = s
end.


