#include <stdio.h>
#include <algorithm>

#define MAXN      120

using namespace std;

char     map [MAXN] [MAXN];
int      graph [MAXN] [MAXN] , dx [MAXN] , dy [MAXN] , Link [MAXN];
int      L , N , M;
bool     mkx [MAXN] , mky [MAXN];

bool     init ();
int      MaxMatch ();
bool     find ( int );

main ()
{
     while ( init () ) {
           printf ( "%d\n" , MAXN * L - MaxMatch () );
     }
}

bool find ( int k )
{
     mkx [k] = true;
     int t;
     for ( int i = 0; i < L; i ++ ) if ( !mky [i] && dx [k] + dy [i] == graph [k] [i] ) {
         mky [i] = true;
         t = Link [i];
         Link [i] = k;
         if ( t == -1 || find ( t )) return true;
         Link [i] = t;
     }
     return false;
}

int  MaxMatch ()
{
     memset ( dy , 0 , sizeof ( dy ));
     memset ( Link , 0xff , sizeof ( Link ));
     for ( int i = 0; i < L; i ++ )
         for ( int j = dx [i] = 0; j < L; j ++ ) if ( graph [i] [j] > dx [i] )
             dx [i] = graph [i] [j];
     for ( int k = 0; k < L; k ++ )
         for ( ;; ) {
             memset ( mkx , 0 , sizeof ( mkx ));
             memset ( mky , 0 , sizeof ( mky ));
             if ( find ( k ) ) break;
             int delta = 0x7fffffff;
             for ( int i = 0; i < L; i ++ ) if ( mkx [i] )
                 for ( int j = 0; j < L; j ++ ) if ( !mky [j] )
                     if ( dx [i] + dy [j] - graph [i] [j] < delta )
                        delta = dx [i] + dy [j] - graph [i] [j];
             for ( int i = 0; i < L; i ++ ) {
                 if ( mkx [i] ) dx [i] -= delta;
                 if ( mky [i] ) dy [i] += delta;
             }
         }
     int Ret = 0;
     for ( int i = 0; i < L; i ++ ) Ret += graph [Link [i]] [i];
     return Ret;
}

bool init ()
{
     int  mx [MAXN] , my [MAXN] , Hx [MAXN] , Hy [MAXN] , m = 0 , H = 0;
     
     scanf ( "%d%d\n" , &N , &M );
     if ( N == 0 && M == 0 ) return false;
     for ( int i = 0; i < N; i ++ ) gets ( map [i] );
     
     for ( int i = 0; i < N; i ++ ) 
         for ( int j = 0; j < M; j ++ ) {
             if ( map [i] [j] == 'H' ) Hx [H] = i , Hy [H ++] = j;
             if ( map [i] [j] == 'm' ) mx [m] = i , my [m ++] = j;
         }
     L = H;
     for ( int i = 0; i < L; i ++ )
         for ( int j = 0; j < L; j ++ )
             graph [i] [j] = MAXN - abs ( Hx [i] - mx [j] ) - abs ( Hy [i] - my [j] );
     return true;
}
// zoj 2404 Going Home
