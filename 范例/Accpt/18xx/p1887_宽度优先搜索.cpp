#include <stdio.h>
#include <string.h>

#define MAXN      20
#define eps       1e-8

int     N , Line [1 << MAXN];
bool    Balance [1 << MAXN];
char    ReachEmpty [1 << MAXN];
double  Board , WBoard , Weight [MAXN] , Pos [MAXN];

bool    init ();
void    prepare ();
void    print ();
void    BFS ();


main ()
{
     int      p = 0;
     while ( init () ) {
           printf ( "Case %d:\n" , ++ p );
           prepare ();
           BFS ();
           print ();
     }
}

void print ()
{
     if ( ReachEmpty [ ( 1 << N ) - 1 ] <= 1 ) {
          printf ( "Impossible\n" );
          return;
     }
     int  s , i;
     for ( s = ( 1 << N ) - 1; s; s ^= ( 1 << i )) {
         for ( i = 0; i < N; i ++ ) if ( ( s & ( 1 << i ) ) && ReachEmpty [s ^ ( 1 << i )] == 2 ) break;
         printf ( "%.lf %.lf\n" , Pos [i] + eps , Weight [i] + eps );
     }
}

void BFS ()
{
     int open , closed , t;
     Line [0] = 0;
     for ( open = 0 , closed = 1; open < closed; open ++ ) {
         for ( int i = 0; i < N; i ++ ) if ( ( Line [open] & ( 1 << i ) ) == 0 ) {
             t = Line [open] | ( 1 << i );
             if ( Balance [t] && !ReachEmpty [t] ) Line [closed ++] = t , ReachEmpty [t] = 2;
         }
     }
}

void prepare ()
{
     double sum1 , sum2;
     for ( int i = ( 1 << N ) - 1; i >= 0; i -- ) {
         sum1 = - WBoard * 1.5 , sum2 = WBoard * 1.5;
         for ( int j = 0; j < N; j ++ ) if ( i & ( 1 << j )) 
             sum1 += Weight [j] * ( Pos [j] - 1.5 ) , sum2 += Weight [j] * ( Pos [j] + 1.5 );
         Balance [i] = sum1 < eps && sum2 > - eps;
     }
     memset ( ReachEmpty , 0 , sizeof ( ReachEmpty ));
     ReachEmpty [0] = 2;
}

bool init ()
{
     scanf ( "%lf%lf%d", &Board , &WBoard , &N );
     if ( N == 0 ) return false;
     for ( int i = 0; i < N; i ++ ) scanf ( "%lf%lf" , Pos + i , Weight + i );
     return true;
}

// 4465446 	2006/04/01 05:31:38.619	Accepted	0:09.389	6540	35374	C++	10123 - No Tipping
