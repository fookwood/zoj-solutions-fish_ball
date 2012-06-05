#include <stdio.h>
#include <math.h>
#include <algorithm>
#define zero    1e-5
using   namespace std;

int     Ans;
int     CutNum , T;
int     a [8] , b [8] , c [8] , d [8] , p [11];

struct  TPos {
        double  x , y;
}       Data [32];

int     cross ( int a , int b , int c , int d )
{
        return a * d - b * c;
}

bool    Work ( int p , int q )
{
        int     a1 , b1 , c1 , a2 , b2 , c2 , C;
        double  tx , ty;
        a1 = b [p] - d [p] , b1 = c [p] - a [p] , c1 = cross ( c [p] , d [p] , a [p] , b [p] );
        a2 = b [q] - d [q] , b2 = c [q] - a [q] , c2 = cross ( c [q] , d [q] , a [q] , b [q] );
        C = cross ( a1 , b1 , a2 , b2 );
        if ( C == 0 ) return false;
        tx = double ( cross ( c1 , b1 , c2 , b2 )) / C;
        ty = double ( cross ( a1 , c1 , a2 , c2 )) / C;
        if ( tx < zero || ty < zero || tx + zero > 1000 || ty + zero > 1000 ) return false;
        Data [T].x = tx , Data [T ++].y = ty;
        return true;
}

bool    cmp ( const TPos &a , const TPos &b )
{
        return  fabs ( a.x - b.x ) < zero ? a.y < b.y : a.x < b.x; 
}

main ()
{
//        freopen ( "f.in" , "r" , stdin );
//        freopen ( "p.out" , "w" , stdout );
        
        int     i , j , last , Num = 0;
        p [0] = 0 , p [1] = 0 , p [3] = 1 , p [6] = 3 , p [10] = 6;
        while ( scanf ( "%d" , &CutNum ) , CutNum ) {
                Num ++;
                for ( i = 0; i < CutNum; i ++ )
                        scanf ( "%d%d%d%d" , &a [i] , &b [i] , &c [i] , &d [i] );

//                if ( Num == 2738 )
//                for ( i = 0; i < CutNum;i ++ )
//                        printf ( "%d %d %d %d\n" , a [i] , b [i] , c [i] , d [i] );

                for ( i = 0; i < CutNum; i ++ )
                        for ( j = i + 1; j < CutNum; j ++ )
                                if ( a [i] == a [j] && b [i] == b [j] && c [i] == c [j] && d [i] == d [j]
                                || a [i] == c [j] && b [i] == d [j] && c [i] == a [j] && d [i] == b [j] )
                                        CutNum -- , a [j] = a [CutNum] , b [j] = b [CutNum] , c [j] = c [CutNum] , d [j] = d [CutNum] , j --;
                Ans = ( 1 + CutNum ) * CutNum / 2 + 1;
                for ( T = i = 0; i < CutNum; i ++ )
                        for ( j = i + 1; j < CutNum; j ++ )
                                if ( !Work ( i , j ) ) Ans --;
//                printf ( "T = %d\n" , T );
                sort ( Data , Data + T , cmp );


                for ( last = i = 1; i < T; i ++ ) if ( fabs ( Data [i].x - Data [i - 1].x ) > zero || fabs ( Data [i].y - Data [i - 1].y ) > zero )
                        Ans -= p [last] , last = 1;
                        else last ++;
                Ans -= p [last];

//                if ( Num == 2738 )
                printf ( "%d\n" , Ans );
        }
}
 