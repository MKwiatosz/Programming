{ Dane są deklaracje opisujące listę jednokierunkową: }

type 
	pwezel = ^wezel;
	wezel = record
		val: integer;
		next: pwezel
	end;

{ Proszę napisać procedurę, która w liście wskazywanej przez zmienna typu pwezel usuwa powtarzające się elementy. Można założyć, że lista jest niepusta. }

{ poniższe rozwiązanie pozostawia po jednej kopii każdego elementu, czyli jeżeli jest np. 10 dwójek, to usuwa 9 z nich }

procedure UsunPowtarzajace(first: pwezel);

  procedure UsunEl(first: pwezel; v: Integer);
  var
    p: pwezel;
  begin
    while first^.next<>nil do
      if first^.next^.val = v then begin
        p := first^.next;
        first^.next := first^.next^.next;
        dispose(p);
      end else
        first := first^.next;
  end;
  
begin
  while first<>nil do begin
    UsunEl(first,first^.val);
    first := first^.next;
  end;
end;

{ modyfikacja powyższego algorytmu, tak, żeby usuwał np. wszystkie 10 dwójek ;) }

procedure UsunPowtarzajace2(var first: pwezel);
var
  p,q: pwezel;
  i: integer;

  function UsunEl(first: pwezel; v: Integer): Integer;
  var
    p: pwezel;
    ile: Integer;
  begin
    ile := 0;
    while first^.next<>nil do
      if first^.next^.val = v then begin
        p := first^.next;
        first^.next := first^.next^.next;
        dispose(p);
        inc(ile);
      end else
        first := first^.next;
    UsunEl := ile;
  end;
  
begin
  p := first;
  while p<>nil do begin
    i := UsunEl(p,p^.val);
    if i>0 then begin
      if p=first then begin
        first := first^.next;
        dispose(p);
        p := first;
      end else begin
        q^.next := p^.next;
        dispose(p);
        p := q^.next;
      end;
    end else begin
      q := p;
      p := p^.next;
    end;
  end;
end;
