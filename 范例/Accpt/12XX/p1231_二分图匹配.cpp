#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

#define MAXN 120
#define eps  1e-8
#define sqr(a) ((a)*(a))

using namespace std;

int     N , Link [MAXN] , mk [MAXN] , P;
int     x [MAXN] , y [MAXN] , c [MAXN] , w [MAXN] , s [MAXN];
double  All [MAXN * MAXN];
double  dis [MAXN] [MAXN] , L;



bool    init ();
void    solve ();
void    BuildGraph ();
bool    check ( double );
bool    find ( int );

main ()
{
     while ( init ()) {
           BuildGraph ();
           solve ();
     }
}

bool find ( int k )
{
     int t;
     for ( int i = 1; i <= N; i ++ ) if ( !mk [i] && dis [k] [i] <= L + eps ) {
         t = Link [i] , Link [i] = k , mk [i] = true;
         if ( t == -1 || find ( t ) ) return true;
         Link [i] = t;
     }
     return false;
}

bool check ( double Limit )
{
     L = Limit;
     memset ( Link , 0xff , sizeof ( Link ));
     for ( int i = 1; i <= N; i ++ ) {
         memset ( mk , 0 , sizeof ( mk ));
         if ( !find ( i )) return false;
     }
     return true;
}

void BuildGraph ()
{
     int l [MAXN] , r [MAXN];
     for ( int i = 1; i <= N; i ++ ) {
         l [i] = 1000 , r [i] = 0;
         for ( int k = 0; k <= 1000; k ++ ) {
             if ( y [i - 1] <= y [i] && ( x [i] - x [i - 1] ) * ( 0 - y [i - 1] ) - ( y [i] - y [i - 1] ) * ( k - x [i - 1] ) > 0 ) continue;
             if ( y [i + 1] <= y [i] && ( k - x [i + 1] ) * ( y [i] - y [i + 1] ) - ( 0 - y [i + 1] ) * ( x [i] - x [i + 1] ) > 0 ) continue;
             if ( k < l [i] ) l [i] = k;
             if ( k > r [i] ) r [i] = k;
         }
     }
     
     double     t;
     P = 0;
     for ( int i = 1; i <= N; i ++ ) for ( ; x [i] < 0 || x [i] > 1000; );
     for ( int i = 1; i <= N; i ++ )
         for ( int j = 1; j <= N; j ++ ) {
             dis [i] [j] = 1e20;
             for ( int k = l [j]; k <= r [j]; k ++ ) {
                 t = fabs ( (double) s [i] - k ) / w [i] + sqrt ( (double) sqr ( y [j] ) + sqr ( x [j] - k ) ) / c [i];
                 if ( t < dis [i] [j] ) dis [i] [j] = t;
             }
             All [P ++] = dis [i] [j];
         }
     sort ( All , All + P );
}

void solve ()
{
     int   low , high , mid;
     for ( low = -1 , high = P - 1; low + 1 < high; ) {
         mid = ( low + high ) / 2;
         if ( check ( All [mid] )) high = mid;
         else low = mid;
     }
     printf ( "%.2lf\n" , All [high] );
}

bool init ()
{
     scanf ( "%d" , &N );
     if ( N == 0 ) return false;
     for ( int i = 0; i <= N + 1; i ++ ) scanf ( "%d%d" , x + i , y + i );
     for ( int i = 1; i <= N; i ++ ) scanf ( "%d%d%d" , c + i , w + i , s + i );
     return true;
}

// 4465176 	2006/04/01 03:16:42.731	Wrong Answer	0:18.215	520	35374	C++	10122 - Mysterious Mountain
// 4465258 	2006/04/01 04:09:48.945	Accepted	0:13.818	648	35374	C++	10122 - Mysterious Mountain
