program wariacje_z_powtorzeniami;

procedure war(s, r: string; k: integer);

var
    i : integer;

begin
    if length(r) = k then
        writeln(r)
    else
        for i := 1 to length(s) do
            war(s, r + s[i], k);
end;

begin
    war('abcd', '', 2);
end.