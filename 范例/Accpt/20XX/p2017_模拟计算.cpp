#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define  MAXN      400
#define  max(a,b) (a>b?a:b)

struct   HP {
         int len , s [MAXN];
}        A , B;

char     Str [MAXN * 2 + 1] , Oper;

void     back ( HP & A )
{
         for ( int j = 0; j < A.len / 2; j ++ )
             A.s [j] ^= A.s [A.len - j - 1] ^= A.s [j] ^= A.s [A.len - j - 1];
}

void     print ( const HP &A )
{
         for ( int i = A.len - 1; i >= 0; i -- ) printf ( "%d" , A.s [i] );
         printf ( "\n" );
}

void     part ()
{
         int  len = strlen ( Str ) , i;
         for ( i = 0; isdigit ( Str [i] ); i ++ )
             A.s [i] = Str [i] - '0';
         A.len = i; Oper = Str [i];
         for ( int j = ++i; j < len; j ++ )
             B.s [j - i] = Str [j] - '0';
         B.len = len - i;
         back ( A ) , back ( B );
//         print ( A ) , print ( B );
}

void     print_ ( int many , int wide = 0 )
{
         for ( int i = 0; i < wide - many; i ++ ) printf ( " " );
         for ( int i = 0; i < many; i ++ ) printf ( "-" );
}

void     Addition ()
{
         int      Max = max ( A.len , B.len + 1 );
         HP       C;
         int      i , j;
         for ( i = 0 , j = 0; i < A.len || i < B.len; i ++ , j /= 10 ) {
             if ( i < A.len ) j += A.s [i];
             if ( i < B.len ) j += B.s [i];
             C.s [i] = j % 10;
         }
         while ( j ) C.s [i++] = j % 10 , j /= 10; C.len = i;
         Max = max ( Max , C.len );
         
         print_ ( 0 , Max - A.len ) , print ( A );
         print_ ( 0 , Max - B.len - 1 ) , printf ( "+" ) , print ( B );
         print_ ( max ( B.len + 1 , C.len ), Max ); printf ( "\n" );
         print_ ( 0 , Max - C.len ); print ( C );
}

void     Subtration ()
{
         int      Max = max ( A.len , B.len + 1 );
         HP       C;
         int      i , j;
         for ( i = 0 , j = 0; i < A.len; i ++ ) {
             C.s [i] = A.s [i] - j;
             if ( i < B.len ) C.s [i] -= B.s [i];
             if ( C.s [i] < 0 ) C.s [i] += 10 , j = 1;
             else j = 0;
         }
         for ( C.len = A.len; C.len > 1 && C.s [C.len - 1] == 0; C.len -- );
         Max = max ( Max , C.len );
         
         print_ ( 0 , Max - A.len ) , print ( A );
         print_ ( 0 , Max - B.len - 1 ) , printf ( "-" ) , print ( B );
         print_ ( max ( B.len + 1 , C.len ) , Max ) , printf ( "\n" );
         print_ ( 0 , Max - C.len ) , print ( C );
}

void     Multiply ()
{
         int      Max = max ( A.len , B.len + 1 );
         HP       Sub [MAXN] , Ans;
         int      i , j , k;
         for ( k = 0; k < B.len; k ++ ) {
             for ( i = j = 0; i < A.len; i ++ , j /= 10 ) {
                 j += A.s [i] * B.s [k];
                 Sub [k].s [i] = j % 10;
             }
             while ( j ) Sub [k].s [i ++] = j % 10 , j /= 10;
             Sub [k].len = i;
             while ( Sub [k].len > 1 && Sub [k].s [Sub [k].len - 1] == 0 ) Sub [k].len --;
             Max = max ( Max , Sub [k].len + k );
         }
         
         memset ( Ans.s , 0 , sizeof ( Ans.s ));
         for ( i = 0; i < A.len; i ++ )
             for ( j = 0; j < B.len; j ++ ) Ans.s [i + j] += A.s [i] * B.s [j];
         Ans.len = A.len + B.len - 1;
         for ( i = j = 0; i < Ans.len; i ++ , j /= 10 )
             j += Ans.s [i] , Ans.s [i] = j % 10;
         while ( j ) Ans.s [Ans.len ++] = j % 10 , j /= 10;
         while ( Ans.len > 1 && Ans.s [Ans.len - 1] == 0 ) Ans.len --;
         Max = max ( Max , Ans.len );
         
         print_ ( 0 , Max - A.len ) , print ( A );
         print_ ( 0 , Max - B.len - 1 ) , printf ( "*" ) , print ( B );
         print_ ( max ( B.len + 1 , Sub [0].len ) , Max ) , printf ( "\n" );
         for ( k = 0; k < B.len; k ++ )
             print_ ( 0 , Max - k - Sub [k].len ) , print ( Sub [k] );
         if ( B.len <= 1 ) return;
         print_ ( Ans.len , Max ) , printf ( "\n" );
         print_ ( 0 , Max - Ans.len ) , print ( Ans );
         
}

main ()
{
     int total;
     for ( scanf ( "%d\n" , &total ); total; total -- ) {
         gets ( Str );
         part ();
         switch ( Oper ) {
                case   '+'  : Addition (); break;
                case   '-'  : Subtration (); break;
                case   '*'  : Multiply (); break;
         }
         printf ( "\n" );
     }
}
