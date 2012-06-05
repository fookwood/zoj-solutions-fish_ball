// 类似于最小生成树，考虑 Kruscal 算法改变一下，并查集 
// 2862032 2008-04-22 22:12:21 Accepted 1914 C++ 00:00.24 1376K 呆滞的慢板  

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Edge {
    int     v1,  v2;
    double  len;
public:
    Edge() {}
    Edge( int v1, int v2, double len ) :
        v1( v1 ), v2( v2 ), len( len ) {}
    void get_v( int& x, int& y ) const { x = v1; y = v2; }
    double get_len() const{ return len; }
    friend bool operator < 
        ( const Edge& e1, const Edge& e2 ) {
        return e1.len < e2.len;
    }
};

int main() {
    int   T,  S,  N;
    int   A[500];
    double  X[500], Y[500];
    vector<Edge> E;
    scanf( "%d", &T );
    while( T-- ) {
        scanf( "%d%d", &S, &N );
        E.clear();
        for( int i = 0; i < N; ++i ) {
            scanf( "%lf%lf", X + i, Y + i );
            A[i] = i;
            for( int j = 0; j < i; ++j )
                E.push_back( Edge( i, j, 
                    hypot( X[i] - X[j], Y[i] - Y[j] ) ) );
        }
        sort( E.begin(), E.end() );
        double maxLen = 0.0;
        for( int i = 0; i < E.size(); i++ ) {
            if( S == N ) break;
            int     v1, v2;
            E[i].get_v( v1, v2 );
            int     p1 = v1, p2 = v2;
            while( A[p1] != p1 ) p1 = A[p1];
            while( A[p2] != p2 ) p2 = A[p2];
            if( p1 != p2 ) {
                S++;
                maxLen = E[i].get_len();
                A[p2] = p1;
                while( A[v2] != p1 ) {
                    p2 = A[v2];
                    A[v2] = p1;
                    v2 = p2;
                }
            }
        }
        printf( "%.2lf\n", maxLen );
    }
}
