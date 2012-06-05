#include <stdio.h>
#include <string.h>

#define MAXM   10010

int     Time [MAXM] , U , N;
char    Name [MAXM] [100];

void    init ();
void    solve ();

main ()
{
     int total , p = 0;
     for ( scanf ( "%d" , &total ); total; total -- ) {
         printf ( "Case %d:\n" , ++p );
         init ();
         solve ();
         if ( total > 1 ) printf ( "\n" );
     }
}

void solve ()
{
     int   Max = 0x7fffffff , k;
     for ( int i = 0; i <= U; i ++ ) if ( Time [i] && Time [i] < Max )
         Max = Time [i] , k = i;
     printf ( "The winner is %s.\n" , Name [k] );
     printf ( "The price is %d.\n" , k );
}

void init ()

{
     scanf ( "%d%d\n" , &U , &N );
     memset ( Time , 0 , sizeof ( Time ));
     int    t;
     char   Str [100];
     for ( int i = 0; i < N; i ++ ) {
         scanf ( "%s%d\n" , Str , &t );
         if ( t > U ) continue;
         Time [t] ++;
         if ( Time [t] == 1 ) strcpy ( Name [t] , Str );
     }
}
