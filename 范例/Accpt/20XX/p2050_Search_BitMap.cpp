#include <stdio.h>
#include <string.h>

const    int      dx [4] = { 0 , 0 , -1 , 1 };
const    int      dy [4] = { -1 , 1 , 0 , 0 };

bool     Opt [1 << 16];
int      Change [16] , Start , Line [1 << 16];
char     map [4] [10];

void     print ( int t )
{
         for ( int i = 0; i < 4; i++ ) {
             for ( int j = 0; j < 4; j ++ ) if ( t & ( 1 << ( 4 * i + j )) ) printf ( "b" );
             else printf ( "w" );
             printf ( "\n" );
         }
         printf ( "\n" );
}

bool     range ( int x , int y )
{
         return x >= 0 && x < 4 && y >= 0 && y < 4;
}

void     prepare ()
{
         for ( int i = 0; i < 4; i ++ )
             for ( int j = 0; j < 4; j ++ ) {
                 Change [i * 4 + j] = 1 << ( i * 4 + j );
                 for ( int k = 0; k < 4; k ++ )
                     if ( range ( i + dx [k] , j + dy [k] ))
                        Change [i * 4 + j] |= 1 << ( 4 * ( i + dx [k] ) + j + dy [k] );
             }
}

void     init ()
{
         for ( int i = 0; i < 4; i ++ ) gets ( map [i] );
         Start = 0;
         for ( int i = 0; i < 4; i ++ )
             for ( int j = 0; j < 4; j ++ ) if ( map [i] [j] == 'b' )
                 Start |= 1 << ( 4 * i + j );
         getchar ();
}

void     C ( int t )
{
         for ( int e = 0; e < t; e ++ )
         for ( int i = 0; i < 10000; i ++ )
             for ( int j = 0; j < 10000; j ++ ) int d = i;
}

int      BFS ()
{
         if ( Start == 0 || Start + 1 == ( 1 << 16 ) ) return 0;
         memset ( Opt , 0 , sizeof ( Opt ));
         int    open = 0 , closed = 1 , i , next , step = 0 , LastClosed = 0;
         Opt [Start] = 0; Line [0] = Start;
         
         for ( ; open < closed; open ++ ) {
             if ( open == LastClosed ) LastClosed = closed  , step ++;
             
             for ( i = 0; i < 16; i ++ ) {
                 next = Line [open] ^ Change [i];
                 if ( Opt [next] ) continue;
                 if ( next == 0 || next + 1 == ( 1 << 16 )) return step;
                 Line [closed ++] = next ,Opt [next] = true;
             }
         }
         return  -1;
}

main ()
{
     prepare ();
     int     Total;
     for ( scanf ( "%d\n\n" , &Total ); Total; Total -- ) {
         init ();
         int  Ans = BFS ();
         if ( Ans == -1 ) printf ( "Impossible\n" ); else printf ( "%d\n" , Ans );
         if ( Total > 1 ) printf ( "\n" );
     }
}
