#include <stdio.h>

int     N;
char    Data [2000] [7];
char    dis [2000] [2000];
char    min [2000];
bool    Reach [2000];

void    init ()
{
        int     i , j , k ;
        for ( i = 0; i < N; i ++ )
                scanf ( "%s" , Data [i] );
                
        for ( i = 0; i < N; i ++ )
                for ( j = i + 1; j < N; j ++ ) {
                        dis [i] [j] = 0;
                        for ( k = 0; k < 7; k ++ )
                                if ( Data [i] [k] != Data [j] [k] )
                                        dis [i] [j] ++;
                        dis [j] [i] = dis [i] [j];
                }
}

int     Prim ()
{
        int     i , j , k , ret;
        for ( i = 1; i < N; i ++ ) {
                min [i] = dis [0] [i];
                Reach [i] = 0;
        } Reach [0] = 1;
        
        for ( i = 1 , ret = 0; i < N; i ++ ) {
                k = -1;
                for ( j = 1; j < N; j ++ ) if ( !Reach [j] )
                        if ( k == -1 || min [j] < min [k] ) k = j;
                if ( k == -1 ) break;
                Reach [k] = 1;
                ret += min [k];
                for ( j = 1; j < N; j ++ ) if ( !Reach [j] && dis [k] [j] < min [j] )
                        min [j] = dis [k] [j];
        }
        return ret;
}

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );
        
        while ( scanf ( "%d" , &N ) , N ) {
                init ();
                printf ( "The highest possible quality is 1/%d.\n" , Prim ());
        }
}
 