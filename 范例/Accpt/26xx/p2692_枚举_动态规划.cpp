#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 120
#define s    6

using namespace std;

int  N , Min , Dice [s] , f [MAXN] [s] , Ans [s];
char Data [MAXN];
bool Appear [10];

void solve ();
void check ();

main ()
{
     int p = 0;
     while ( gets ( Data ) ) { N = strlen ( Data );
           printf ( "Dice %d: " , ++ p );
           solve ();
     }
}

void solve ()
{
     N = strlen ( Data );
     memset ( Appear , 0 , sizeof ( Appear )); Appear [0] = true;
     for ( int i = 0; i < N; i ++ ) Data [i] -= '0' , Appear [Data [i]] = true;
     
     Min = 0x7fffffff;
     memset ( Dice , 0 , sizeof ( Dice ));
     check ();
     for ( Dice [0] = 0; Dice [0] < 10; Dice [0] ++ ) if ( Appear [Dice [0]] )
         for ( Dice [1] = 0; Dice [1] < 10; Dice [1] ++ ) if ( Appear [Dice [1]] )
             for ( Dice [2] = 0; Dice [2] < 10; Dice [2] ++ ) if ( Appear [Dice [2]] )
                 for ( Dice [3] = 0; Dice [3] < 10; Dice [3] ++ ) if ( Appear [Dice [3]] )
                     for ( Dice [4] = 0; Dice [4] < 10; Dice [4] ++ ) if ( Appear [Dice [4]] )
                         for ( Dice [5] = 0; Dice [5] < 10; Dice [5] ++ ) if ( Appear [Dice [5]] )
                             check ();

     printf ( "discrepancy is %d, digits used:" , Min );
     for ( int i = 0; i < s; i ++ ) printf ( " %d" , Ans [i] );
     printf ( "\n" );
}

void check ()
{
     for ( int i = 0; i < s; i ++ ) f [0] [i] = 0;
     int Min1 , d , t;
     for ( int i = 1; i <= N; i ++ ) {
         Min1 = 0x7fffffff;
         for ( int j = 0; j < s; j ++ ) {
             f [i] [j] = f [i - 1] [j] + 1;
             
             d = ( j + 3 ) % s;
             for ( int k = 0; k < 6; k ++ ) if ( k != j && k != d ) {
                 t = f [i - 1] [k] + ( Dice [j] != Data [i - 1] );
                 if ( t < f [i] [j] ) f [i] [j] = t;
             }
             t = f [i - 1] [d] + ( Dice [j] != Data [i - 1] ) + 1;
             if ( t < f [i] [j] ) f [i] [j] = t;
             
             
             if ( f [i] [j] < Min1 ) Min1 = f [i] [j];
         }
         if ( Min1 > Min ) return;
     }
     int Tmp [s];
     memcpy ( Tmp , Dice , sizeof ( Dice ));
     sort ( Tmp , Tmp + s );
     if ( Min == Min1 ) {
          for ( d = 0; d < s && Tmp [d] == Ans [d]; d ++ );
          if ( Tmp [d] >= Ans [d] ) return;
     }
     Min = Min1;
     memcpy ( Ans , Tmp , sizeof ( Tmp ));
}
