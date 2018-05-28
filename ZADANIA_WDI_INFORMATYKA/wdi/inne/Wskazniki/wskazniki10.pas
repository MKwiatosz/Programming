program wielomiany;
type
        pwezel = ^wezel;
        wezel = record
                potega : integer;
                wspolcz : integer;
                next : pwezel
        end;

procedure roznica(var p, q, roznica : pwezel);
var
        s, t : pwezel;
begin
        roznica := nil;
        while (p <> nil) or (q <> nil) do
        begin
        	if roznica = nil then
        	begin
        		new(s);
        		roznica := s;
        	end
        	else
        	begin
        		new(s^.next);
        		s := s^.next;
        	end;
        	s^.next := nil;


                if (q=nil) or (p^.potega < q^.potega) then
                begin
                        s^.wspolcz := p^.wspolcz;
                        t := p^.next;
                        dispose(p);
                        p := t;
                end
                else
                        if (p=nil) or (p^.potega > q^.potega) then
                        begin
                                s^.wspolcz := q^.wspolcz;
                                t := q^.next;
                                dispose(q);
                                q := t;
                        end
                        else
                        begin
                                s^.wspolcz := p^.wspolcz + q^.wspolcz;
                                t := p^.next;
                                dispose(p);
                                p := t;
                                t := q^.next;
                                dispose(q);
                                q := t;
                        end;
        end;
end;

begin
end.
