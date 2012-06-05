#include <stdio.h>
#include <algorithm>

#define MAXN      120
#define MAXM      500
#define eps       1e-4
#define Inf       1e20
using namespace std;

int     N , M;
int     Edge [MAXN] [MAXN] , Len [MAXN] , Pre [MAXN] , X [MAXM] , Y [MAXM];
double  Graph [MAXN] [MAXN] , Cost [MAXN] [MAXN] , Flux [MAXN];
bool    S [MAXN] , Ans [MAXM];

int     Lines;
double  TotalCost;

bool    init ();
void    solve ();
double  FindPath ();
bool    check ( double );
void    BuildGraph ( double );

main ()
{
     int p = 0;
     while ( init () ) {
           if ( p ++ > 0 ) printf ( "\n" );
           solve ();
     }
}

void BuildGraph ( double L )
{
     Lines = 0 , TotalCost = 0;
     memset ( Ans , 0 , sizeof ( Ans ));
     memset ( Cost , 0 , sizeof ( Cost ));
     int    a , b;
     for ( int i = 0; i < M; i ++ ) {
         a = X [i] , b = Y [i];
         if ( Graph [a] [b] >= L + eps ) Cost [a] [b] = Cost [b] [a] = Graph [a] [b] - L;
         else Lines ++ , Ans [i] = true , TotalCost += Graph [a] [b];
     }
}

bool check ( double L )
{
     BuildGraph ( L );
     double  InCome;
     for ( ;; ) {
           if ( InCome = FindPath () , InCome < 0 ) break;
           for ( int i = N; i != 1; i = Pre [i] )
               Cost [Pre [i]] [i] -= InCome ,
               Cost [i] [Pre [i]] += InCome;
     }
     int       a , b;
     for ( int i = 0; i < M; i ++ ) if ( !Ans [i] ) {
         a = X [i] , b = Y [i];
         if ( ! (S [a] ^ S [b] ) ) continue;
         Ans [i] = true;
         Lines ++ , TotalCost += Graph [a] [b];
     }
     return L >= TotalCost / Lines + eps;
}

double FindPath ()
{
       double  Max [MAXN];
       memset ( S , 0 , sizeof ( S ));
       memset ( Max , 0 , sizeof ( Max ));
       Max [1] = Inf;
       
       int i , j , k;
       double t;
       for ( i = 0; i < N; i ++ ) {
           for ( k = -1 , j = 1; j <= N; j ++ ) if ( !S [j] )
               if ( k == -1 || Max [j] > Max [k] ) k = j;
           if ( k == -1 || Max [k] < eps ) return - Inf;
           if ( k == N ) return Max [k];
           S [k] = true;
           for ( j = 1; j <= N; j ++ ) if ( !S [j] && Cost [k] [j] > eps ) {
               t = min ( Max [k] , Cost [k] [j] );
               if ( t > Max [j] ) Max [j] = t , Pre [j] = k;
           }
       }
}

void solve ()
{
     double low = 0 , high = 1 , mid;
     while ( !check ( high ) ) high *= 10;
     while ( low + eps < high ) {
           mid = ( low + high ) / 2;
           if ( check ( mid )) high = mid;
           else low = mid;
     }
     printf ( "%d\n" , Lines );
     bool   first = true;
     for ( int i = 0; i < M; i++ ) if ( Ans [i] ) {
         if ( first ) first = false; else printf ( " " );
         printf ( "%d" , i + 1 );
     }
     printf ( "\n" );
}

bool init ()
{
     if ( scanf ( "%d%d" , &N , &M ) == EOF ) return false;
     int  a , b;
     double c;
     memset ( Len , 0 , sizeof ( Len ));
     for ( int i = 0; i < M; i ++ )
         scanf ( "%d%d%lf" , &a , &b , &c ) , 
         Edge [a] [Len [a] ++] = b ,
         Edge [b] [Len [b] ++] = a ,
         Graph [a] [b] = Graph [b] [a] = c ,
         X [i] = a , Y [i] = b;
     return true;
}
