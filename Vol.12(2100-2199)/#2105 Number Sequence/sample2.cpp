#include<iostream>
using namespace std;
int main()
{ 
       int a,i,b,n;
    int fn[1000];    
       int previous, current;
    fn[0] = 1;    
       fn[1] = 1;    
       while(cin>>a>>b>>n&&a!=0)   
       {        
              previous=(a+b)%7;        
              fn[2]=previous;       
              i=2;        
              while(i++&&i<1000)      
              {           
                     current=(a*fn[i-1]+b*fn[i-2])%7;    
                     if (previous==1&&current==1)         
                            break;           
                  fn[i] = current;           
                     previous = current;        
              }        
              cout <<fn[(n-1)%(i-1)]<<endl; 
       }    
       return 0;
}
