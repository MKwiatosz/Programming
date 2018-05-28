program usunpowtarzajacesie;
type
        pwezel = ^wezel;
        wezel = record
                val : integer;
                next : pwezel
        end;

procedure usun (var p, q : pwezel);
var
        curr1, curr2, prev1, prev2, tmp : pwezel;
begin
        prev1 := nil;
        curr1 := p;
        prev2 := nil;
        curr2 := q;
        while (curr1 <> nil) and (curr2 <> nil) do
        begin
                if curr1^.val = curr2^.val then
                begin {usun je}
                        prev1 := curr1;
                        dispose(curr1);
                        curr1 := prev1^.next;
                        prev2 := curr2;
                        dispose(curr2);
                        curr2 := prev2^.next
                end
                else
                        if curr1^.val > curr2^.val then
                                curr2 := curr2^.next
                        else
                                curr1 := curr1^.next
        end;
end;

begin
end.




