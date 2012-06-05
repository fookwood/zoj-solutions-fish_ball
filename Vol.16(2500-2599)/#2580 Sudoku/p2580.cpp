// 2837858 2008-04-11 15:10:32 Accepted 2580 C++ 00:00.01 852K 呆滞的慢板 

// 剪枝 DFS，最重要的剪枝在枚举顺序上
// 将所有 0 的坐标点记录，按照剩余可能数最小的优先进行 DFS
// 这样在绝大多数情况下都是一链到尾，很少有死胡同的情况 

#include <cstdio>
#include <cstdlib>
#include <vector>
using std::vector;

struct  Point {
    int     x,  y;
    bool    B[10];
    int     remain;
    Point(int x = 0, int y = 0) :
        x(x), y(y), remain(0)
        { memset( B, 1, 10 ); }
};

char    A[9][10];

vector<Point>   V;

bool    finish;

inline bool same( const Point& p1, const Point& p2 ) {
    return  p1.x == p2.x || p1.y == p2.y ||
            p1.x / 3 == p2.x / 3 && p1.y / 3 == p2.y /3;
}

void DFS( const int& grade ) {
    if( grade == V.size() ) {
        finish = true;
        return;
    }
    int     pos = -1;
    for( int i = 0; i < V.size(); i++ )
        if( A[V[i].x][V[i].y] == '0' &&
            ( pos == -1 ||
            V[i].remain < V[pos].remain ) )
            pos = i;
    for( int i = 1; i < 10; i++ ) {
        vector<int> trace( 0 );
        if( V[pos].B[i] ) {
            A[V[pos].x][V[pos].y] += i;
            for( int j = 0; j < V.size(); j++ ) {
                if( A[V[j].x][V[j].y] == '0' && same( V[j], V[pos] ) ) {
                    if( V[j].B[i] ) {
                        trace.push_back( j );
                        V[j].B[i] = false;
                        V[j].remain--;
                    }
                }
            }
            DFS( grade + 1 );
            if( finish )    return;
            for( int j = 0; j < trace.size(); j++ ) {
                V[trace[j]].B[i] = true;
                V[trace[j]].remain++;
            }
            A[V[pos].x][V[pos].y] -= i;
        }
    }
}

int main() {
    int     T;
    scanf( "%d", &T );
    while( T-- ) {
        for( int i = 0; i < 9; i++ )
            scanf( "%s", A[i] );

        V.resize( 0 );
        for( int i = 0; i < 9; i++ ) {
            for( int j = 0; j < 9; j++ ) {
                if( A[i][j] == '0' ) {
                    V.push_back( Point( i, j ) );
                    for( int m = 0; m < 9; m++ ) {
                        V.back().B[A[i][m]-'0'] = false;
                        V.back().B[A[m][j]-'0'] = false;
                    }
                    int posx = i - i % 3;
                    int posy = j - j % 3;
                    for( int m = 0; m < 3; m++ )
                        for( int n = 0; n < 3; n++ )
                            V.back().B[A[posx+m][posy+n]-'0'] = false;
                    for( int m = 1; m < 10; m++ )
                        V.back().remain += V.back().B[m];
                }
            }
        }

        finish = false;
        DFS( 0 );

        for( int i = 0; i < 9; i++ )
            puts(A[i]);
    }
}
