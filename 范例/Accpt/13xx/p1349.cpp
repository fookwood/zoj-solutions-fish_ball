#include <stdio.h>

const   int     PlayA [3] [3] = {1 , 1 , 2 , 0 , 0 , 1 , -1 , 0 , 0 };
const   int     PlayB [3] [3] = {0 , -1 , -1, 1 , 0 , 0 , 2 , 0 , -1};
const   double  W [3] = { 0.25 , 0.5 , 0.25 };

double  Awins [21] , Bwins [21] , Tie [21];
double  Opt [21] [61] [61];

main ()
{
        int     i , j , k;
        int     p1 , p2;
        for ( i = 0; i < 21; i ++ )
                for ( j = 0; j < 61; j ++ )
                        for ( k = 0; k < 61; k ++ )
                                Opt [i] [j] [k] = 0;

        for ( i = 0; i < 21; i ++ ) Awins [i] = Bwins [i] = Tie [i] = 0;

        Opt [0] [20] [20] = 1;

        for ( k = 0; k < 20; k ++ )
                for ( i = 0; i < 61; i ++ )
                        for ( j = 0; j < 61; j ++ ) if ( Opt [k] [i] [j] > 0 ) {
                                for ( p1 = 0; p1 < 3; p1 ++ )
                                        for ( p2 = 0; p2 < 3; p2 ++ )
                                                Opt [k + 1] [i + PlayA [p1] [p2]] [j + PlayB [p1] [p2]] += Opt [k] [i] [j] * W [p1] * W [p2];
                        }

        for ( k = 0; k < 21; k ++ ) {
                for ( i = 0; i < 61; i ++ )
                        for ( j = 0; j < i; j ++ )
                                Awins [k] += Opt [k] [i] [j];
                for ( i = 0; i < 61; i ++ )
                        for ( j = i + 1; j < 61; j ++ )
                                Bwins [k] += Opt [k] [i] [j];
                for ( i = 0; i < 61; i ++ )
                        Tie [k] += Opt [k] [i] [i];
        }

        printf ( "Round   A wins    B wins    Tie\n" );
        for ( i = 1; i < 21; i ++ ) {
                printf ( "%5d%10.4f%c%9.4f%c%9.4f%\n" , i , Awins [i] * 100 , '%' , Bwins [i] * 100 , '%' , Tie [i] * 100 );
        }
}
 