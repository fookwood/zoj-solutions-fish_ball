#include <stdio.h>
#include <algorithm>

using    namespace std;

int      N , Many [100] , Order [100] , Tot;
bool     Opt [100] [100] , FoundError;

bool cmp ( const int &a , const int &b )
{
     return Many [a] > Many [b];
}

main()
{
      bool  first = true;
      while ( scanf ( "%d" , &N ) , N ) {
            if ( first ) first = false; else printf ( "\n" );
            for ( int i = Tot = 0; i < N; i ++ ) scanf ( "%d" , &Many [i] ) , Tot += Many [i];
            if ( Tot & 1 ) {
                 printf ( "~><~\n" );
                 continue;
            }
            for ( int i = 0; i < N; i ++ ) Order [i] = i;
            memset ( Opt , 0 , sizeof ( Opt ));
            FoundError = false;
            do {
                sort ( Order , Order + N , cmp );
                if ( Many [Order [0]] == 0 ) break;
                for ( int i = 1; !FoundError && Many [Order [0]] && i < N; i ++ )
                    if ( Many [Order [i]] == 0 ) FoundError = true;
                    else Many [Order [i]] -- , Many [Order [0]] -- , Opt [Order [0]] [Order [i]] = Opt [Order [i]] [Order [0]] = true;
                if ( Many [Order [0]] ) FoundError = true;
            } while ( !FoundError );
            if ( FoundError ) {
                 printf ( "~><~\n" );
                 continue;
            }
            for ( int i = 0; i < N; i ++ ) {
                for ( int j = 0; j < N; j ++ ) {
                    if ( j ) printf ( " " );
                    printf ( "%d" , Opt [i] [j] ? 1 : 0 );
                }
                printf ( "\n" );
            }
      }
}
