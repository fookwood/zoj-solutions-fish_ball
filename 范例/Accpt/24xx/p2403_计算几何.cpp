#include <stdio.h>
#include <math.h>
#include <complex>
#include <algorithm>

using namespace std;

typedef complex <double> TPos;

int     N;
TPos    Data [20] [20];
double  Start [20];

bool    init ();
void    solve ();

main ()
{
     while ( init () )
           solve ();
}

void solve ()
{
     TPos  Tmp;
     double    l;
     for ( int i = 0; N - i > 1; i ++ )
         for ( int j = 0; j + 1 < N - i; j ++ ) {
             Tmp = Data [i] [j + 1] - Data [i] [j];
             l = sqrt ( norm ( Tmp ) ) / 4;
             Tmp *= TPos ( l , sqrt ( 1 - l * l ) );
             Tmp /= l * 2;
             Data [i + 1] [j] = Data [i] [j] + Tmp;
         }
     printf ( "%.4lf %.4lf\n" , Data [N - 1] [0].real () , Data [N - 1] [0].imag () );
}

bool init ()
{
     scanf ( "%d" , &N );
     double  x , y;
     if ( N == 0 ) return false;
     for ( int i = 0; i < N; i ++ )
         scanf ( "%lf" , &Start [i] );
     sort ( Start , Start + N );
     for ( int i = 0; i < N; i ++ )
         Data [0] [i] = TPos ( Start [i] , 1.0 );
     return true;
}
