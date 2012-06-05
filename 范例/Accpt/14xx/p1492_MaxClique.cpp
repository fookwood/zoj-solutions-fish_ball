// zju 1492
// max clique
#include <stdio.h>

bool    found;
int     N;
int     c [50] , max;
bool    Line [50] [50];

struct  set {
        int     Size;
        bool    Contain [50];
        set operator & ( set a );
}       U , Nv [50];

set set :: operator & ( set a )
{
        set     T;
        int     i;
        T.Size = 0;
        for ( i = 0; i < N; i ++ ) {
                T.Contain [i] = Contain [i] && a.Contain [i];
                if ( T.Contain [i] ) T.Size ++;
        }
        return T;
}

bool    init ()
{
        scanf ( "%d" , &N ); if ( N == 0 ) return false;
        int     i , j;
        for ( i = 0; i < N; i ++ ) {
                Nv [i].Size = 0;
                for ( j = 0; j < N; j ++ ) {
                        scanf ( "%d" , &Line [i] [j] );
                        Nv [i].Contain [j] = Line [i] [j];
                        if ( Line [i] [j] ) Nv [i].Size ++;
                }
        }
        return true;
}

void    Clique ( set &U , int Size )
{
        if ( U.Size == 0 ) {
                if ( Size > max ) {
                        max = Size;
                        found = 1;
                }
                return;
        }
        int     i;
        set     Next;
        while ( U.Size ) {
                if ( Size + U.Size < max ) return;
                for ( i = 0; !U.Contain [i]; i ++ );
                if ( Size + c [i] < max ) return;
                U.Size --; U.Contain [i] = 0;
                Next = U & Nv [i];
                Clique ( Next , Size + 1 );
        }
}

main ()
{
        int     i;
        set     P;
        while ( init () ) {
                max = 0;
                P.Size = 0;
                for ( i = 0; i < N; i ++ ) P.Contain [i] = 0;

                for ( i = N - 1; i >= 0; i -- ) {
                        found = 0;
                        P.Size ++; P.Contain [i] = 1;
                        U = P & Nv [i];
                        Clique ( U , 1 );
                        c [i] = max;
                }
                printf ( "%d\n" , max );
        }
}
 