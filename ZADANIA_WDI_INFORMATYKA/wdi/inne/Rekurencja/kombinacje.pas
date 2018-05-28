program wypisz_podzbiory;

{s - zbior wyjsciowy,
 r - podzbiory
 n - indeks aktualnej litery z s
 k - k-elementowa kombinacja}

procedure podzbiory(s, r: string; n, k: integer);
begin
    if n > length(s) then
    begin
        if length(r) = k then
            writeln(r)
    end
    else
    begin
        if length(r) < k then                    {jeszcze mozemy doklejac}
            podzbiory(s, r + s[n], n + 1, k);    {wez litere}
        podzbiory(s, r, n + 1, k);               {nie bierz litery}
    end;
end;

begin
    podzbiory('abcde','', 1, 3);
end.