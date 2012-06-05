#include <stdio.h>
#include <string.h>

#define vacant  0
#define stock   1
#define snake   2

const   int     face [8] = { 0x00000003 , 0x0000000C , 0x00000030 , 0x000000C0 ,
                             0x00000300 , 0x00000C00 , 0x00003000 , 0x0000C000 };

int     Min;

int     StartLen , Len;
int     Hash [20] [20] [1 << 14];

int     N , M , L;
int     map [20] [20];

const   int     Limit   = 10000;
const   int     dx [4] = { 0 , 1 , 0 , -1 };
const   int     dy [4] = { 1 , 0 , -1 , 0 };
const   int     f_1 [4] = { 2 , 3 , 0 , 1 };

int     Open , Closed;
struct  TNode   {
        int     x , y;
        int     State;
}       Line [Limit];

int     OpenSub , ClosedSub;
int     LineSub [400] [2];
bool    reach [20] [20];

int     Num ( int pdx , int pdy )
{
        for ( int i = 0; i < 4; i ++ ) if ( pdx == dx [i] && pdy == dy [i] ) return i;
        return -1;
}

void    print ()
{
        int     i , j;
        for ( i = 0; i < N; i ++ ) {
                for ( j = 0; j < M; j ++ ) printf ( "%d" , map [i] [j] );
                printf ( "\n" );
        }
        printf ( "\n" );
}


bool    init ()
{
        scanf ( "%d%d%d" , &N , &M , &L ); if ( N == 0 ) return false;
        
        int     i , ax , ay , bx , by , k;
        scanf ( "%d%d" , &ax , &ay ); Line [0].x = ax - 1; Line [0].y = ay - 1;
        for ( i = k = 0; i + 1 < L; i ++ , ax = bx , ay = by ) {
                scanf ( "%d%d" , &bx , &by );
                k |= Num ( bx - ax , by - ay ) << ( i + i );
        }
        Line [0].State = k;
        
        memset ( map , vacant , sizeof ( map ) );
        for ( scanf ( "%d" , &k ); k ; k -- ) {
                scanf ( "%d%d" , &ax , &ay );
                map [ax - 1] [ay - 1] = stock;
        }
        return true;
}

void    fillbody ( TNode & S )
{
        int     x = S.x , y = S.y , State = S.State , i , t;
        for ( map [x] [y] = snake , i = 0; i + 1 < L; i ++ , State >>= 2 ) {
                t = State & 3;
                x += dx [t]; y += dy [t]; map [x] [y] = snake;
        }
}

void    clearbody ( TNode & S )
{
        int     x = S.x , y = S.y , State = S.State , i , t;
        for ( map [x] [y] = vacant , i = 0; i + 1 < L; i ++ , State >>= 2 ) {
                t = State & 3;
                x += dx [t]; y += dy [t]; map [x] [y] = vacant;
        }
}

int     Check ( int sx , int sy )
{
        int     i , x , y , k;
        int     LastClosedSub , Step , a = -1, b = -1;

        memset ( reach , 0 , sizeof ( reach ) );
        LineSub [0] [0] = sx; LineSub [0] [1] = sy;
        reach [sx] [sy] = 1;

        for ( Step = LastClosedSub = OpenSub = 0, ClosedSub = 1; a < 0 && OpenSub < ClosedSub; OpenSub ++ ) {
                if ( OpenSub == LastClosedSub ) { Step ++; LastClosedSub = ClosedSub; }

                for ( k = 0; k < 4; k ++ ) {
                        x = LineSub [OpenSub] [0] + dx [k]; y = LineSub [OpenSub] [1] + dy [k];
                        if ( x < 0 || x == N || y < 0 || y == M || reach [x] [y] || map [x] [y] != vacant ) continue;
                        reach [x] [y] = 1;
                        LineSub [ClosedSub] [0] = x;
                        LineSub [ClosedSub ++] [1] = y;
                        if ( x == 0 && y == 0 ) { a = Step; break; }
                }
        }

        memset ( reach , 0 , sizeof ( reach ) );
        reach [sx] [sy] = 1;

        for ( Step = LastClosedSub = OpenSub = 0, ClosedSub = 1; b < 0 && OpenSub < ClosedSub; OpenSub ++ ) {
                if ( OpenSub == LastClosedSub ) { Step ++; LastClosedSub = ClosedSub; }
                for ( k = 0; k < 4; k ++ ) {
                        x = LineSub [OpenSub] [0] + dx [k]; y = LineSub [OpenSub] [1] + dy [k];
                        if ( x < 0 || x == N || y < 0 || y == M || reach [x] [y] || map [x] [y] == stock ) continue;
                        reach [x] [y] = 1;
                        LineSub [ClosedSub] [0] = x;
                        LineSub [ClosedSub ++] [1] = y;
                        if ( x == 0 && y == 0 ) { b = Step; break; }
                }
        }

        return a == b ? a : -2;
}


void    BFS ()
{
        if ( Line [0].x == 0 && Line [0].y == 0 ) { Min = 0; return; } // 判断开始点是否为终点

        int     LastClosed = 0 , k , x , y , NewState , ret;

        Len ++; // 新建一组数据
        StartLen = Len; Hash [Line [0].x] [Line [0].y] [Line [0].State] = Len; // 将开始点插入Hash表中

        for ( Open = 0 , Closed = 1; Open < Closed; Open ++ ) {
                if ( Open == LastClosed ) { Len ++; LastClosed = Closed; } // 碰到新扩展的部分 步数加一
                
                fillbody ( Line [Open] );                                  // 将snakebody填入地图

                /*ret = Check ( Line [Open].x , Line [Open].y );

                if ( ret == -1 ) return;
                if ( ret > 0 ) { if ( Len - StartLen + ret - 1 < Min ) Min = Len - StartLen + ret - 1;  }
                        else*/
                for ( k = 0; k < 4; k ++ ) {                                    // 枚举头前进的4个方向
                        x = Line [Open].x + dx [k];
                        y = Line [Open].y + dy [k];
                        if ( x < 0 || x == N || y < 0 || y == M || map [x] [y] != vacant ) continue;  // 越界或不是空地

                        NewState = ( Line [Open].State << 2 ) & ~face [L - 1] | f_1 [k]; // 求出新的State
                        if ( Hash [x] [y] [NewState] < StartLen ) {              // Hash判重
                                Hash [x] [y] [NewState] = Len;
                                Line [Closed].x = x; Line [Closed].y = y;
                                Line [Closed ++].State = NewState;
                        }
//                        if ( Closed >= Limit ) return;
                        if ( x == 0 && y == 0 ) { if ( Len - StartLen < Min ) Min - Len - StartLen; Closed --; }
                }

                clearbody ( Line [Open] );                              // 在地图中 清除snakebody
        }
}

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );

        Len = 0;

        memset ( Hash , 0xff , sizeof ( Hash ) );
        int     step = 0;
        
        while ( init () ) {
                Min = 0x7fffffff;
                BFS ();
                if ( Min == 0x7fffffff ) Min = -1;
                printf ( "Case %d: %d\n" , ++ step , Min );
        }
}
 