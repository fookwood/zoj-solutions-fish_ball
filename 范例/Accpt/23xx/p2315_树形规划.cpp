#include <stdio.h>
#include <string.h>

#define  MAXN     500001

bool     Get [MAXN];
int      N , LeftChild [MAXN] , RightBrother [MAXN] , Give [MAXN] , Opt [2] [MAXN];

void     init ();
void     Cal ( int );
void     DTime_ ( int , int );
void     Print ();

main ()
{
     int total;
     for ( scanf ( "%d" , &total ); total; total -- ) {
         init ();
         Cal ( 1 );
         DTime_ ( 1 , 0 );
         Print ();
         if ( total > 1 ) puts ( "" );
     }
}

void Print ()
{
     bool  first = true;
     printf ( "%d000\n" , Opt [0] [1] );
     for ( int i = 1; i <= N; i ++ ) if ( Get [i] ) {
         if ( first ) first = false; else printf ( " " );
         printf ( "%d" , i );
     }
     printf ( "\n" );
}

void DTime_ ( int k , int state )
{
     if ( state ) Get [k] = true;
     for ( int i = LeftChild [k]; i; i = RightBrother [i] )
         DTime_ ( i , i == Give [k] );
}

void Cal ( int k )
{
     int Sum = 0 , Max = 0 , Choose = 0;
     for ( int i = LeftChild [k]; i; i = RightBrother [i] ) {
         Cal ( i );
         Sum += Opt [0] [i];
         if ( Opt [1] [i] - Opt [0] [i] > Max ) Max = Opt [1] [i] - Opt [0] [i] , Choose = i;
     }
     Opt [1] [k] = Sum + 1;
     Opt [0] [k] = Sum + Max;
     Give [k] = Choose;
}

void init ()
{
     scanf ( "%d" , &N );
     int Boss;
     
     memset ( Get , 0 , sizeof ( Get ));
     memset ( LeftChild , 0 , sizeof ( LeftChild ));
     memset ( RightBrother , 0 , sizeof ( RightBrother ));
     memset ( Opt , 0 , sizeof ( Opt ));
     
     for ( int i = 2; i <= N; i ++ ) {
         scanf ( "%d" , &Boss );
         RightBrother [i] = LeftChild [Boss] , LeftChild [Boss] = i;
     }
}
