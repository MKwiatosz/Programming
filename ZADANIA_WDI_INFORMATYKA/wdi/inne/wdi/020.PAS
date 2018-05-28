program zespdodwanie;
uses crt2;
const n=5;
type zesp=record
                re,im:real
                end;
     wiel=array[0..n] of zesp;
     wiel2=array[0..2*n] of zesp;

var wielomian:wiel;
    wielomian2:wiel;

procedure sumz(var za,zb,sum:zesp);
          begin
          sum.re:=za.re+zb.re;
          sum.im:=za.im+zb.im;
          end;

procedure suma(var za,zb,sum:wiel);
          var i:integer;
          begin
          for i:=0 to n do sumz(za[i],zb[i],sum[i]);
          end;

procedure mnoz(var z1,z2,iloczyn:zesp);
          begin
          iloczyn.re:=z1.re*z2.re-z1.im*z2.im;
          iloczyn.im:=z1.re*z2.im+z2.re*z1.im;
          end;

procedure ilocz(var w1,w2:wiel;w:wiel2);
          var i,j:integer;
              t:zesp;
          begin
          t.im:=0;
          t.re:=0;
          for i:=0 to 2*n do w[i]:=t;
          for i:=0 to 100 do
              for j:=0 to 100 do
                  begin
                  mnoz(w1[j],w2[i],t);
                  sumz(w[j+i],t,w[j+i]);
                  end;
          end;

procedure wczytaj(var w:wiel);
          var i:integer;
          begin
          for i:=0 to n do
          read(w[i].re,w[i].im);
          end;

procedure wypisz(var w:wiel);
          var i:integer;
          begin
          for i:=n downto 0 do begin
              write('(',w[i].re:2:0,'+i',w[i].im:2:0,')*');
              write('x^',i,' + ');
          end;
          end;

procedure wypisz2(var w:wiel2);
          var i:integer;
          begin
          for i:=2*n downto 0 do begin
              write(w[i].re,' i',w[i].im);
          end;
          end;

begin
clrscr;
wczytaj(wielomian);
wypisz(wielomian);
repeat until keypressed;
end.