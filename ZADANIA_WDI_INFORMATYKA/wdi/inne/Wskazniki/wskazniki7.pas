program sumamnogosciowa;
type
        pwezel = ^wezel;
        wezel = record
                val : integer;
                next : pwezel
        end;

function suma(var p, q : pwezel) : pwezel;
var
        s, t : pwezel;
begin
        suma := nil;
        while (p <> nil) or (q <> nil) do
        begin
        	if suma = nil then
        	begin
        		new(s);
        		suma := s;
        	end
        	else
        	begin
        		new(s^.next);
        		s := s^.next;
        	end;
        	s^.next := nil;
                if (q=nil) or (p^.val < q^.val) then
                begin
                        s^.val := p^.val;
                        t := p^.next;
                        dispose(p);
                        p := t;
                end
                else
                        if (p=nil) or (p^.val > q^.val) then
                        begin
                                s^.val := q^.val;
                                t := q^.next;
                                dispose(q);
                                q := t;
                        end
                        else
                        begin
                                s^.val := p^.val;
                                t := p^.next;
                                dispose(p);
                                p := t;
                                t := q^.next;
                                dispose(q);
                                q := t;
                        end;
                s := s^.next;
        end;
end;

begin
end.
