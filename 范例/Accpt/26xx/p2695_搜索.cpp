#include <stdio.h>
#include <string.h>
#define MAXN       32
using namespace std;

int   N , Num [MAXN] , Min;

struct TState {
       int  cnt_inc , cnt_dec , Last_inc [MAXN / 2] , Last_dec [MAXN / 2];
};

bool  init ();
int   solve ();
void  Search ( int );

TState       S;

main ()
{
     while ( scanf ( "%d" , &N ) > 0 && N > 0 ) {
           init ();
           printf ( "%d\n" , solve () );
     }
}

void Search ( int depth )
{
     if ( S.cnt_inc + S.cnt_dec >= Min ) return;
     if ( depth == N ) {
          Min = S.cnt_inc + S.cnt_dec;
          return;
     }
     
     int    i;
     for ( i = 0; i < S.cnt_inc; i ++ ) if ( S.Last_inc [i] <= Num [depth] ) break;
     if ( i == S.cnt_inc ) {
          S.Last_inc [S.cnt_inc ++] = Num [depth];
          Search ( depth + 1 );
          S.cnt_inc --;
     } else {
          int p = S.Last_inc [i];
          S.Last_inc [i] = Num [depth];
          Search ( depth + 1 );
          S.Last_inc [i]= p;
     }
     
     for ( i = 0; i < S.cnt_dec; i ++ ) if ( S.Last_dec [i] >= Num [depth] ) break;
     if ( i == S.cnt_dec ) {
          S.Last_dec [S.cnt_dec ++] = Num [depth];
          Search ( depth + 1 );
          S.cnt_dec --;
     } else {
          int p = S.Last_dec [i];
          S.Last_dec [i] = Num [depth];
          Search ( depth + 1 );
          S.Last_dec [i] = p;
     }
}

int solve ()
{
     if ( N == 1 ) return 0;
     if ( N == 2 ) return 1;
     if ( N == 3 ) {
          if ( Num [0] <= Num [1] && Num [1] <= Num [2] ) return 1;
          if ( Num [0] >= Num [1] && Num [1] >= Num [2] ) return 1;
          return 0;
     }
     
     Min = ( N + 1 ) / 2;
     S.cnt_inc = S.cnt_dec = 0;
     Search ( 0 );
     return Min;
}

bool init ()
{
     for ( int i = 0; i < N; i ++ ) scanf ( "%d" , &Num [i] );
}
