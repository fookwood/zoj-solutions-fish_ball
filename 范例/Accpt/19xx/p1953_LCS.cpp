#include <stdio.h>
#include <string.h>
#define  MAXN      200
#define  max(a,b) (a>b?a:b)
char     Str1 [MAXN] , Str2 [MAXN] , Opt [MAXN] [MAXN];

int      len1 , len2;

void     Work ( int a , int b )
{
         if ( a == 0 && b == 0 ) return;
         if ( a == 0 ) { Work ( a , b - 1 ); printf ( "%c" , Str2 [b - 1] ); return; }
         if ( b == 0 ) { Work ( a - 1 , b ); printf ( "%c" , Str1 [a - 1] ); return; }
         if ( Str1 [a - 1] == Str2 [b - 1] ) { Work ( a - 1 , b - 1 ); printf ( "%c" , Str1 [a - 1] ); return; }
         if ( Opt [a - 1] [b] == Opt [a] [b] ) { Work ( a - 1 , b ); printf ( "%c" , Str1 [a - 1] ); return; }
         Work ( a , b - 1 ); printf ( "%c" , Str2 [b - 1] );
}

main ()
{
     while ( scanf ( "%s%s" , Str1 , Str2 ) != EOF ) {
           memset ( Opt , 0 , sizeof ( Opt ));
           len1 = strlen ( Str1 ) , len2 = strlen ( Str2 );
           for ( int i = 1; i <= len1; i ++ )
               for ( int j = 1; j <= len2; j ++ )
                   if ( Str1 [i - 1] == Str2 [j - 1] ) Opt [i] [j] = Opt [i - 1] [j - 1] + 1;
                      else Opt [i] [j] = max ( Opt [i - 1] [j] , Opt [i] [j - 1] );
           Work ( len1 , len2 );
           printf ( "\n" );
     }
}
