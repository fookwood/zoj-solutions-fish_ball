#include <stdio.h>
#include <algorithm>
#include <functional>
#define  MAX        110

using namespace std;

int   T , N , M , R , map [MAX] [MAX] , opt [MAX] [MAX] [MAX] , list [MAX] , listsize;

bool  init ();
bool  range ( int , int );
void  Dynamic ();

main ()
{
     while ( init () )
           Dynamic ();
}

bool range ( int x , int y )
{
     return x >= 0 && x < N && y >= 0 && y < M;
}

void Dynamic ()
{
     if ( map [0] [0] ) {
          printf ( "0\n" );
          return;
     }
     
     int     i , j , k , sum , p;
     memset ( opt , 0xff , sizeof ( opt ));
     listsize = 0;
     opt [0] [0] [0] = 0;
     for ( i = 0; i <= R; i ++ )
         for ( j = 0; j <= R; j ++ ) if ( range ( i , j ) && map [i] [j] ) list [listsize ++] = map [i] [j];
         
     sort ( list , list + listsize , greater <int> () );
     for ( i = sum = 0; i < T && i < listsize; i ++ ) {
         sum += list [i];
         if ( opt [i + 1] [0] [0] == -1 || sum > opt [i + 1] [0] [0] )
            opt [i + 1] [0] [0] = sum;
     }
     
     
     for ( k = 0; k < T; k ++ )
         for ( i = 0; i < N; i ++ )
             for ( j = 0; j < M; j ++ ) if ( opt [k] [i] [j] != -1 ) {
                 if ( opt [k + 1] [i] [j] == -1 || opt [k] [i] [j] > opt [k + 1] [i] [j] )
                    opt [k + 1] [i] [j] = opt [k] [i] [j];
                    
                 if ( range ( i + 1 , j ) && map [i + 1] [j] == 0 )
                    if ( opt [k + 1] [i + 1] [j] == -1 || opt [k] [i] [j] > opt [k + 1] [i + 1] [j] )
                       opt [k + 1] [i + 1] [j] = opt [k] [i] [j];
                 if ( range ( i , j + 1 ) && map [i] [j + 1] == 0 )
                    if ( opt [k + 1] [i] [j + 1] == -1 || opt [k] [i] [j] > opt [k + 1] [i] [j + 1] )
                       opt [k + 1] [i] [j + 1] = opt [k] [i] [j];
                       
                 if ( i + R + 1 < N && map [i + 1] [j] == 0 ) {
                      listsize = 0;
                      for ( p = j - R; p <= j + R; p ++ ) if ( range ( i + R + 1 , p ) && map [i + R + 1] [p] )
                          list [listsize ++] = map [i + R + 1] [p];
                      sort ( list , list + listsize , greater<int> () );
                      for ( p = sum = 0; p < listsize; p ++ ) {
                          if ( k + p + 2 > T ) break;
                          sum += list [p];
                          if ( opt [k + p + 2] [i + 1] [j] == -1 || opt [k] [i] [j] + sum > opt [k + p + 2] [i + 1] [j] )
                             opt [k + p + 2] [i + 1] [j] = opt [k] [i] [j] + sum;
                      }
                 }
                 if ( j + R + 1 < M && map [i] [j + 1] == 0 ) {
                      listsize = 0;
                      for ( p = i - R; p <= i + R; p ++ )if ( range ( p , j + R + 1 ) && map [p] [j + R + 1] )
                          list [listsize ++] = map [p] [j + R + 1];
                      sort ( list , list + listsize , greater<int> () );
                      for ( p = sum = 0; p < listsize; p ++ ) {
                          if ( k + p + 2 > T ) break;
                          sum += list [p];
                          if ( opt [k + p + 2] [i] [j + 1] == -1 || opt [k] [i] [j] + sum > opt [k + p + 2] [i] [j + 1] )
                             opt [k + p + 2] [i] [j + 1] = opt [k] [i] [j] + sum;
                      }
                 }
             }
         
     for ( sum = i = 0; i < N; i ++ )
         for ( j = 0; j < M; j ++ ) if ( opt [T] [i] [j] > sum ) sum = opt [T] [i] [j];
     printf ( "%d\n" , sum );
}

bool  init ()
{
      if ( scanf ( "%d" , &T ) == EOF ) return false;
      scanf ( "%d%d" , &N , &M );
      for ( int i = N - 1; i >= 0; i -- )
          for ( int j = 0; j < M; j ++ ) scanf ( "%d", &map [i] [j] );
      scanf ( "%d" , &R );
      return true;
}

