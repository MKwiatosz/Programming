program skoczek;

const
    N = 5;

type
    polozenie = record
                wiersz, kolumna : integer;
                end;

var
    tu_bylam: array [1..N, 1..N] of boolean;
    droga: array [1..N*N] of polozenie;
    i, j : integer;

procedure skocz(numer_skoku: integer; wiersz, kolumna: integer);
var
   i : integer;
begin
    {sprawdzamy czy jestesmy dalej na szachownicy i czy juz tu nie bylismy}
    if (wiersz <= N) and (wiersz >= 1) and (kolumna <= N) and (kolumna >= 1) and (not tu_bylam[wiersz, kolumna]) then
    begin
        {zapamietujemy pole na ktorym jestesmy}
        droga[numer_skoku].wiersz := wiersz;
        droga[numer_skoku].kolumna := kolumna;
        {zaznaczamy ze tu juz bylismy}
        tu_bylam[wiersz, kolumna] := true;
        if numer_skoku = N*N then       {przeszlismy cala szachownice}
        begin
            {wypisywanie kolejnosci skokow}
            writeln('Rozwiazanie:');
            for i := 1 to N*N do
                write('(', droga[i].wiersz, ',', droga[i].kolumna, ') ');
            writeln();
            writeln();
        end
        else
        begin
            {skaczemy na mozliwe pola}
            skocz(numer_skoku + 1, wiersz - 1, kolumna - 2);
            skocz(numer_skoku + 1, wiersz - 2, kolumna - 1);
            skocz(numer_skoku + 1, wiersz - 2, kolumna + 1);
            skocz(numer_skoku + 1, wiersz - 1, kolumna + 2);
            skocz(numer_skoku + 1, wiersz + 1, kolumna + 2);
            skocz(numer_skoku + 1, wiersz + 2, kolumna + 1);
            skocz(numer_skoku + 1, wiersz + 2, kolumna - 1);
            skocz(numer_skoku + 1, wiersz + 1, kolumna - 2);
        end;
        tu_bylam[wiersz, kolumna] := false {wycofujemy sie z pola bo inaczej nie bedzie gdzie skoczyc}
    end;
end;

begin
    {inicjalizacja tablicy tu_bylam}
    for i := 1 to N do
        for j := 1 to N do
            tu_bylam[i, j] := false;

    skocz(1, 1, 1);
end.





