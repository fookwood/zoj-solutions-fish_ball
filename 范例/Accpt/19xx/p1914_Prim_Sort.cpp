#include <stdio.h>
#include <math.h>
#include <algorithm>

using    namespace std;

int      S , P;
double   dis [500] [500] , x [500] , y [500];

void     init ()
{
         scanf ( "%d%d" , &S , &P );
         for ( int i = 0; i < P; i ++ ) scanf ( "%lf%lf" , &x [i] , &y [i] );
         for ( int i = 0; i < P; i ++ )
             for ( int j = i + 1; j < P; j ++ )
                 dis [i] [j] = dis [j] [i] = sqrt ( ( x [i] - x [j] ) * ( x [i] - x [j] ) + ( y [i] - y [j] ) * ( y [i] - y [j] ));
}

double   Prim ()
{
         bool mk [500];
         double Min [500];
         
         memset ( mk , 0 , P );
         int    i , j , k;
         for ( i = 0; i < P; i ++ ) Min [i] = 1e20; Min [0] = 0;
         
         for ( i = 0; i < P; i ++ ) {
             for ( k = -1 , j = 0; j < P; j ++ ) if ( !mk [j] )
                 if ( k == -1 || Min [j] < Min [k] ) k = j;
             mk [k] = true;
             for ( j = 0; j < P; j ++ ) if ( !mk [j] && dis [k] [j] < Min [j] )
                 Min [j] = dis [k] [j];
         }
         sort ( Min , Min + P );
         return     Min [P - S];
}

main ()
{
     int part;
     for ( scanf ( "%d" , &part ); part; part -- ) {
           init ();
           printf ( "%.2lf\n" , Prim () );
     }
}
