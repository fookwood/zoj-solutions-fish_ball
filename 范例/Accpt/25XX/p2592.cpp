#include <stdio.h>

#define MAX 200000

int     N , Sum;
int     Num [MAX] , RightMin [MAX] , LeftMax;

int     Answer ()
{
        int     i;
        int     ret;
        
        scanf ( "%d" , &N );
        Sum = 0;
        for ( i = 0; i < N; i ++ ) {
                scanf ( "%d" , &Num [i] );
                Sum += Num [i];
        }

        RightMin [N - 1] = Num [N - 1];
        for ( i = N - 2; i >= 0; i -- ) {
                if ( RightMin [i + 1] >= 0 ) RightMin [i] = 0; else RightMin [i] = RightMin [i + 1];
                RightMin [i] += Num [i];
        }

        LeftMax = Num [0];
        if ( RightMin [0] > 0 ) ret = 1; else ret = 0;

        for ( i = 1; i < N; i ++ ) {
                if ( Sum > LeftMax && RightMin [i] > 0 ) ret ++;
                if ( LeftMax < 0 ) LeftMax = 0;
                LeftMax += Num [i];
        }
        return ret;
}

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );
        
        int     total;
        for ( scanf ( "%d" , &total ); total; total -- )
                printf ( "%d\n" , Answer () );
}
