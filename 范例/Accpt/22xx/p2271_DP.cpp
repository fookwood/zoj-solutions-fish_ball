#include <stdio.h>
#include <string.h>

const    int       dx [4] = { 0 , 0 , -1 , 1 };
const    int       dy [4] = { -1 , 1 , 0 , 0 };

int      N , Face [100] [100];
bool     Ran [100] [100];
double   Opt [101] [100] [100] , Answer [100];

bool     range ( int x , int y )
{
         return x >= 0 && x < N && y >= 0 && y < N;
}

double   Ans ()
{
         if ( Answer [N - 1] >= 0 ) return Answer [N - 1];
         memset ( Face , 0 , sizeof ( Face ));
         for ( int i = 0; i < N; i ++ )
             for ( int j = 0; j < N; j ++ )
                 for ( int k = Face [i] [j] = 0; k < 4; k ++ )
                     if ( range ( i + dx [k] , j + dy [k] )) Face [i] [j] ++;
         
         double    Ret = 0;
         memset ( Opt [0] , 0 , sizeof ( Opt [0] ));
         Opt [0] [N / 2] [N / 2] = 1;
         int k  , i , j , t , x , y;
         
         for ( k = 0; k < N; k ++ ) {
             for ( i = 0; i < N; i ++ )
                 for ( j = 0; j < N; j ++ ) {
                     Opt [k + 1] [i] [j] = 0;
                     for ( t = 0; t < 4; t ++ ) {
                         x = i + dx [t] , y = j + dy [t];
                         if ( x >= 0 && x < N && y >= 0 && y < N )
                            Opt [k + 1] [i] [j] += Opt [k] [x] [y] / Face [x] [y];
                     }
                 }
             Ret += Opt [k + 1] [N / 2] [k];
             Opt [k + 1] [N / 2] [k] = 0;
         }
         Answer [N - 1] = Ret;
         return  Ret;
}

main ()
{
     for ( int i = 0; i < 100; i ++ ) Answer [i] = -1;
     while ( scanf ( "%d" , &N ) != EOF )
           printf ( "%.4lf\n" , Ans ());
}
