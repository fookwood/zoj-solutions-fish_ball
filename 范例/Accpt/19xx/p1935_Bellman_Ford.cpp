#include <stdio.h>
#define  MAXN     100

int      N , Cost [MAXN] , Edge [MAXN] [MAXN] , Len [MAXN] , M , Min [MAXN] , MinL;

bool     init ()
{
         scanf ( "%d" , &N );
         MinL = 0;
         if ( N == -1 ) return false;
         for ( int i = 0; i < N; i ++ ) Len [i] = 0;
         for ( int i = 0; i < N; i ++ ) {
             scanf ( "%d" , &Cost [i] );
             if ( Cost [i] < 0 ) MinL += Cost [i];
             Cost [i] = -Cost [i];
             scanf ( "%d" , &Len [i] );
             for ( int j = 0; j < Len [i]; j ++ )
                 scanf ( "%d" , &Edge [i] [j] ) , Edge [i] [j] --;
         }
         return true;         
}

int      Bellman_Ford ()
{
         for ( int i = 0; i < N; i ++ ) Min [i] = 0x0fffffff; Min [0] = -100;
         bool  Change;
        while ( true ) {
             Change = false;
             for ( int j = 0; j < N; j ++ )
                 for ( int k = 0; k < Len [j]; k ++ ) {
                     if ( Min [j] < MinL && Cost [Edge [j] [k]] < 0 ) continue;
                     if ( Min [j] < 0 && Min [j] + Cost [Edge [j] [k]] < Min [Edge [j] [k]] )
                        Min [Edge [j] [k]] = Min [j] + Cost [Edge [j] [k]] , Change = true;
                 }
             if ( !Change ) break;
         }
         return Min [N - 1];
}

main ()
{
     while ( init () ) {
           if ( Bellman_Ford () < 0 ) printf ( "winnable\n" );
              else printf ( "hopeless\n" );
     }
}
