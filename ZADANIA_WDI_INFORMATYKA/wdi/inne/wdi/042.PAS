{procedura, ktora w liscie wskazywanej przez zmienna typu pwezel usuwa
powtarzajace sie elementy, mozna zalozyc, ze lista jest niepusta}
program wskazniki_1_usun_powtorki;
uses crt2;
const n=5;
type
    pwezel=^wezel;
    wezel=record
                nr:integer;
                next:pwezel;
    end;
var p,first:pwezel;
    pom:integer;

    procedure lista(var l,f:pwezel);
              var licz,i:integer;
                  firs:pwezel;
              begin
              firs:=nil;
              for i:=1 to n do
                  begin
                  read(licz);
                  new(l);
                  l^.next:=firs;
                  l^.nr:=licz;
                  firs:=l;
                  end;
                  f:=firs;
              end;

    procedure wypisz(var l,f:pwezel);
              begin
              while l<>nil do
                    begin
                    write(l^.nr,' ');
                    l:=l^.next;
                    end;
                    l:=f;
              end;
    {procedura usuwajaca z listy element nastepny za wskazanym(f?)}
    {jezeli chcemu usunac pierwszy to wsazujacemu przypisujemy zawartosc nil}
    procedure usun(var l,f:pwezel);
              var r:pwezel;

              begin
              if f=nil then halt; {lista jest pusta}
              if l=nil then      {wskazywany jest pusty wiec usuwamy pierwszy}
                 begin
                 r:=f;
                 f:=f^.next;
                 dispose(r);
                 end
              else
                  begin
                  r:=l^.next;
                  if r=nil then halt;  {nie ma nic po l, wiec haltujemy}
                  l^.next:=r^.next;
                  dispose(r);
                  end;
              end;

    procedure usunidentyczne(var l,f:pwezel);
              var licz:integer;
                  wsk,popwsk,pop:pwezel;
                  pom:boolean;
              begin
              pop:=nil;
              while (l<>nil) and (l^.next<>nil) do
                    begin
                    wsk:=l^.next;
                    popwsk:=l;
                    pom:=false;
                    while wsk<>nil do
                          begin
                          if l^.nr=wsk^.nr then
                             begin
                             wsk:=wsk^.next;
                             usun(popwsk,f);
                             pom:=true;
                             end
                          else
                              begin
                              popwsk:=wsk;
                              wsk:=wsk^.next;
                              end;
                          end;

                    if pom then
                       begin
                       l:=l^.next;
                       usun(pop,f);
                       end
                    else
                        begin
                        pop:=l;
                        l:=l^.next;
                        end;
                    end;

              l:=f;
              end;

begin
clrscr;
lista(p,first);
writeln('przed');
wypisz(p,first);
usunidentyczne(p,first);
writeln;
writeln('po');
wypisz(p,first);
writeln;
writeln('fin');
repeat until keypressed;
end.