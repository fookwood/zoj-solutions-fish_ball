#include <stdio.h>

#define MAXN      22

int      N , graph [MAXN] [MAXN] , Add [MAXN] , LeaveSum , Max;

void     init ();
void     Search ( int , int );

main ()
{
     int total;
     for ( scanf ( "%d" , &total ); total; total -- ) {
         init ();
         Search ( 0 , 0 );
         printf ( "%d\n" , Max );
         if ( total > 1 ) printf ( "\n" );
     }
}

void Search ( int depth , int cost )
{
     if ( cost > Max ) Max = cost;
     if ( depth == N ) return;
     
     int  i;
     if ( Add [depth] > 0 ) {
          for ( i = depth + 1 , LeaveSum = 0; i < N; i ++ ) { Add [i] -= ( graph [depth] [i] << 1 ); if ( Add [i] > 0 ) LeaveSum += Add [i]; }
          if ( cost + Add [depth] + LeaveSum > Max ) Search ( depth + 1 , cost + Add [depth] );
          for ( i = depth + 1 , LeaveSum = 0; i < N; i ++ ) { Add [i] += ( graph [depth] [i] << 1 ); if ( Add [i] > 0 ) LeaveSum += Add [i]; }
     }
//     printf ( "depth = %d cost = %d Max = %d\n" , depth , cost , Max );
//     for ( int i = 0; i < N; i ++ ) printf ( "%d " , Add [i] ); printf ( "\n" );
     if ( cost + LeaveSum > Max ) Search ( depth + 1 , cost );
}

void init ()
{
     scanf ( "%d" , &N );
     for ( int i = 0; i < N; i ++ )
         for ( int j = Add [i] = 0; j < N; j ++ )
             scanf ( "%d" , &graph [i] [j] ) , Add [i] += graph [i] [j];
     for ( int i = LeaveSum = 0; i < N; i ++ ) LeaveSum += Add [i];
//     for ( int i = 0; i < N; i ++ ) printf ( "%d " , Add [i] ); printf ( "\n" );
     Max = 0;
}
