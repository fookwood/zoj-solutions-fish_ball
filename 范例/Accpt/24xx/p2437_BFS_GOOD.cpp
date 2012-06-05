#include <stdio.h>
#include <string.h>

#define  MAXN     210

const    int dx [4] = { 0 , 0 , -1 , 1 };
const    int dy [4] = { -1 , 1 , 0 , 0 };

int      N , Len;

bool     range ( int x , int y ) { return x >= 0 && x < N && y >= 0 && y < N; }

int      Min [MAXN] [MAXN] , Choose [MAXN] [MAXN];
int      Map [MAXN] [MAXN];

struct   TLine {
         int x , y , col;
}        Line [MAXN * MAXN];

void     init ()
{
         int  i , j;
         scanf ( "%d" , &N );
         for ( i = 0; i < N; i ++ ) 
             for ( j = 0; j < N; j ++ )
                 scanf ( "%d" , &Map [i] [j] );

         memset ( Choose , 0xff , sizeof ( Choose ));        
         for ( Len = i = 0; i < N; i ++ )
             for ( j = 0; j < N; j ++ )
                 if ( Map [i] [j] == 0 ) Min [i] [j] = 0x7fffffff;
                 else Min [i] [j] = 0 , Line [Len].x = i , Line [Len].y = j , Line [Len].col = Len , Len ++;
}

void     BFS ()
{
         int   open = 0 , closed = Len , x , y , i , t , j;
         
         for ( ; open < closed; open ++ ) {
             t = Min [Line [open].x] [Line [open].y] + 1;
             j = Line [open].col;
             
             for ( i = 0; i < 4; i ++ ) {
                 x = Line [open].x + dx [i] , y = Line [open].y + dy [i];
                 if ( !range ( x , y ) || t > Min [x] [y] ) continue;
                 if ( t < Min [x] [y] )
                    Line [closed].x = x , Line [closed].y = y , Line [closed ++].col = Line [open].col;
                 Min [x] [y] = t;
                 
                 
                 if ( Choose [x] [y] == -1 || Choose [x] [y] == j ) Choose [x] [y] = j;
                    else Choose [x] [y] = -2;
                 
                 if ( Choose [Line [open].x] [Line [open].y] == -2 ) Choose [x] [y] = -2;
                 Map [x] [y] = Map [Line [j].x] [Line [j].y];
             }             
         }
         
         for ( i = 0; i < N; i ++ ) {
             for ( j = 0; j < N; j ++ ) {
                 if ( j ) printf ( " " );
                 if ( Choose [i] [j] == -2 ) printf ( "0" );
                    else printf ( "%d" , Map [i] [j] );
             }
             printf ( "\n" );
         }
}


main ()
{
     int Part , P;
     for ( scanf ( "%d" , &Part ) , P = 0; P < Part; P ++ ) {
         if ( P ) printf ( "\n" );
         init ();
         BFS ();
     }
}
