#include <stdio.h>
#include <string.h>

int      Len , Many [256] [256] , Max;
char     Data [64 * 80 + 3];

bool     init ()
{
         int  N;
         scanf ( "%d\n" , &N ); if ( N == 0 ) return false;
         for ( Len = 0; N; N -- ) {
             gets ( &Data [Len] );
             Len += strlen ( &Data [Len] );
         }
         memset ( Many , 0 , sizeof ( Many ));
         Max = 0;
         for ( int i = 0; i + 1 < Len; i ++ ) {
             Many [Data [i]] [Data [i + 1]] ++;
             if ( Many [Data [i]] [Data [i + 1]] > Max )
                Max = Many [Data [i]] [Data [i + 1]];
         }
         return true;
}

void     PrintAns ()
{
         int      i , j , k , step = 0;
         for ( i = Max; i; i -- ) {
             for ( j = 0; j < 256; j ++ )
                 for ( k = 0; k < 256; k ++ ) if ( Many [j] [k] == i ) {
                     printf ( "%c%c %d %.6lf\n" , j , k , i , (double) i / ( Len - 1 ) );
                     if ( ++ step == 5 ) return;
                 }
         }
}

main ()
{
     while ( init () ) {
           PrintAns ();
           printf ( "\n" );
     }
           
}
