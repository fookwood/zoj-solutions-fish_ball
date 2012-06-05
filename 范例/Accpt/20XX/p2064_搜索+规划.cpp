#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

#define MAXN      15
#define Limit     16

const   int dx [4] = { 0 , 0 , - 1, 1 };
const   int dy [4] = { -1 , 1 , 0 , 0 };

int     N , M , Cut [MAXN * MAXN] , Num [MAXN] [MAXN] , Pow [31] , Min , opt [1 << 16];
char    map [MAXN] [MAXN + 2];

bool    init ();
void    Search ( int , int , int );

int     f ( int );

main ()
{
     while ( init () ) {
           Min = 0x7fffffff;
           if ( M <= Limit ) {
                printf ( "%d\n" , opt [Pow [M] - 1] );
                continue;
           }
           Search ( Pow [M] - 1 , 0 , Pow [M - 1] );
           printf ( "%d\n" , Min );
     }
}

int  f ( int S )
{
     if ( opt [S] != -1 ) return opt [S];
     int  t;
     opt [S] = 0x7fffffff;
     for ( int i = 0; i < N; i ++ ) if ( S & Cut [i] ) {
         t = f ( S & (~Cut [i]) ) + 1;
         if ( t < opt [S] ) opt [S] = t;
     }
     return opt [S];
}

void Search ( int S , int get , int last )
{
     if ( get >= Min ) return;
     if ( S == 0 ) {
          Min = get;
          return;
     }
     if ( S < Pow [Limit] ) {
          if ( get + opt [S] >= Min ) return;
          Min = get + opt [S];
          return;
     }
     int  next , nS;
     for ( int i = 0; i < N; i ++ ) if ( ( Cut [i] & last ) ) {
         nS = S & (~ Cut [i]);
         for ( next = last; next && ( nS & next ) == 0; next >>= 1 );
         Search ( nS , get + 1 , next );
     }
}

bool init ()
{
     int  n , m , x , y;
     if ( scanf ( "%d%d\n" , &n , &m ) == EOF ) return false;
     for ( int i = 0; i < n; i ++ )
         gets ( map [i] );
     for ( int i = M = 0; i < n; i ++ )
         for ( int j = 0; j < m; j ++ ) if ( map [i] [j] == '#' )
             Num [i] [j] = M ++;
     for ( int i = 0; i < 31; i ++ ) Pow [i] = 1 << i;
     for ( int i = N = 0; i < n; i ++ )
         for ( int j = 0; j < m; j ++ ) if ( map [i] [j] == '.' ) {
             Cut [N] = 0;
             for ( int k = 0; k < 4; k ++ ) {
                 for ( x = i , y = j; map [x] [y] == '.'; x += dx [k] , y += dy [k] );
                 if ( map [x] [y] == '#' ) Cut [N] |= Pow [Num [x] [y]];
             }
             N ++;
         }
     sort ( Cut , Cut + N , greater <int> () );
     for ( int i = 0; i < N; i ++ )
         for ( int j = i + 1; j < N; j ++ ) {
             if ( i >= N || j >= N ) continue;
             if ( ( Cut [i] & Cut [j] ) == Cut [j] ) {
                for ( int k = j; k + 1 < N; k ++ ) Cut [k] = Cut [k + 1];
                N -- , j --;
             }
         }
     memset ( opt , 0xff , sizeof ( opt ));
     opt [0] = 0;
     f ( Pow [min ( M , Limit )] - 1 );
     return true;
}
