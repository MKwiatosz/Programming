#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    float a1, a2, b1, b2, c1, c2, W, Wx, Wy, x, y;
    
    cout << "Podaj wspolczynnik przy niewiadomej X i Y oraz wyraz wolny pierwszego rownania: ";
    cin >> a1 >> b1 >> c1;
    cout << endl << "Podaj wspolczynnik przy niewiadomej X i Y oraz wyraz wolny pierwszego drugiego rownania: ";
    cin >> a2 >> b2 >> c2;
    cout << endl;
    
    W=a1*b2-a2*b1;
    Wx=c1*b2-c2*b1;
    Wy=a1*c2-a2*c1;
    
    if(W==0 and Wx==0 and Wy==0) cout << "Uklad nieoznaczony.";
    if(W==0 and (Wx!=0 or Wy!=0)) cout << "Uklad sprzeczny.";
    if(W!=0)
    {
      x=Wx/W;
      y=Wy/W;
      cout << "Uklad oznaczony.\tX = " << x << "\tY = " << y;
    }
    
cin.ignore();
getchar();
}  
