#include <stdio.h>
#include <string.h>


struct  node {
        int     len;
        int     data [4];
};

int     n , n4 , Ans;
int     candy [40] [4];
bool    Opt [41] [41] [41] [41];

node    data;

bool    init ()
{
        scanf ( "%d" , &n );
        if ( !n ) return false;

        n4 = n * 4;
        int     i , j;
        for ( i = 0; i < n; i ++ )
                for ( j = 0; j < 4; j ++ )
                        scanf ( "%d" , &candy [i] [j] );
        return true;
}

void    print ()
{
        int     i;
        for ( i = 0; i < data.len; i ++ )
                printf ( "%d " , data.data [i] );
        printf ( "\n" );
}

int     add ( int e )
{
        int     i;
        for ( i = 0; i < data.len; i ++ ) if ( data.data [i] == e ) {
                data.data [i] = data.data [data.len - 1];
                data.len --;
                return 1;
        }
        if ( data.len == 4 ) return 0;
        data.data [data.len] = e;
        data.len ++;
        return 1;
}

void    search ( int a , int b , int c , int d )
{
        if ( Opt [a] [b] [c] [d] ) return;

        int     t;
        node    save;
        
        Opt [a] [b] [c] [d] = 1;
        t = n4 - a - b - c - d + data.len;
        if ( t < Ans ) {
                Ans = t;
        }

        save = data;
        if ( a < n && add ( candy [a] [0] ) ) {
                search ( a + 1 , b , c , d );
                data = save;
        }
        if ( b < n && add ( candy [b] [1] ) ) {
                search ( a , b + 1 , c , d );
                data = save;
        }
        if ( c < n && add ( candy [c] [2] ) ) {
                search ( a , b , c + 1 , d );
                data = save;
        }
        if ( d < n && add ( candy [d] [3] ) ) {
                search ( a , b , c , d + 1 );
                data = save;
        }
}

main ()
{
        while ( init () ) {
                memset ( Opt , 0 , sizeof ( Opt ));
                Ans = 999999;
                data.len = 0;
                search ( 0 , 0 , 0 , 0 );
                printf ( "%d\n" , ( n4 - Ans ) / 2 ); 
        }
}
 