#include <stdio.h>
#include <string.h>

#define MAXN      13
#define Front     0
#define Left      1
#define Back      2
#define Right     3
#define Top       4
#define Bottom    5

const int dx [6] = { 0 , 0 , 0 , 0 , 1 , -1 };
const int dy [6] = { 0 , 1 , 0 , -1 , 0 , 0 };
const int dz [6] = { 1 , 0 , -1 , 0 , 0 , 0 };

int   N;
bool  Have [MAXN] [MAXN] [MAXN];
char  map [6] [MAXN] [MAXN];

bool  range ( int , int , int );
bool  init ();
void  solve ();
bool  check ( int & , int & , int & );

main ()
{
     while ( init () ) {
           solve ();
     }
}

bool check ( int &rx , int &ry , int &rz )
{
     char  col [MAXN] [MAXN] [MAXN];
     int   x , y , z , sx , sy ,sz;
     memset ( col , 0 , sizeof ( col ));
     
     for ( int f = 0; f < 6; f ++ )
         for ( int i = 0; i < N; i ++ )
             for ( int j = 0; j < N; j ++ ) {
                 switch ( f ) {
                        case Front   : x = i , y = j , z = 0; break;
                        case Left    : x = i , y = 0 , z = N - j - 1; break;
                        case Back    : x = i , y = N - j - 1 , z = N - 1; break;
                        case Right   : x = i , y = N - 1 , z = j; break;
                        case Top     : x = 0 , y = j , z = N - i - 1; break;
                        case Bottom  : x = N - 1 , y = j , z = i; break;
                 }
                 
                 for ( ; range ( x , y , z ); x += dx [f] , y += dy [f] , z += dz [f] ) {
                     if ( col [x] [y] [z] && col [x] [y] [z] != map [f] [i] [j] ) { rx = x , ry = y , rz = z; return false; }
                     if ( Have [x] [y] [z] && map [f] [i] [j] == '.' ) { rx = x , ry = y , rz = z; return false; }
                     if ( Have [x] [y] [z] ) { col [x] [y] [z] = map [f] [i] [j]; break; }
                 }
             }
     return true;
}

void solve ()
{
     int   Weight , x , y , z;
     memset ( Have , 1 , sizeof ( Have ));
     for ( Weight = N * N * N; Weight; Weight -- ) {
         if ( check ( x , y , z ) ) break;
         Have [x] [y] [z] = false;
     }
     printf ( "Maximum weight: %d gram(s)\n" , Weight );
}

bool init ()
{
     scanf ( "%d" , &N ); if ( N == 0 ) return false;
     for ( int i = 0; i < N; i ++ )
         for ( int j = 0; j < 6; j ++ )
             scanf ( "%s" , map [j] [i] );
     return true;
}

bool range ( int x , int y , int z )
{
     return x >= 0 && x < N && y >= 0 && y < N && z >= 0 && z < N;
}
