// zju 2005
//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>

int     F , E , A , B;
int     father [100] , X [100] , Y [100];
bool    containa [100] , containb [100];

int     getfather ( int p )
{
        if ( father [p] != p ) father [p] = getfather ( father [p] );
        return father [p];
}

void    extended_gcd ( int a , int b , int &gcd , int &x , int &y )
{
        if ( b == 0 ) { gcd = a; x = 1; y = 0; }
        else { extended_gcd ( b , a % b , gcd , y , x ); y -= x * ( a / b ); }
}

bool    check ()
{
        if ( A == B ) return true;
        bool    noA = 1, noB = 1;
        int     i , j , gcd , x , y , ki , kj , xi , xj , tmp , fi , fj;
        for ( i = 0; i < E; i ++ ) {
                containa [i] = A >= Y [i] && ( A - Y [i] ) % X [i] == 0;
                containb [i] = B >= Y [i] && ( B - Y [i] ) % X [i] == 0;
                if ( containa [i] && containb [i] ) return true;
                if ( containa [i] ) noA = 0;
                if ( containb [i] ) noB = 0;
        }

        if ( noA || noB ) return false;

        for ( i = 0; i < E; i ++ )
                for ( j = i + 1; j < E; j ++ ) {
                        fi = getfather ( i ); fj = getfather ( j );
                        if ( fi == fj ) continue;

                        if ( X [i] >= X [j] ) extended_gcd ( X [i] , X [j] , gcd , x , y );
                                else extended_gcd ( X [j] , X [i] , gcd , y , x );

                        if ( Y [i] % gcd != Y [j] % gcd ) continue;

                        xi = X [i] / gcd; xj = X [j] / gcd;
                        y = ( Y [j] - Y [i] ) / gcd;
                        ki = ( y * x ) % xj; if ( ki < 0 ) ki = xj + ki;
                        kj = ( xi * ki - y ) / xj;

                        if ( kj < 0 ) tmp = ( - 1 - kj ) / xi + 1; else tmp = 0;
                        ki += tmp * xj; kj += tmp * xi;

                        if ( Y [i] + X [i] * ki < F ) {
                                father [fj] = fi;
                                containa [fi] |= containa [fj];
                                containb [fi] |= containb [fj];
                                if ( containa [fi] && containb [fi] ) return true;
                        }
                }
        return false;
}

int main(int argc, char* argv[])
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );
        
        int     total , t , i;
        for ( scanf ( "%d" ,&total ) , t = 0; t < total; t ++ ) {
                scanf ( "%d%d%d%d" , &F , &E , &A , &B );
                for ( i = 0; i < E; i ++ ) father [i] = i;
                for ( i = 0; i < E; i ++ ) scanf ( "%d%d" , &X [i] , &Y [i] );
                if ( check () ) printf ( "It is possible to move the furniture.\n" );
                        else printf ( "The furniture cannot be moved.\n" );
                
        }
        return 0;
}
//---------------------------------------------------------------------------
 