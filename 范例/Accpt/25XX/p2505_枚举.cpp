#include <stdio.h>
#include <algorithm>
#define N 4096
using namespace std;

int  M;
bool State [N];

void solve ();

main ()
{
     int total;
     for ( scanf ( "%d" , &total ); total; total -- ) {
         solve ();
     }
}

void solve ()
{
     int   Ans = 0;
     scanf ( "%d" , &M );
     memset ( State , 1 , sizeof ( State ));
     for ( int i = 0; i < M; i ++ ) {
         int   Last , t;
         scanf ( "%d" , &t ) , t --;
         State [t] = !State [t];
         if ( State [t] ) continue;
         Last = 1;
         for ( int j = t - 1; j >= 0 && !State [j]; j -- ) Last ++;
         for ( int j = t + 1; j < N && !State [j]; j ++ ) Last ++;
         if ( Last > Ans ) Ans = Last;
     }
     printf ( "%d\n" , Ans );
}
