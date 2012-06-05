#include <cstdio>
int main()
{
     int r[49] = {1, 1};
     int a, b, n, i, k;
     while(scanf("%d%d%d", &a, &b, &n) == 3 && a|b|n)
     {
           for (i = 2; i < 49; i++)
           {
                 r[i] = (a * r[i-1] + b * r[i-2]) % 7;
                 if (r[i] == 1 && r[i-1] == 1)
                       break;
           }
           printf("%d\n", r[(n-1)%k]);
     }
     return 0;
} 
