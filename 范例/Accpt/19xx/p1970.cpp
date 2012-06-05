#include <stdio.h>
#include <string.h>

char     Str1 [500000] , Str2 [500000];

main ()
{
     int i , Reach , len1 , len2;
     while ( scanf ( "%s%s" , Str1 , Str2 ) != EOF ) {
           len1 = strlen ( Str1 ) , len2 = strlen ( Str2 );
           for ( Reach = 0 , i = 0; i < len2; i ++ ) {
               if ( Str2 [i] == Str1 [Reach] ) Reach ++;
               if ( Reach == len1 ) break;
           }
           printf ( "%s\n" , Reach == len1 ? "Yes" : "No" );
     }
}
