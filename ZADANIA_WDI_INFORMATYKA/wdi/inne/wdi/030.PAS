program tab2;                  {zly bo tylko dla liczb dodatnich}
uses crt2;
const max1=5;
      max2=4;    {t[i,j]}
type  tablica=array[1..max1,1..max2] of integer;
var   t:tablica;
      i,j:integer;



procedure nilo(var tab:tablica; var x,y:integer);
          var sumx,sumy,maxi,minj,a,b:integer;
          begin
          sumx:=0;
          sumy:=0;
          for a:=1 to max2 do sumx:=sumx+tab[1,a];
          for a:=1 to max1 do sumy:=sumy+tab[a,1];
          maxi:=sumx;x:=1;
          minj:=sumy;y:=1;
          for b:=2 to max1 do
              begin
              for a:=1 to max2 do sumx:=sumx+tab[b,a];
              if sumx>maxi then begin
                           x:=b;
                           maxi:=sumx;
                           end;
              end;
          for b:=2 to max2 do
              begin
              for a:=1 to max1 do sumy:=sumy+tab[a,b];
              if sumy<minj then
                           begin
                           minj:=sumy;
                           y:=b;
              end;
              end;
          if minj=0 then x:=-1;


end;


begin
clrscr;




repeat until keypressed;
end.