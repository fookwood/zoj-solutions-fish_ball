#include <stdio.h>
#include <string.h>

#define MAXN    410
#define MaxSize 810
#define Inf     0x7fffffff

const int dx [4] = { 0 , -1 , 0 , 1 };
const int dy [4] = { -1 , 0 , 1 , 0 };

struct TState {
       int x , y;
       bool range ();
       bool Final ();
       bool isedge ( int );
};

int    N , M , Min [MAXN] [MAXN];
char   map [MaxSize] [MaxSize];
TState Line [MAXN * MAXN];

void init ();
void BFS ();
void print ();

main ()
{
     int total;
     for ( scanf ( "%d" , &total );total; total -- ) {
         init ();
         BFS ();
         print ();
         if ( total > 1 ) printf ( "\n" );
     }
}

void print ()
{
     int     f;
     TState  State , NewState;
     if ( Min [1] [0] < Min [0] [1] )
          printf ( "N\n" ) , State.x = 1 , State.y = 0 , f = 3;
     else printf ( "E\n" ) , State.x = 0 , State.y = 1 , f = 2;
     for ( ; !State.Final (); State = NewState ) {
         NewState.x = State.x + dx [f] , NewState.y = State.y + dy [f];
         if ( NewState.range () && Min [State.x] [State.y] == Min [NewState.x] [NewState.y] + 1 && State.isedge ( f ) ) {
              printf ( "F" );
              continue;
         }
         
         int  nf;
         for ( nf = 0; nf < 4; nf ++ ) {
             NewState.x = State.x + dx [nf] , NewState.y = State.y + dy [nf];
             if ( NewState.range () && Min [State.x] [State.y] == Min [NewState.x] [NewState.y] + 1 && State.isedge ( nf ) ) break;
         }
         printf ( "%c" , nf == ( f + 1 ) % 4 ? 'L' : 'R' ) , f = nf;
     }
     printf ( "\n" );
}

void init ()
{
     scanf ( "%d%d\n" , &N , &M );
     for ( int i = 2 * N - 2; i >= 0; i -- )
         gets ( map [i] );
}

void BFS ()
{
     for ( int i = 0; i < N; i ++ )
         for ( int j = 0; j < M; j ++ )
             Min [i] [j] = Inf;
     Min [N - 1] [M - 1] = 0;
     
     int open , closed , p , q;
     TState State , NewState;
     Line [0].x = N - 1 , Line [0].y = M - 1;
     for ( open = 0 , closed = 1; open < closed; open ++ ) {
         State = Line [open];
         for ( int i = 0; i < 4; i ++ ) {
             NewState.x = State.x + dx [i] , 
             NewState.y = State.y + dy [i];
             if ( !NewState.range () || Min [NewState.x] [NewState.y] < Inf ) continue;
             if ( !State.isedge ( i ) ) continue;
             Min [NewState.x] [NewState.y] = Min [State.x] [State.y] + 1;
             Line [closed ++] = NewState;
         }
     }
}

bool TState :: range ()
{
     return x >= 0 && x < N && y >= 0 && y < M;
}

bool TState :: Final ()
{
     return x == N - 1 && y == M - 1;
}

bool TState :: isedge ( int f )
{
     char t = map [2 * x + dx [f]] [2 * y + dy [f]];
     return t == '|' || t == '-';
}

// 1700924 2006-03-21 16:32:32 Accepted 2594 C++ 00:00.27 3052K AndyZhau 
