#include <stdio.h>
#include <math.h>
#include <algorithm>
#define zero    1e-10

using   namespace std;

const   double  pi = 3.141592653589;

double  R , Angle [100];
int     N , Long [100];

double  TotalAngle ()
{
        int     i;
        double  Ret = 0;
        for ( i = 0; i < N; i ++ )
                Angle [i] = asin ( double ( Long [i] ) / R / 2.0 ) , Ret += Angle [i];
        return  Ret;
}

double  Area ( int p )
{
        return  R * Long [p] * cos ( Angle [p] ) / 2.0;
}

double  MaxArea ()
{
        int     i , tmp;
        
        for ( tmp = i = 0; i < N - 1; i ++ ) tmp += Long [i];
        if ( tmp <= Long [N - 1] ) return 0.0;


        double  Low = Long [N - 1] / 2.0 , High = 1e4 , Key , Ret = 0;

        R = Low , Key = TotalAngle ();
        if ( fabs ( Key - pi ) > zero ) {
                if ( Key < pi ) {
                        while ( Low < High ) {
                                R = ( Low + High ) / 2;
                                Key = TotalAngle ();
                                if ( fabs ( Key - Angle [N - 1] * 2 ) <= zero ) break;
                                if ( Key > Angle [N - 1] * 2 + zero ) High = R - zero;
                                        else Low = R + zero;
                        }

                        for ( i = 0; i + 1 < N; i ++ ) Ret += Area ( i );
                        Ret -= Area ( N - 1 );
                        return  Ret;
                } else {
                        while ( Low < High ) {
                                R = ( Low + High ) / 2;
                                Key = TotalAngle ();
                                if ( fabs ( Key - pi ) <= zero ) break;
                                if ( Key + zero < pi ) High = R - zero;
                                        else Low = R + zero;
                        }
                }
        }

        for ( i = 0; i < N; i ++ ) Ret += Area ( i );
        return  Ret;
}

main ()
{
        while ( scanf ( "%d" , &N ) != EOF ) {
                for ( int i = 0; i < N; i ++ ) scanf ( "%d" , &Long [i] );
                sort ( Long , Long + N );
                printf ( "%.2lf\n" , MaxArea () );
        }
}
 