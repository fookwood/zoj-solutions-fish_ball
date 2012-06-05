#include <stdio.h>
#include <string.h>

char     map [1024] [2048];

void     PutMap ( int x , int y )
{
         map [x] [y + 1] = map [x + 1] [y] = '/';
         map [x] [y + 2] = map [x + 1] [y + 3] = '\\';
         map [x + 1] [y + 1] = map [x + 1] [y + 2] = '_';
}

void     FillMap ( int x , int y , int l )
{
         if ( l == 2 ) { PutMap ( x , y ); return; }
         FillMap ( x , y + l / 2 , l / 2 );
         FillMap ( x + l / 2 , y , l / 2 );
         FillMap ( x + l / 2 , y + l , l / 2 );
}

void     makemap ()
{
         int     l = 1024;
         memset ( map , ' ' , sizeof ( map ));
         FillMap ( 0 , 0 , l );
}

void     PrintMap ( int N )
{
         int      i , j , l = 1 << N;
         for ( i = 0; i < l; i ++ ) {
             for ( j = 0; j <= l + i; j ++ )
                 printf ( "%c" , map [1024 - l + i] [j] );
             printf ( "\n" );
         }
}

main ()
{
     int N;
     makemap ();
     while ( scanf ( "%d" , &N ) , N ) {
           PrintMap ( N );
           printf ( "\n" );
     }
}
