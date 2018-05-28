{pojedyncza lista zawiera niepowtarzajace sie liczby naturalne posortowane
rosnaco. prosze napisac procedure(funkc), ktora dwie niepuste listy wejsciowe
przeksztalca na jedna liste wynikowa tak, ze elementy listy wynikowej
stanowia sume mnogosciowa list wejsciowych. listy wejsciowe sa usuwane
z pamieci. Do funkcji nalezy przekazac, wskazniki na poczatki list
wejsciowych, funkcja powinna zwrocic wskaznik do listy wynikowej.}
program wskazniki_6_7_9_suma_dwoch_ciagow;
uses crt2;
type
    pwezel=^wezel;
    wezel=record
                nr:integer;
                next:pwezel;
                end;
var p1,p2,p:pwezel;

procedure tworz(var f:pwezel;n:integer);
          var p:pwezel;
              i,licz:integer;
          begin
          f:=nil;
          for i:=1 to n do
              begin
              read(licz);
              new(p);
              p^.next:=f;
              p^.nr:=licz;
              f:=p;
              end;
          end;

procedure wypisz(f:pwezel);
          begin
          while f<>nil do
                begin
                write(f^.nr,' ');
                f:=f^.next;
                end;
          end;

procedure nel(var p:pwezel;var w:integer);
          var niu:pwezel;
          begin
          new(niu);
          niu^.next:=p;
          niu^.nr:=w;
          p:=niu;
          end;

procedure usun(var p:pwezel);
          var r,f:pwezel;
          begin
          f:=p;
             while (p<>nil) and (p^.next<>nil) do
                begin
                r:=p^.next;
                p:=r^.next;
                dispose(r);
                end;
             if p^.next=nil then
                begin
                r:=f;
                f:=nil;
                dispose(r);
                end;
          p:=f;
          end;

function sumuj(var l1,l2:pwezel):pwezel;

         var       wart:integer;
                   l,f,l11,l22:pwezel;
         begin
         wart:=0;
         f:=nil;
         l11:=l1;
         l22:=l2;
         while (l1<>nil) or (l2<>nil) do
              begin
               if (l1=nil) or (l2=nil) then
               begin
               if l1=nil then
                  while l2<>nil do
                        begin
                        nel(f,l2^.nr);
                        l2:=l2^.next;
                        end
               else
                   while l1<>nil do
                         begin
                         nel(f,l1^.nr);
                         l1:=l1^.next;
                         end
               end
               else

               if (l1^.nr=l2^.nr) then
                  begin
                  if l1^.nr>wart then
                     begin
                     wart:=l1^.nr;
                     nel(f,wart);
                     l1:=l1^.next;
                     l2:=l2^.next;
                     end
                  end
               else
                   if (l1^.nr>l2^.nr) then
                      begin
                      if l2^.nr>wart then
                         begin
                         wart:=l2^.nr;
                         nel(f,wart);
                         l2:=l2^.next;
                         end
                      else
                         begin
                         wart:=l1^.nr;
                         nel(f,wart);
                         l1:=l1^.next;
                         l2:=l2^.next;
                         end
                      end
                   else
                       begin
                       if l1^.nr>wart then
                          begin
                          wart:=l1^.nr;
                          nel(f,wart);
                          l1:=l1^.next;
                          end
                       else
                           begin
                           wart:=l2^.nr;
                           nel(f,wart);
                           l1:=l1^.next;
                           l2:=l2^.next;
                           end
                       end


         end;
         l1:=l11;
         l2:=l22;
         usun(l1);
         usun(l2);
         sumuj:=f;
         end;



begin
clrscr;
tworz(p1,5);
writeln('kolejny:');
tworz(p2,4);
wypisz(p1);
writeln;
wypisz(p2);
writeln;
wypisz(sumuj(p1,p2));
writeln;
wypisz(p1);
repeat until keypressed;
end.
