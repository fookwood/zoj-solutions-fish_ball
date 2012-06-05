#include <stdio.h>
#include <math.h>

const   int maxn    = 1000;

int     x [maxn] , y [maxn];

int     Px , Py;
double  R;
int     n;
int     Tot;

void    init ()
{
        int     i;
        int     a , b;
        scanf ( "%d" , &n );
        for ( i = 0 , Tot = 0; i < n; i ++ ) {
                scanf ( "%d %d" , &a , &b );
                if ( sqrt ( (a - Px) * (a - Px) + (b - Py) * ( b - Py )) > R ) continue;
                x [Tot] = a; y [Tot] = b;
                Tot ++;
        }
}

int     max ()
{
        int     i , j , L , R;
        int     mul;
        int     ret = 0;
        for ( i = 0; i < Tot; i ++ ) {
                L = R = 0;
                for ( j = 0; j < Tot; j ++ ) {
                        mul = x [i] * y [j] - x [j] * y [i] + ( y [i] - y [j] ) * Px - ( x [i] - x [j] ) * Py;
                        if ( mul > 0 ) L ++;
                        else if ( mul < 0 ) R ++;
                        else { L ++; R ++; }
                }
                if ( L > ret ) ret = L;
                if ( R > ret ) ret = R;
        }
        return ( ret );
}

main ()
{
        while ( 1 ) {
                scanf ( "%d %d %lf" , &Px , &Py , &R );
                if ( R <= 0 ) break;
                init ();
                printf ( "%d\n" , max ());
        }
}
