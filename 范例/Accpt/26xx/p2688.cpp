#include <stdio.h>
#include <algorithm>
#define MAXN  100010

using namespace std;

int N;
struct TSchool {
       double s [5];
       void init () { for ( int i = 0;i < 5; i ++ ) scanf ( "%lf" , &s [i] ); }
};

int    Pow [5];
double  Sum [MAXN];
bool    init ();

TSchool School [MAXN];
void    solve ();

main ()
{
     while ( init () ) {
           solve ();
     }
}

void solve ()
{
     if ( N == 1 ) {
          printf ( "0.00\n" );
          return;
     }
     double  Ans = 0 , Min , Max;
     for ( int i = 0; i < 5; i ++ ) Pow [i] = 1 << i;
     
     for ( int i = 0; i < ( 1 << 5 ); i ++ ) {
         
         fill_n ( Sum , N , 0 );
         for ( int j = 0; j < N; j ++ ) 
             for ( int k = 0; k < 5; k ++ )
                 Sum [j] += ( i & Pow [k] ) ? School [j].s [k] : - School [j].s [k];
         
         Min = 1e20 , Max = -1e20;
         for ( int j = 0; j < N; j ++ ) {
             if ( Sum [j] > Max ) Max = Sum [j];
             if ( Sum [j] < Min ) Min = Sum [j];
         }
         if ( Max - Min > Ans ) Ans = Max - Min;
     }
     printf ( "%.2lf\n" , Ans + 1e-8 );
}

bool init ()
{
     scanf ( "%d" , &N );
     if( N == 0 ) return false;
     for ( int i = 0; i < N; i ++ ) School [i].init ();
     return true;
}
