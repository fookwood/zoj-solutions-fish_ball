#include <stdio.h>
#include <string.h>

#define n 230
#define m 110

struct TPol {
       int  s [n];
       int& operator [] ( const int Index ) { return s [Index]; }
       int  operator [] ( const int Index ) const { return s [Index]; }
       bool init ();
       void print ();
};

int    Pos [n * 2] , Num [n * 2];
TPol   a1 , a2 , b1 , b2 , c1 , c2 , A [n * 2] , x1 , x2;

bool   check ();

main ()
{
     while ( a1.init () && b1.init () && c1.init () && a2.init () && b2.init () && c2.init () ) {
           if ( !check () ) printf ( "No solution\n" );
           else x1.print () , x2.print ();
           printf ( "\n" );
     }
}

bool check ()
{
     memset ( A , 0 , sizeof ( A ));
     for ( int i = 0; i < m; i ++ )
         for ( int j = 0; j < m; j ++ )
         A [i + j + 0] [j + 0] ^= a1 [i] ,
         A [i + j + 0] [j + m] ^= b1 [i] ,
         A [i + j + n] [j + 0] ^= a2 [i] ,
         A [i + j + n] [j + m] ^= b2 [i];
     
     for ( int i = 0; i < m; i ++ )
         A [i] [2 * m] = c1 [i] , A [i + n] [2 * m] = c2 [i];
     
     int i , j , t = 0;
     for ( i = 0; i < n + n; i ++ ) {
         for ( j = 0; j <= m + m; j ++ ) if ( A [i] [j] ) break;
         if ( j == m + m ) return false;
         if ( j > m + m ) continue;
         
         for ( int k = 0; k < n + n; k ++ ) if ( k != i && A [k] [j] )
             for ( int d = 0; d <= m + m; d ++ ) A [k] [d] ^= A [i] [d];
         
         Num [t] = i , Pos [t ++] = j;
     }
     memset ( x1.s , 0 , sizeof ( x1.s ));
     memset ( x2.s , 0 , sizeof ( x2.s ));
     for ( int i = 0; i < t; i ++ )
         if ( Pos [i] < m ) x1 [Pos [i]] = A [Num [i]] [m + m];
         else x2 [Pos [i] - m] = A [Num [i]] [m + m];
     
     return true;
}

bool TPol :: init ()
{
     int  len;
     if ( scanf ( "%d" , &len ) != 1 ) return false;
     memset ( s , 0 , sizeof ( s ));
     for ( int i = len; i >= 0; i -- ) scanf ( "%d" , &s [i] );
     return true;
}

void TPol :: print ()
{
     int  i;
     for ( i = n; i >= 0; i -- ) if ( s [i] ) break;
     printf ( "%d" , i );
     for ( ; i >= 0; i -- ) printf ( " %d" , s [i] );
     printf ( "\n" );
}
