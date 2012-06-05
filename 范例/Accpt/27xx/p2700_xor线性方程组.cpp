#include <stdio.h>
#include <string.h>

#define n 400
#define m 130

struct TPol {
       int  s [m + 10];
       int& operator [] ( const int Index ) { return s [Index]; }
       int  operator [] ( const int Index ) const { return s [Index]; }
       bool init ();
       void print ();
};

TPol   a , b , c , A [n] , x;
int    Pos [n] , Num [n];

bool   solve ();

main ()
{
     while ( a.init () && b.init () && c.init () ) {
           if ( !solve () ) printf ( "no solution\n" );
           printf ( "\n" );
     }
}

bool solve ()
{
     memset ( A , 0 , sizeof ( A ));
     for ( int i = 0; i < m; i ++ )
         for ( int j = 0; j < m; j ++ )
             A [i + j + j] [j] ^= a [i] ,
             A [i + j] [j] ^= b [i];
     for ( int i = 0; i < m; i ++ ) A [i] [m] = c [i];
     
     int t = 0 , i , j , k;
     for ( int i = 0; i < n; i ++ ) {
         for ( j = 0; j <= m; j ++ ) if ( A [i] [j] ) break;
         if ( j == m ) return false;
         if ( j > m ) continue;
         
         for ( k = 0; k < n; k ++ ) if ( k != i && A [k] [j] )
             for ( int p = 0; p <= m; p ++ ) A [k] [p] ^= A [i] [p];
         Num [t] = i , Pos [t ++] = j;
     }
     memset ( x.s , 0 , sizeof ( x.s ));
     for ( int i = 0; i < t; i ++ )
         x [Pos [i]] = A [Num [i]] [m];
     x.print ();
     return true;
}

bool TPol :: init ()
{
     int len;
     if ( scanf ( "%d" , &len ) != 1 ) return false;
     memset ( s , 0 , sizeof ( s ));
     for ( int i = len; i >= 0; i -- )
         scanf ( "%d" , &s [i] );
     return true;
}

void TPol :: print ()
{
     int  i;
     for ( i = m - 1; i >= 0; i -- ) if ( s [i] ) break;
     for ( printf ( "%d " , i ); i >= 0; i -- ) printf ( " %d" , s [i] );
     printf ( "\n" );
}

