program zesolone;
uses crt2;
const n=5;
type zesp=record
     re,im:integer;
     end;
type wiel=array[0..n] of zesp;
     wiel2=array[0..2*n] of zesp;

procedure sumz(var a,b,s:zesp);
          begin
          s.re:=a.re+b.re;
          s.im:=b.im+a.im;
          end;

procedure suma(var w1,w2,ws:wiel);
          var i:integer;
          begin
          for i:=0 to n do sumz(w1[i],w2[i],ws[i]);
          end;

procedure mnoz(var a,b,s:zesp);
          begin
          s.re:=a.re*b.re-a.im*b.im;
          s.im:=a.re*b.im+a.im*b.re;
          end;

procedure ilocz(var w1,w2:wiel;ws:wiel2);
          var i,j:integer;
              m:zesp;
          begin
          for i:=0 to 2*n do
              begin
              ws[i].re:=0;
              ws[i].im:=0;
              end;

          for i:=0 to n do
              for j:=0 to n do
                  begin
                  mnoz(w1[i],w2[j],m);
                  sumz(m,ws[j+i],ws[j+i]);
                  end;
          end;







begin
clrscr;

repeat until keypressed;
end.