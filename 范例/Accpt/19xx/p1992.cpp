#include <stdio.h>
#include <string.h>
#define MAX     200

int     N , M , degree [MAX] , drain [MAX] [MAX] , prev [MAX] , src [MAX];
bool    mk [MAX];

void    init ()
{
        int     i , a , b , c;
        
        memset ( degree , 0 , sizeof ( degree ));
        memset ( drain , 0 , sizeof ( drain ));
        scanf ( "%d%d" , &N , &M );
        for ( i = 0; i < M; i ++ ) {
                scanf ( "%d%d%d" , &a , &b , &c );
                degree [-- a] -- , degree [-- b] ++;
                if ( c == 0 ) drain [b] [a] += 2;
        }
}

bool    change ( int st )
{
        int     i , k , tmp;
        bool    found = false;
        memset ( mk , 0 , N );
        memset ( src , 0 , N << 2 );
        src [st] = degree [st];

        while ( !found ) {
                k = -1;
                for ( i = 0; i < N; i ++ ) if ( !mk [i] )
                        if ( k == -1 || src [i] > src [k] ) k = i;
                if ( k == -1 || src [k] == 0 ) return false;
                mk [k] = true;
                if ( degree [k] < 0 ) break;
                for ( i = 0; i < N; i ++ ) if ( !mk [i] && drain [k] [i] > 0 ) {
                        tmp = drain [k] [i] < src [k] ? drain [k] [i] : src [k];
                        if ( tmp > src [i] ) src [i] = tmp , prev [i] = k;
                }
        }
        tmp = - degree [k] < src [k] ? - degree [k] : src [k];
        degree [st] -= tmp , degree [k] += tmp;
        for ( i = k; i != st; i = prev [i] ) drain [i] [prev [i]] += tmp , drain [prev [i]] [i] -= tmp;
        return true;
}

bool    check ()
{
        int     i = 0;
        for ( i = 0; i < N; i ++ ) if ( degree [i] & 1 ) return false;

        i = 0;
        while ( true ) {
                while ( i < N && degree [i] <= 0 ) i ++;
                if ( i == N ) return true;
                if ( !change ( i ) ) return false;
        }
}

main ()
{
        int     total;
        for ( scanf ( "%d" , &total ); total; total -- ) {
                init ();
                if ( check () ) printf ( "possible\n" );
                        else printf ( "impossible\n" );
        }
}
 