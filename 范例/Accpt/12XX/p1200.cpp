#include <stdio.h>

const   int     maxLimit        = 10000;

int     Len;
int     Heap [maxLimit];

int     GoTime;
int     TimeLine;

int     S , W , C , M;

bool    init ()
{
        if ( scanf ( "%d" , &S ) == EOF ) return false;
        scanf ( "%d %d %d %d" , &W , &C , &Len , &M );

        GoTime = 9999 / C + 1;
        if ( Len > GoTime ) Len = GoTime;
        for ( int i = 0; i < Len; i ++ )
                Heap [i] = M * ( i + 1 ) + S;
        return true;
}

void    push ()
{
        int     k = 0 , t , Next;
        if ( Heap [k] > TimeLine ) TimeLine = Heap [k];
        Heap [k] += S + S + W;
        TimeLine += W;
        
        t = Heap [k]; Next = k * 2 + 1;
        while ( Next < Len ) {
                if ( Next + 1 < Len && Heap [Next + 1] < Heap [Next] ) Next ++;
                if ( Heap [Next] < t ) {
                        Heap [k] = Heap [Next];
                        k = Next;
                        Next = k * 2 + 1;
                } else break;
        }
        Heap [k] = t;

}

main ()
{
        int     i;
        while ( init () ) {
                TimeLine = 0;
                for ( i = 0; i < GoTime; i ++ ) push ();
                printf ( "%d\n" , TimeLine + S );
        }
}
 