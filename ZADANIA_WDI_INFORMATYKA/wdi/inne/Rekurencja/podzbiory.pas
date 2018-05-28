program wypisz_podzbiory;

{s - zbior wyjsciowy,
 r - podzbiory
 n - indeks aktualnej litery z s}

procedure podzbiory(s, r: string; n: integer);
begin
    if n > length(s) then
        if r = '' then
            writeln('{}')
        else
            writeln(r)
    else
    begin
        {wez litere}
        podzbiory(s, r + s[n], n + 1);
        {nie bierz litery}
        podzbiory(s, r, n + 1);
    end;
end;

begin
    podzbiory('abc','', 1);
end.