program tablicecz1;
uses crt2;
const
     max1=7;
     max2=5;     {il wier     wiersz}
type table=array[1..max1] of array[1..max2] of integer;
  {   tablica=array[1..max1,1..max2] of integer; }
      wiersz=array[1..max1] of integer;
      tablica=array[1..max2] of wiersz;

var t:tablica;
    x,y:integer;


function najmniejszy(var t:table):integer;
         var b,gdzie,min:integer;
         function max(i:integer):integer;
                  var a,naj:integer;
                  begin
                  naj:=t[i][1];
                  for a:=2 to max2 do
                      begin
                      if t[i][a]>naj then naj:=t[i][a];
                      end;
                  max:=naj;
                  end;

         begin
         min:=max(1);
         gdzie:=1;
         for b:=2 to max1 do
             if max(b)<min then
                begin
                min:=max(b);
                gdzie:=b;
                end;



         najmniejszy:=gdzie;
         end;

procedure iloraz(var t:tablica);   { t[i,j]  i-ta max1 koluma j-ty wiersz}
          var i,j,ii,jj,li,licznik,mianownik:integer;
          begin
          {suma w kolumnie}      {zrobic metoda czolgowa bo to nie obejmuej ujemnych}
          li:=0;
          for jj:=1 to max1 do li:=li+t[1,jj];
          licznik:=li;
          i:=1;
          for ii:=2 to max1 do
              begin
              li:=0;
              for jj:=1 to max2 do li:=li+t[ii,jj];
              if licznik<li then
                 begin
                 licznik:=li;
                 i:=ii;
                 end;
              end;
          {suma w wierszu najm}
          li:=0;
          for ii:=1 to max2 do li:=li+t[ii,1];
          mianownik:=li;
          j:=1;
          for jj:=2 to max2 do
              begin
              li:=0;
              for ii:=1 to max1 do li:=li+t[ii,jj];
              if (mianownik>li) and (li<>0) then
                 begin
                 mianownik:=li;
                 j:=jj;
                 end;

              end;

          if mianownik=0 then write('pupa') else write(i,' ',j);
          end;

function podciag(var t:tablica):integer;
         var i,wiersz,max:integer;

         function ciag(wier:integer):integer;
                  var a,najdl,pom,li:integer;
                  begin
                  ciag:=1;
                  najdl:=1;
                  pom:=1;
                  li:=t[wier][1];
                  for a:=2 to max1 do
                      begin
                      if li=t[wier][a] then pom:=pom+1
                      else
                          begin
                          li:=t[wier][a];

                          if pom>najdl then najdl:=pom;
                          pom:=1;
                          end;
                      end;
                  if pom>najdl then najdl:=pom;
                  ciag:=najdl;
                  end;

         begin
         max:=ciag(1);
         wiersz:=1;
         for i:=2 to max1 do

             begin
             if ciag(i)>max then
                begin
                max:=ciag(i);
                wiersz:=i;
                end;
             end;

         podciag:=wiersz;
         end;

begin
clrscr;
for x:=1 to max2 do
    begin
    for y:=1 to max1 do
        begin
        randomize;
        t[x][y]:=random(3);
        write(t[x][y]:3);
        delay(257);
        end;
    writeln;
    end;
{write(najmniejszy(t));}
{iloraz(t);}
write(podciag(t));
repeat until keypressed;
end.