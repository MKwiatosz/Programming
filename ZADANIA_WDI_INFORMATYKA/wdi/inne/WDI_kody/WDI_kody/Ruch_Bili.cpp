
/* Dany jest nast�puj�cy typ tab = array [1..MAXX,1..MAXY] of integer
Prosz� napisa� procedur� bila, kt�ra symuluje ruch bili zaczynaj�cej si�
porusza� z punktu o wsp�rz�dnych (x,y) w kierunku rosn�cych indeks�w z
pr�dko�ci� dx=1 i dy=1. Bila powinna �odbija� si� od brzeg�w tablicy.
Ka�dy element tablicy powinien po wykonaniu procedury zawiera� liczb�
okre�laj�c�, ile razy bila znajdowa�a si� w punkcie o tych wsp�rz�dnych w
czasie jej ruchu do momentu powrotu do punktu wyj�cia. [czy to si�
sko�czy?] */


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
