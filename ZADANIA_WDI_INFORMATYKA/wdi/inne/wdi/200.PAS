program zeszyt1;
uses crt2;
const n=40;
var licz:integer;

    procedure najzwielu;
              var min,max:integer;
              begin
              if not eof then
                 begin
                 read(max);
                 while not eof do
                       begin
                       read(min);
                       if min>max then max:=min;
                       end;
                 write(max)
                 end
              end;

    procedure dwanajw;
              var max1,max2,l:integer;
              begin
              if not eof then
                 begin
                 read(max1);
                 max2:=max1;
                 while not eof do
                       begin
                       read(l);
                       if l>max1 then
                          begin
                          max2:=max1;
                          max1:=l;

                          end
                       else if (l>max2) and (l<>max1) then max2:=l;
                       end;
                 end;
              if max1<>max2 then write(max1,' ',max2) else write(max1);
              end;

    procedure podzielniki;
              var l,i:integer;
              begin
              if not eof then read(l);
              for i:=1 to trunc(sqrt(l)) do if (l mod i=0) then

                  if i<>(l div i) then writeln(i,' ',l div i)
                  else writeln(i);

              end;


    procedure nwd;
              var a,b:integer;
              begin
              if not eof then read(a,b);
              while a<>b do if a>b then a:=a-b else b:=b-a;
              write(a);
              end;


    procedure czynnikipierw;
              var i,l:integer;
              begin
              if not eof then
              begin
              read(l);
              i:=2;
              if l<2 then write(l) else
              while i<=l do
                    begin
                    if (l mod i)=0 then
                       begin
                       write(i,' ');
                       l:=l div i;

                       end
                    else i:=i+1;
                    end;
              end;
              end;


    procedure pierwsze;
              var i,j:integer;
                  pierw:array[1..n] of boolean;
              begin
              for i:=1 to n do pierw[i]:=true;
              i:=2;
              while i<sqrt(n) do
                    begin
                    j:=i*i;
                    while j<=n do
                          begin
                          pierw[j]:=false;
                          j:=j+i;
                          end;
                    i:=i+1;
                    end;
              for i:=1 to n do if pierw[i] then writeln(i);
              end;

    procedure kroliki;
              var i,p,f0,f1,f2:integer;
              begin
              read(p);
              f0:=0;
              f1:=1;
              if p=0 then write(f0)
              else if p=1 then write(f1)
                else
                  begin
                  for i:=2 to p do
                      begin
                      f2:=f1+f0;
                      f0:=f1;
                      f1:=f2;
                      end;
                  write(f1);
                  end;
              end;

    procedure pierwcalk;
              var l,w,i:integer;
              begin
              if not eof then
                 begin
                 read(l);
                 w:=0;
                 i:=1;
                 while w<l do
                       begin
                       w:=w+2*i+1;
                       i:=i+1;
                       end;
                 write(i-1);
                 end;
              end;

    procedure sitoer;
              var sito,pierwsze:set of 2..n;
                  i,next:integer;
              begin
              sito:=[2..n];
              pierwsze:=[ ];
              next:=2;
              repeat
                    while not (next in sito) do next:=succ(next);
                    pierwsze:=pierwsze+[next];
                    i:=next;
                    while i<=n do
                          begin
                          sito:=sito-[i];
                          i:=i+next;
                          end;
              until sito=[ ];
              for i:=2 to n do if i in pierwsze then write(i,' ');
              end;


    procedure kolopodziel;
              var lpom,l,i,podz,najw:integer;

              begin
              najw:=1;
              lpom:=1;
              while l<>0 do
                    begin
                    read(l);
                    if i>0 then
                       begin
                       podz:=0;
                       for i:=1 to (l div 2) do if (l mod i)=0 then
                           podz:=podz+1;
                       if podz>lpom then
                          begin
                          lpom:=podz;
                          najw:=l;
                          end;
                       if podz=lpom then if najw<l then najw:=l;
                       end;
                    end;
                    write(najw);


              end;

    procedure piernew(a,d:real);
              var x,y:real;
              begin
              if (a>0) and (d>0) then
              begin
              y:=a/2;
              repeat
                    x:=y;
                    y:=0.5*(x+a/x);

              until abs(x-y)<=d;
              write(y:5:10);
              end;
              end;


    procedure xsystem(l,sys:integer);
              var dzies,wyn:integer;
              begin
              dzies:=1;
              wyn:=0;
              while l>=1 do
                    begin
                    wyn:=wyn+(l mod sys)*dzies;
                    l:=l div sys;
                    dzies:=dzies*10;
                    end;
              write(wyn);
              end;


begin
clrscr;

{xsystem(13,2);
piernew(2,0.00000000001);
kolopodziel;
sitoer;
pierwcalk;
najzwielu;
dwanajw;
podzielniki;
nwd;
czynnikipierw;
pierwsze;
kroliki;}
repeat until keypressed;
end.