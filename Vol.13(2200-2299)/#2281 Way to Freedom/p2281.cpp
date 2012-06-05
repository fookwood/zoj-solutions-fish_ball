// 2866656 2008-04-24 19:04:02 Accepted 2281 C++ 00:01.45 2776K 呆滞的慢板  
// 改进的 Kruscal 方法，使用并查集模板，O(ElogE) 
// 先将边排序(从大到小)，不断合并边，直到出发点和终点共集
// 然后最大值就是最后合并的边权值 
// 不过要考虑两点不连通的情况，这时候应输出 0，因此 WA1。 

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// 并查集模板！！！ 
template<int SZ> class Union {
    int elem,   subSets;
    int* U;
public:
    Union( int N = 0 ) : elem( N ), subSets( N )
        { U = new int[SZ]; }
    void init( const int& );
    bool check( int, int ) const;
    bool merge( const int&, const int& );
    int getSets() const { return subSets; }
    ~Union() { delete [] U; }
};

template<int SZ> void Union<SZ>::init( const int& N ) {
    elem = subSets = N;
    for( int i = 1; i <= N; i++ )   U[i] = i;
}

template<int SZ> bool Union<SZ>::check( int x, int y ) const {
    while( U[x] != x ) x = U[x];
    while( U[y] != y ) y = U[y];
    return x == y;
}

template<int SZ> bool Union<SZ>::merge( const int& x, const int& y ) {
    int p = x, q = y, r = y;
    while( U[p] != p ) p = U[p];
    while( U[q] != q ) q = U[q];
    if( p == q ) return true;
    U[q] = p;
    while( U[r] != p ) {
        q = U[r];
        U[r] = p;
        r = q;
    }
    subSets--;
    return  false;
}


// 边结构体 
struct Edge {
    int X,  Y,  L;
    Edge( int x, int y, int l ) :
        X(x), Y(y), L(l) {}
};

inline bool icmp( const Edge& e1, const Edge& e2 ) {
    return  e1.L > e2.L;
}

// 主函数 
int main() {
    int V,  E,  S,  D,  temp;
    vector<Edge> edge;
    Union<100001>  U;
    while( scanf( "%d%d", &V, &E ) != EOF ) {
        edge.clear();
        U.init( V );
        for( int i = 0; i < E; i++ ) {
            scanf( "%d%d%d", &S, &D, &temp );
            edge.push_back( Edge( S, D, temp ) );
        }
        scanf( "%d%d", &S, &D );
        sort( edge.begin(), edge.end(), icmp );
        for( temp = 0; temp < E; temp++ ) {
            if( U.check( S, D ) )   break;
            else U.merge( edge[temp].X, edge[temp].Y );
        }
        if( !U.check( S, D ) ) puts( "0" );
        else printf( "%d\n", edge[--temp].L );
    }
}
