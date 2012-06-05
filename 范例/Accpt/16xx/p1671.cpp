#include <stdio.h>

#define MAX     8

const   int dx [4] = { 0 , 0 , -1 , 1 };
const   int dy [4] = { -1 , 1 , 0 , 0 };

struct  TNode {
        int     x , y;
}       Data [MAX * MAX];

int     Start , Goal;
int     H , W , NumberPoint , map [MAX] [MAX] , dis [MAX * MAX] [MAX * MAX];
int     min [MAX] [MAX] , MinTime [MAX * MAX];
bool    mk [MAX * MAX];

void    DFS ( int x , int y , int cost = 0 )
{
        if ( x < 0 || x == H || y < 0 || y == W ) return;
        if ( cost > 6 || cost >= min [x] [y] ) return;
        min [x] [y] = cost;
        if ( cost && map [x] [y] != 1 ) return;
        for ( int i = 0; i < 4; i ++ ) DFS ( x + dx [i] , y + dy [i] , cost + 1 );
}

bool    init ()
{
        scanf ( "%d%d" , &W , &H ); if ( W == 0 ) return false;
        NumberPoint = 0;
        int     i , j , k;
        for ( i = 0; i < H; i ++ )
                for ( j = 0; j < W; j ++ ) {
                        scanf ( "%d" , &map [i] [j] );
                        if ( map [i] [j] <= 1 ) continue;
                        if ( map [i] [j] == 2 ) Start = NumberPoint;
                        if ( map [i] [j] == 3 ) Goal = NumberPoint;
                        Data [NumberPoint].x = i , Data [NumberPoint ++].y = j;
                }

        for ( i = 0; i < NumberPoint; i ++ ) {
                for ( j = 0; j < H; j ++ )
                        for ( k = 0; k < W; k ++ ) min [j] [k] = 10;
                DFS ( Data [i].x , Data [i].y );
                for ( j = 0; j < NumberPoint; j ++ )
                        dis [i] [j] = min [Data [j].x] [Data [j].y];
        }
        return true;
}

void    Work ()
{
        int     i , j , k;
        for ( i = 0; i < NumberPoint; i ++ ) mk [i] = false , MinTime [i] = 100000;
        MinTime [Start] = 0;
        for ( i = 0; i < NumberPoint; i ++ ) {
                for ( k = -1 , j = 0; j < NumberPoint; j ++ ) if ( !mk [j] )
                        if ( k == -1 || MinTime [j] < MinTime [k] ) k = j;
                if ( MinTime [k] == 100000 ) break;
                mk [k] = true;
                if ( k == Goal ) {
                        printf ( "%d\n" , MinTime [k] );
                        return;
                }
                for ( j = 0; j < NumberPoint; j ++ ) if ( !mk [j] && dis [k] [j] < 6 )
                        if ( MinTime [k] + dis [k] [j] < MinTime [j] )
                                MinTime [j] = MinTime [k] + dis [k] [j];
        }
        printf ( "-1\n" );
        
}

main ()
{
        while ( init () ) Work ();
}
 