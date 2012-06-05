// 这个题时间掐得实在是太紧了，这里面改一点点都 TLE！！！
// 最近点对，不好做啊！！
// 近来很郁闷，总是发觉能 AC 的标程结果都不一样 
// 2877886 2008-04-29 10:15:14 Accepted 2107 C++ 00:02.61 2792K 呆滞的慢板 
 

#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

struct Point { double  x,  y; };

int     N;
Point   V[100000];
Point*  X[100000];
Point*  Y[100000];

inline bool xcmp ( Point* const p1, Point* const p2 ) {
    return  p1 -> x < p2 -> x;
}

inline bool ycmp ( Point* const p1, Point* const p2 ) {
    return  p1 -> y < p2 -> y;
}

inline double dist( const int& i, const int& j ) {
    return  hypot( X[i] -> x - X[j] -> x,
                   X[i] -> y - X[j] -> y );
}

inline double dist2( const int& i, const int& j ) {
    return  hypot( Y[i] -> x - Y[j] -> x,
                   Y[i] -> y - Y[j] -> y );
}

inline double mini( const double& d1, const double& d2 ) {
    return  d1 > d2 ? d2 : d1;
}

// Closest Pair
double CP( const int& left, const int& right ) {

    if( right - left == 1 )
        return  dist( left, right );

    if( right - left == 2 )
        return  mini( dist( left, left + 1 ),
                mini( dist( left + 1, right ),
                      dist( left, right ) ) );

    int     middle = ( left + right ) / 2,  top = 0;

    double  ans = min( CP( left, middle ),
                       CP( middle + 1, right ) );

    for( int i = left; i <= right; ++i ) {
        if( X[middle]->x - ans <= X[i]->x && 
            X[i]->x <= X[middle]->x + ans  ) {
            Y[top++] = X[i];
        }
    }

    sort( Y, Y + top, ycmp );

    for( int i = 0; i < top; ++i ) {
        for( int j = i + 1; j < top; ++j ) {
            if( Y[j] -> y - Y[i] -> y >= ans )    break;
            ans = mini( ans, dist2( i, j ) );
        }
    }

    return  ans;
    
}

int main() {
    
    freopen( "b.in", "r", stdin );
    freopen( "test_out.txt", "w", stdout );
    
    while( scanf( "%d", &N ) && N ) {
        
        for( int i = 0; i < N; ++i ) {
            scanf( "%lf%lf", &V[i].x, &V[i].y );
            X[i] = V + i;
        }
                    
        sort( X, X + N, xcmp );

        printf( "%.2lf\n", CP( 0, N - 1 ) / 2.0 );

    }

}
