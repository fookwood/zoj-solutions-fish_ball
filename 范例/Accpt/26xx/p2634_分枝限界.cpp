#include <stdio.h>
#include <string.h>

#define N          8

const   int dx [8] = { -1 , 0 , 1 , -1 , 1 , -1 , 0 , 1 };
const   int dy [8] = { -1 , -1 , -1 , 0 , 0 , 1 , 1 , 1 };

int     map [N] [N] , Min [N] [N] , Max [N] [N] , Goal;
bool    mark [N] [N];

bool    range ( int , int );
void    solve ();
bool    Search ( int , int , int );
void    init ();

main ()
{
     int     total;
     for ( scanf ( "%d" , &total ); total; total -- ) {
         init ();
         solve ();
     }
}

void init ()
{
     scanf ( "%d" , &Goal );
     for ( int i = 0; i < N; i ++ )
         for ( int j = 0; j < N; j ++ )
             scanf ( "%d" , &map [i] [j] );
}

void solve ()
{
     int   i , j , k , x , y , tx , S;
     for ( i = 0; i < N; i ++ ) for ( j = 0; j < N; j ++ ) Min [i] [j] = 0x7fffffff , Max [i] [j] = -1;
     
     Min [7] [7] = Max [7] [7] = 0;
     for ( i = 6; i >= 0; i -- ) Min [i] [7] = Max [i] [7] = Min [i + 1] [7] + map [i + 1] [7];
     
     for ( j = 7; j; j -- ) {
         for ( i = 0; i < N; i ++ ) {
             for ( k = 0; k < 3; k ++ ) {
                 x = i + dx [k] , y = j + dy [k];
                 if ( !range ( x , y ) || Min [i] [j] + map [i] [j] >= Min [x] [y] ) continue;
                 Min [x] [y] = Min [i] [j] + map [i] [j];
                 for ( tx = x + 1; range ( tx , y ) && Min [tx - 1] [y] + map [tx - 1] [y] < Min [tx] [y]; tx ++ )
                     Min [tx] [y] = Min [tx - 1] [y] + map [tx - 1] [y];
                 for ( tx = x - 1; range ( tx , y ) && Min [tx + 1] [y] + map [tx + 1] [y] < Min [tx] [y]; tx -- )
                     Min [tx] [y] = Min [tx + 1] [y] + map [tx + 1] [y];
             }
         }
     }
     
     
     for ( j = 7; j; j -- ) {
         for ( i = 0; i < N; i ++ ) {
             for ( k = 0; k < 3; k ++ ) {
                 x = i + dx [k] , y = j + dy [k];
                 if ( !range ( x , y ) ) continue;
                 if ( Max [i] [j] + map [i] [j] > Max [x] [y] )
                    Max [x] [y] = Max [i] [j] + map [i] [j];
                    
                 S = Max [i] [j] + map [i] [j] + map [x] [y];
                 for ( tx = x + 1; range ( tx , y ); S += map [tx] [y] , tx ++ )
                     if ( S > Max [tx] [y] ) Max [tx] [y] = S;
                 S = Max [i] [j] + map [i] [j] + map [x] [y];
                 for ( tx = x - 1; range ( tx , y ); S += map [tx] [y] , tx -- )
                     if ( S > Max [tx] [y] ) Max [tx] [y] = S;
             }
         }
     }     
   
     memset ( mark , 0 , sizeof ( mark )); mark [0] [0] = true;
     if ( Search ( 0 , 0 , map [0] [0] )) printf ( "Yes\n" );
     else printf ( "No\n" );
}

bool Search ( int x , int y , int cost )
{
     if ( y == 7 ) {
          for ( x ++; x < N; x ++ ) cost += map [x] [y];
          return cost == Goal;
     }
     int  i , nx , ny , ncost;
     for ( i = 3; i < N; i ++ ) {
         nx = x + dx [i] , ny = y + dy [i];
         if ( !range ( nx , ny ) || mark [nx] [ny] ) continue;
         ncost = cost + map [nx] [ny];
         if ( ncost + Min [nx] [ny] > Goal || ncost + Max [nx] [ny] < Goal ) continue;
         mark [nx] [ny] = true;
         if ( Search ( nx , ny , cost + map [nx] [ny] )) return true;
         mark [nx] [ny] = false;
     }
     return false;
}

bool range ( int x , int y )
{
     return x >= 0 && x < N && y >= 0 && y < N;
}
