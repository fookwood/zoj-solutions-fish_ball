#include <stdio.h>
#include <string.h>


bool     edge [25] [25];
int      N , M , Max , Len [25] , graph [25] [4];


bool     init ()
{
         scanf ( "%d%d" , &N , &M );
         if ( N == 0 || M == 0 ) return false;
         int  a , b;
         memset ( Len , 0 , sizeof ( Len ));
         for ( int i = 0; i < M; i ++ ) scanf ( "%d%d" , &a , &b ) , 
             graph [a] [Len [a] ++] = b , graph [b] [Len [b] ++] = a;
         return true;
}

void     Search ( int t , int depth = 0 )
{
         if ( depth > Max ) Max = depth;
         for ( int i = 0; i < Len [t]; i ++ ) if ( !edge [t] [graph [t] [i]] ) {
             edge [t] [graph [t] [i]] = edge [graph [t] [i]] [t] = true;
             Search ( graph [t] [i] , depth + 1 );
             edge [t] [graph [t] [i]] = edge [graph [t] [i]] [t] = false;
         }
}

main ()
{
     while ( init () ) {
           Max = 0;
           memset ( edge , 0 , sizeof ( edge ));
           for ( int i = 0; i < N; i ++ ) Search ( i );
           printf ( "%d\n" , Max );
     }
}
