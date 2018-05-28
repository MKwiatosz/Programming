#include <iostream>


int main()
{
  int t[3] = {0,0,0};
  int number;
  
  for(int i=0; i<3; i++)
  {
    std::cin >> number;
    t[i]=number;
  }
      if(t[0]>t[1])
      {
        int temp = t[0];
        t[0]=t[1];
        t[1]=temp;
      }
      if(t[2]<t[1])
      {
        int temp = t[2];
        t[2]=t[1];
        t[1]=temp;
      }
      if(t[0]>t[1])
      {
        int temp = t[0];
        t[0]=t[1];
        t[1]=temp;
      }
  for(;;)
  {    
    std::cin >> number;
    if(number>t[2]) 
      std::cout << number << " ";
    else
    {
      int j;
      for(j=0; j<3 and t[j]<=number; j++);
      for(int i=1; i>=j ;i--)
        t[i+1]=t[i];
      t[j]=number;
    }       
  }

   
  return 0;
} 
