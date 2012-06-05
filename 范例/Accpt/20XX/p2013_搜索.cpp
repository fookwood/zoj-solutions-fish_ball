#include <stdio.h>
#include <string.h>

const    int      dx [4] = { 0 , 0 , -1 , 1 };
const    int      dy [4] = { -1 , 1 , 0 , 0 };

int      N , M , Ans;
bool     Searched [1000] [1000];
int      Opt [1000] [1000];
char     map [1000] [1001];

bool     range ( int x , int y )
{
         return x >= 0 && x < N && y >= 0 && y < M;
}

int      Search ( int x , int y )
{
         if ( !range ( x , y ) || Searched [x] [y] || map [x] [y] == '#' ) return 0;
         if ( Opt [x] [y] ) return Opt [x] [y];
         Searched [x] [y] = true;
         int    S [4];
         for ( int    i = 0; i < 4; i ++ ) S [i] = Search ( x + dx [i] , y + dy [i] );
         for ( int i = 0; i < 2; i ++ )
             for ( int j = i + 1; j < 4; j ++ ) if ( S [i] < S [j] ) {
                 int   t = S [i];
                 S [i] = S [j] , S [j] = t;
             }
         Opt [x] [y] = S [0] + 1;
         if ( S [0] + S [1] > Ans ) Ans = S [0] + S [1];
         return  Opt [x] [y];
}

main ()
{
     int total;
     for ( scanf ( "%d" , &total ); total; total -- ) {
         scanf ( "%d%d\n" , &M , &N );
         for ( int i = 0; i < N; i ++ ) gets ( map [i] );
         Ans = 0;
         memset ( Opt , 0 , sizeof ( Opt ));
         memset ( Searched , 0 , sizeof ( Searched ));
         for ( int i = 0; i < N; i ++ )
             for ( int j = 0; j < M; j ++ ) if ( map [i] [j] == '.' && Opt [i] [j] == 0 )
                 Search ( i , j );

         printf ( "Maximum rope length is %d.\n" , Ans );
     }
}
