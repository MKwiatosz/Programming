program permutacje;

procedure perm(s, r: string);
var
    i : integer;
    pociete_s : string;
begin
    if length(s) = 0 then
        writeln(r);

    for i := 1 to length(s) do
    begin
        {wytnij i-ta litere ze stringa}
        pociete_s := copy(s, 1, i - 1) + copy(s, i+1, length(s) - i);
        perm(pociete_s, r + s[i]);
    end;
end;

begin
    perm('belki', '');
end.