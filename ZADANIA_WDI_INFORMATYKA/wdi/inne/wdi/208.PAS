program tablicerest2;
uses crt2;
const max=7;
type  bit=0..1;
      longint=array[0..max] of bit;
var licz:longint;
    i,li:integer;

procedure znak(var l:longint);
          var i,ost:integer;
          begin
          {zmiana znaku}
          for i:=0 to max do
              if l[i]=0 then l[i]:=1 else l[i]:=0;
          ost:=l[0];
          {dodanie jedynki}
          for i:=max downto 0 do
              if l[i]=0 then
                 begin
                 l[i]:=1;
                 break;
                 end
              else l[i]:=0;
          if (ost<>l[0]) and (l[0]=1) then write('pupa');
          end;



begin
clrscr;
for i:=max downto 0 do
    begin
    read(li);
    licz[i]:=li;
    end;
znak(licz);
for i:=0 to max do write(licz[i],' ');

repeat until keypressed;
end.