
/* Dany jest nastêpuj¹cy typ tab = array [1..MAXX,1..MAXY] of integer
Proszê napisaæ procedurê bila, która symuluje ruch bili zaczynaj¹cej siê
poruszaæ z punktu o wspó³rzêdnych (x,y) w kierunku rosn¹cych indeksów z
prêdkoœci¹ dx=1 i dy=1. Bila powinna „odbijaæ siê” od brzegów tablicy.
Ka¿dy element tablicy powinien po wykonaniu procedury zawieraæ liczbê
okreœlaj¹c¹, ile razy bila znajdowa³a siê w punkcie o tych wspó³rzêdnych w
czasie jej ruchu do momentu powrotu do punktu wyjœcia. [czy to siê
skoñczy?] */


int const X=100;
int const Y=200;

struct Move
{
 int x;
 int y;
 int dx;
 int dy;
};

Move NewMove(Move m)
{
  if(m.x==0 or m.x==X-1) m.dx=-m.dx;
  if(m.y==0 or m.y==Y-1) m.dy=-m.dy;
  m.x+=m.dx;
  m.y+=m.dy;
}

void HowMany(int &T[X][Y], int x, int y)
{
  Move m;
  m.x=x;
  m.y=y;
  m.dx=1;
  m.dy=1;
  
  do
  {
    T[m.x][m.y]++;
    m=NewMove(m);
  }
  while(m.x!=x or m.y!=y);
}
