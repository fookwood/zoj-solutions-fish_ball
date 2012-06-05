//#include <iostream>
#include <stdio.h>
#include <algorithm>

#define MAXN 50010
#define MAXM 100010

using namespace std;

struct TLine {
       int a , b , ID;
       long long cost;
       bool operator < ( const TLine & B ) const {
            return cost > B.cost;
       }
};

int   N , M , Father [MAXN] , Ans [MAXM];
long long S;
TLine  Lines [MAXM];
bool   mk [MAXM];

int find ( int );
bool init ();
void solve ();

main ()
{
     bool  first = true;
     while ( init () ) {
           if ( first ) first = false; else printf ( "\n" );
           solve ();
     }
}

void solve ()
{
     int   fa , fb , t = 0;
     
     for ( int i = 1; i <= N; i ++ ) Father [i] = i;
     for ( int i = 0; i < M; i ++ ) {
         fa = find ( Lines [i].a );
         fb = find ( Lines [i].b );
         if ( mk [i] = ( fa == fb ) , mk [i] ) continue;
         Father [fa] = fb;
     }
     long long s = 0;
     for ( int i = M - 1; i >= 0; i -- ) if ( mk [i] ) {
         s += Lines [i].cost;
         if ( s > S ) break;
         Ans [t ++] = Lines [i].ID;
     }
     printf ( "%d\n" , t );
     sort ( Ans , Ans + t );
     for ( int i = 0; i < t; i ++ ) {
         if ( i ) printf ( " " );
         printf ( "%d" , Ans [i] );
     }
     printf ( "\n" );
}

bool init ()
{
     if ( scanf ( "%d%d%lld" , &N , &M , &S ) == EOF ) return false;
     for ( int i = 0; i < M; i ++ ) 
         scanf ( "%d%d%lld" , &Lines [i].a , &Lines [i].b , &Lines [i].cost ) , Lines [i].ID = i + 1;
     sort ( Lines , Lines + M );
     return true;
}

int find ( int k )
{
    if ( Father [k] != k ) Father [k] = find ( Father [k] );
    return Father [k];
}

