{program, ktory  odwiedzi wszystkie pola tylko raz,
poruszajac sie ruchem konika szachowego}
program rozne_2_konik;
uses crt2;
const n=5;
      nsq=25;
type indeks=1..n;
var i,j:indeks;
    q:boolean;
    s:set of indeks;
    a,b:array[1..8] of integer;
    h:array[indeks,indeks] of integer;

    procedure proboj(i:integer; x,y:indeks;var q:boolean);
              var k,u,v:integer;
                  q1:boolean;
              begin
              k:=0;
              repeat
                    k:=k+1;
                    q1:=false;
                    u:=x+a[k];
                    v:=y+b[k];
                    if (u in s) and (v in s) then
                       if h[u,v]=0 then
                          begin
                          h[u,v]:=i;
                          if i<nsq then
                             begin
                             proboj(i+1,u,v,q1);
                             if not q1 then h[u,v]:=0;
                             end
                          else q1:=true
                       end;
              until q1 or (k=8);
              q:=q1;
              end;

begin
clrscr;
s:=[1,2,3,4,5];
a[1]:=1; b[1]:=2;
a[2]:=2; b[2]:=1;
a[3]:=-1;b[3]:=2;
a[4]:=-2;b[4]:=1;
a[5]:=-2;b[5]:=-1;
a[6]:=-1;b[6]:=-2;
a[7]:=1 ;b[7]:=-2;
a[8]:=2; b[8]:=-1;

for i:=1 to n do
    for j:=1 to n do h[i,j]:=0;
h[3,3]:=1;
proboj(2,3,3,q);
if q then
   for i:=1 to n do
       begin
       for j:=1 to n do write(h[i,j]:3);
       writeln;
       writeln;
       end
else writeln('ni ma');
repeat until keypressed;
end.