#include <stdio.h>
#include <string.h>

int     A , B , M , L , K;
int     Dis [100] [100] , OneStep [100] [100];
int     Opt [11] [100];
bool    Mark [100];

void    init ()
{
        int     i , a , b;
        scanf( "%d%d%d%d%d" , &A , &B , &M , &L , &K );
        memset ( Opt , 0xff , sizeof ( Opt ));
        memset ( Dis , 0xff , sizeof ( Dis ));
        memset ( OneStep , 0xff , sizeof ( OneStep ));
        for ( i = 0; i < M; i ++ ) {
                scanf ( "%d%d" , &a , &b );
                a --; b --;
                scanf ( "%d" , &Dis [a] [b] );
                Dis [b] [a] = Dis [a] [b];
        }
}

void    WorkForVillage ()
{
        int     i , j , k , t;
        memcpy ( OneStep , Dis , sizeof ( Dis ));

        for ( k = 0; k < A; k ++ )
                for ( i = 0; i < A + B; i ++ ) if ( i != k && OneStep [i] [k] != -1 )
                        for ( j = 0; j < A + B; j ++ ) if ( j != i && j != k ) {
                                if( OneStep [k] [j] == -1 ) continue;
                                t = OneStep [i] [k] + OneStep [k] [j];
                                if ( t > L ) continue;
                                if ( OneStep [i] [j] == -1 || t < OneStep [i] [j] )
                                        OneStep [i] [j] = t;
                        }

        for ( k = 0; k < A + B; k ++ )
                for ( i = 0; i < A + B; i ++ ) if ( i != k && Dis [i] [k] != -1 )
                        for ( j = 0; j < A + B; j ++ ) if ( j != i && j != k ) {
                                if ( Dis [k] [j] == -1 ) continue;
                                t = Dis [i] [k] + Dis [k] [j];
                                if ( Dis [i] [j] == -1 || t < Dis [i] [j] )
                                        Dis [i] [j] = t;
                        }
}

void    Search ()
{
        int     i , j , k , t;
        memcpy ( Opt [0] , Dis [A + B - 1] , 4 * ( A + B ));
        Opt [0] [A + B - 1] = 0;
        
        for ( k = 0; k < K; k ++ ) {
                memcpy ( Opt [k + 1] , Opt [k] , 4 * ( A + B ));

                for ( i = 0; i < A + B; i ++ )
                        for ( j = 0; j < A + B; j ++ ) if ( OneStep [i] [j] != -1 && OneStep [i] [j] <= L ) {
                                if ( Opt [k] [i] < Opt [k + 1] [j] )
                                        Opt [k + 1] [j] = Opt [k] [i];
                                }

                memset ( Mark , 0 , sizeof ( Mark ));
                for ( i = 0; i < A + B; i ++ ) {
                        t = -1;
                        for ( j = 0; j < A + B; j ++ ) if ( !Mark [j] )
                                if ( t == -1 || Opt [k + 1] [j] < Opt [k + 1] [t] )
                                        t = j;
                        if ( t == -1 ) break;
                        
                        Mark [t] = 1;
                        for ( j = 0; j < A + B; j ++ ) if ( !Mark [j] )
                                if ( Dis [t] [j] >= 0 && Opt [k + 1] [t] + Dis [t] [j] < Opt [k + 1] [j] )
                                        Opt [k + 1] [j] = Opt [k + 1] [t] + Dis [t] [j];
                }
        }

}

main ()
{
        int     total;
        for ( scanf ( "%d" , &total ); total; total -- ) {
                init ();
                WorkForVillage ();
                Search ();
                printf ( "%d\n" , Opt [K] [0] );
        }
}

