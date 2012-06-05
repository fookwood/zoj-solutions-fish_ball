// 2822785 2008-04-04 15:47:59 Accepted 1358 C++ 00:01.44 924K 呆滞的慢板 
// 简单 DFS，看清楚规则，规则是高中物理说的“逐差法”，注意精度问题，这使我 WA 多次 

#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

struct Object {
    double  x,  y;
    int     n;
};

char    A[257][257];
int     M,  N;
Object  now,    temp;

inline bool isValid( const int& i, const int& j ) {
    return  i >= 0 && j >= 0 && i < N && j < M && A[i][j] == 'x';
}

void DFS( const int& i, const int& j ) {
    temp.x += double( i );
    temp.y += double( j );
    temp.n++;
    A[i][j] = '.';
    if( isValid( i + 1, j ) )
        DFS( i + 1, j );
    if( isValid( i - 1, j ) )
        DFS( i - 1, j );
    if( isValid( i, j + 1 ) )
        DFS( i, j + 1 );
    if( isValid( i, j - 1 ) )
        DFS( i, j - 1 );
}

int main() {
    vector<Object>  seq;
    while( scanf( "%d%d", &M, &N ) && ( M || N ) ) {
        seq.resize( 0 );
        while( 1 ) {
            for( int i = 0; i <= N; i++ )
                scanf( "%s", A[i] );
            now.x = 0.0;
            now.y = 0.0;
            now.n = 0;
            for( int i = 0; i < N; i++ ) {
                for( int j = 0; j < M; j++ ) {
                    if( A[i][j] == 'x' ) {
                        temp.x = temp.y = 0.0;
                        temp.n = 0;
                        DFS( i, j );
                        if( temp.n > now.n ) {
                            now.x = temp.x;
                            now.y = temp.y;
                            now.n = temp.n;
                        }
                    }
                }
            }
            now.x /= double( now.n );
            now.y /= double( now.n );
            seq.push_back( now );
            if( A[N][0] == '=' )
                break;
        }
        int T = seq.size() / 2;
        double  sX = 0.0,   sY = 0.0;
        for( int i = 0; i < T; i++ ) {
            sX += ( seq[i + T].x - seq[i].x );
            sY += ( seq[i + T].y - seq[i].y );
        }
        // 对于浮点数精度问题要有发神经般的反射！！嗅觉！！ 
        double  xx = round( sY / double(T) / double(T) * 100.0 ) / 100.0 + 1e-5;
        double  yy = round( sX / double(T) / double(T) * 100.0 ) / 100.0 + 1e-5;
        printf( "%.2lf %.2lf\n", xx, yy );
    }
}
