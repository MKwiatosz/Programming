program hanoi;

procedure przenies(z, pomocniczy, na: string; ile: integer);
begin
    if ile > 0 then
    begin
        przenies(z, na, pomocniczy, ile-1);
        writeln(z, '->', na);
        przenies(pomocniczy, z, na, ile-1)
    end;
end;

begin
    przenies('1', '2', '3', 4)
end.