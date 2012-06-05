#include <stdio.h>
#include <string.h>

int      N , M;
char     Map [100] [100];
char     Str [100];

main ()
{
     while ( scanf ( "%s" , Str ) , strcmp ( "ENDOFINPUT" , Str ) ) {
           scanf ( "%d%d\n" , &N , &M );
           for ( int i = 0; i < N; i ++ ) gets ( Map [i] );
           for ( int i = 0; i + 1 < N; i ++ ) {
               for ( int j = 0; j + 1 < M; j ++ ) printf ( "%c" , ( Map [i] [j] + Map [i + 1] [j] + Map [i] [j + 1] + Map [i + 1] [j + 1] ) / 4 );
               printf ( "\n" );
           }
           gets ( Str );
     }
}
