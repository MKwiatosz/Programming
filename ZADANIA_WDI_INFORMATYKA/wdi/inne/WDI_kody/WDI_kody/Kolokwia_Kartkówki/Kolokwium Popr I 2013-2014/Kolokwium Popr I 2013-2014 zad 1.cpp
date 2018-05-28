#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
using namespace std;
const int N=10;

/* Tablica t[n][n] jest wype³niona liczbami naturalnymi. W dok³adnie jednym wierszu istnieje dok³adnie jeden fragment ci¹gu 
Fibonacciego o d³ugoœci wiêkszej ni¿ 2 mniejszej ni¿ N. Napisz funkcjê która znajdzie ten fragment i zwróci nr wiersza,
w którym siê znaduje. */

int isFib(int k)   // METODA#1  zwraca nastêpn¹ liczbê Fib po k lub -1 (gdy nie jest)
{
     if(k==0) return 1;
     int a=0;
     int b=1;
     while(b<=k)
     {
     if(b==k) return b+a;
     
     int t=b;
     b=a+b;
     a=t;
     }
     return -1;
}


int isFib2(int k)  // METODA#2   zwraca numer liczby Fib lub -1 (gdy nie jest)
{
     if(k==0) return 0;
     int a=0;
     int b=1;
     int i=1;
     while(b<=k)
     {
         if(b==k) return i ;
         i++;
         int t=b;
         b=a+b;
         a=t;
     }
     return -1;
}

bool hasFibSubseq(int s[N])  // METODA #1
{
     for(int i=0; i<N; i++) 
     
          if(isFib2(s[i]) != -1)  // s[i] jest liczb¹ Fib
                if(isFib2(s[i+1])!=-1 and isFib2(s[i+1])-1 == isFib2(s[i]) )  // s[i+1] jest liczb¹ Fib
                             if(isFib2(s[i+2]) !=-1 and isFib2(s[i+2])-1 == isFib2(s[i+1]) ) 
                             return true; 
     return false;                
}     




bool hasFibSubseq2(int s[N])  // METODA #2 ---
{
     for(int i=0; i<N; i++) 
     {
          if(isFib2(s[i]) != -1)  // s[i] jest liczb¹ Fib
          {      
                int j=i;
                while (isFib2(s[j])!=-1 and j+1<N and isFib2(s[j+1])-1 == isFib2(s[j])) // dopóki s[j+1] jest kolejn¹ liczb¹ fib
                      j++;
                if(j-i>=3 and j-i<N) return true; 
          }
     }     
     return false;   
}   


bool hasFibSubseq3(int s[N])   // METODA #3
{
     for(int i=0; i<N; i++) 
     {
          int t=isFib(s[i]);
          int j=i;
          while (t != -1 and j+1<N and s[j+1] == t )
          {
                t=t+s[j];
                j++;
          }
     if(j-i+1>=3 and j-i+1<N) return true;   // d³ugoœæ podci¹gu jest >=3
     }
     return false;   
}  


int main()
{ 
int t[N][N];
bool end=true;

srand(time( NULL ));
for (int i=0; i<N; i++)
{
    for(int j=0; j<N; j++)
    {        
             t[i][j]=(rand()% 11);
             cout << t[i][j] << "\t";
             if(j==N-1) cout << endl;
    }         
}


for(int i=0; i<N and end==true; i++)
{
        if(hasFibSubseq3(t[i])) 
        {
                 cout << endl << "wiersz = " << i;
                 end=false;
        }        
}
if (end==true) cout << endl << "Brak szukanego ciagu.";


cin.ignore();
getchar();


}
           
