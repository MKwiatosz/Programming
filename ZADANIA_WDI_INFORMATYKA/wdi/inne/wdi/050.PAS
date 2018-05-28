{lista reprezentuje wielomian o wspolczynnikach calkowitych. elementy
w liscie ulozone sa wedlug rosnacych poteg. prosze napisac procedure
obliczajaca roznice dwoch dowolnych wielomianow. wielomiany reprezentowane
sa przez wyzej opisane listy. listy wejsciowe powinny zostac niezmienione}
program wskazniki_10_roznica_wielomianow;
uses crt2;
type
    pwezel=^wezel;
    wezel=record
                potega:integer;
                wspolcz:integer;
                next:pwezel;
                end;

var w1,w2,w:pwezel;

    procedure tworz(var wie:pwezel);
              var p:pwezel;
                  i,licz,wsp,pot,max:integer;
              begin
              write('ilosc');
              read(max);
              wie:=nil;
              for i:=1 to max do
                  begin
                  write('wsp');
                  read(wsp);
                  write('pot');
                  read(pot);
                  new(p);
                  p^.next:=wie;
                  p^.wspolcz:=wsp;
                  p^.potega:=pot;
                  wie:=p;
                  end;
              end;

    procedure wypisz(wie:pwezel);
              begin
              while wie<>nil do
                    begin
                    write(' ',wie^.wspolcz,'x^',wie^.potega);
                    wie:=wie^.next;
                    end;
              end;

    procedure roznica(w1,w2:pwezel;var w:pwezel);    {w1 minus w2}
              var p:pwezel;

              begin
              w:=nil;
              while (w1<>nil) or (w2<>nil) do
                    begin
                    if (w1=nil) or (w2=nil) then
                       begin
                       if w1=nil then
                          while w2<>nil do
                                begin
                                new(p);
                                p^.next:=w;
                                p^.potega:=w2^.potega;
                                p^.wspolcz:=-w2^.wspolcz;
                                w:=p;
                                w2:=w2^.next;
                                end
                       else
                           while w1<>nil do
                                 begin
                                 new(p);
                                 p^.next:=w;
                                 p^.wspolcz:=w1^.wspolcz;
                                 p^.potega:=w1^.potega;
                                 w:=p;
                                 w1:=w1^.next;
                                 end
                       end

                    else
                        begin
                        if w2^.potega=w1^.potega then
                           begin
                           if w1^.wspolcz-w2^.wspolcz<>0 then
                              begin
                              new(p);
                              p^.next:=w;
                              p^.potega:=w1^.potega;
                              p^.wspolcz:=w1^.wspolcz-w2^.wspolcz;
                              w:=p;
                              end;
                           w1:=w1^.next;
                           w2:=w2^.next;
                           end
                        else
                            if w2^.potega<w1^.potega then
                               begin
                               new(p);
                               p^.next:=w;
                               p^.potega:=-w2^.potega;
                               p^.wspolcz:=w2^.wspolcz;
                               w:=p;
                               w2:=w2^.next;
                               end
                            else
                               begin
                               new(p);
                               p^.next:=w;
                               p^.potega:=w1^.potega;
                               p^.wspolcz:=w1^.wspolcz;
                               w:=p;
                               w1:=w1^.next;
                               end
                        end;
              end;
       end;

begin
clrscr;
tworz(w1);
tworz(w2);
wypisz(w1);
writeln;
wypisz(w2);
writeln;
roznica(w1,w2,w);
wypisz(w);
repeat until keypressed;
end.
