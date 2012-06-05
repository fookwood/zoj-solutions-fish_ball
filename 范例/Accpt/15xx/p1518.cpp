#include <stdio.h>
#include <string.h>
#define MAX     1001

int     Inconsistent;
int     N , max;
int     UnGroup [MAX] , Father [MAX] , Member [MAX];

int     find ( int p )
{
        if ( Father [p] != p ) Father [p] = find ( Father [p] );
        return  Father [p];
}

void    Union ( int p , int q )
{
        if ( p == q ) return;
        Father [p] = q , Member [q] += Member [p];
        if ( UnGroup [q] == -1 ) UnGroup [q] = UnGroup [p];
                else if ( UnGroup [p] != -1 ) Father [UnGroup [p]] = UnGroup [q] , Member [UnGroup [q]] += Member [UnGroup [p]];
        if ( UnGroup [q] != -1 ) UnGroup [UnGroup [q]] = q;
}

main ()
{
        int     i , j , fi , fj;
        char    state [10];

        while ( scanf ( "%d\n" , &N ) , N ) {
                Inconsistent = false;
                for ( i = 1; i <= N; i ++ ) UnGroup [i] = -1 , Father [i] = i , Member [i] = 1;
                
                for ( i = 1; i <= N; i ++ ) {
                        scanf ( "Sentence %d is %s\n" , &j , state );
                        if ( Inconsistent ) continue;
                        if ( i == j ) {
                                if ( state [0] != 't' ) Inconsistent = true; 
                                continue;
                        }
                        fi = find ( i ) , fj = find ( j );
                        if ( state [0] == 't' ) {
                                if ( UnGroup [fi] == fj ) Inconsistent = true;
                                        else Union ( fi , fj );
                        } else {
                                if ( fi == fj ) Inconsistent = true;
                                        else if ( UnGroup [fi] != -1 ) Union ( UnGroup [fi] , fj );
                                                else if ( UnGroup [fj] != -1 ) Union ( fi , UnGroup [fj] );
                                                        else UnGroup [fi] = fj , UnGroup [fj] = fi;
                        }
                }

                if ( !Inconsistent )
                        for ( max = 0 , i = 1; i <= N; i ++ ) if ( Father [i] == i && UnGroup [i] < i )
                                max += UnGroup [i] == -1 || Member [UnGroup [i]] < Member [i] ? Member [i] : Member [UnGroup [i]];

                if ( Inconsistent ) printf ( "Inconsistent\n" );
                        else printf ( "%d\n" , max );
        }
}
 