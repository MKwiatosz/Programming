program wariacje;

procedure war(s, r: string; k: integer);
var
    i : integer;
    pociete_s : string;
begin
    if length(r) = k then
        writeln(r)
    else
        for i := 1 to length(s) do
        begin
            {wytnij i-ta litere ze stringa}
            pociete_s := copy(s, 1, i - 1) + copy(s, i+1, length(s) - i);
            war(pociete_s, r + s[i], k);
        end;
end;

begin
    war('abc', '', 3);
end.
