/******************************************************************************
* Sample solution for the Minimax Triangulation problem in NWERC'04
* Author: Andreas Björklund
* Solution: Dynamic programming, by enumerating subpolygons in order of
*           growing size.
******************************************************************************/
#include <stdio.h>

#define MAXN (50)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define sign(a) ((a)>=0?1:-1)

int x[MAXN],y[MAXN],dyn[MAXN][MAXN];

int triarea(int i,int j,int k)
{
  return ((x[j]-x[i])*(y[k]-y[i])-(y[j]-y[i])*(x[k]-x[i]));
}

int main(void)
{
  int t,i,j,k,n,sum;
  scanf("%d",&t);
  while (t--) {
      scanf("%d",&n);
      for (i=0;i<n;i++) {
        scanf("%d %d",&x[i],&y[i]);
        if (i>1) sum += triarea(0,i-1,i); else sum=0;
        dyn[i][(i+1) % n]=0;
      }  
      for (i=2;i<n;i++)
        for (j=0;j<n;j++) {
          dyn[j][(j+i) % n]=1<<30;  
          for (k=1;k<i;k++) {
            int cost=triarea(j,(j+k) % n,(j+i) % n); 
            if (sign(cost)==sign(sum))
              dyn[j][(j+i) % n]=min(dyn[j][(j+i) % n],max(max(abs(cost),dyn[(j+k) % n][(j+i) % n]),dyn[j][(j+k) % n]));
          }
        }
      printf("%1.1f\n",(double)dyn[1][0]/2);
    }
  return 0;
}
