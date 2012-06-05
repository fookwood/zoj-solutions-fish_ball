// 3047181 2008-08-23 15:11:14 Accepted 2399 C++ 00:04.04 18836K 呆滞的慢板 

// 构图，二分出边容量 

//////////////////////////////////////////////////////
//              最大流(路径扩充) v1.0               //
///////////////////Documentation//////////////////////
//                                                  //
// 1. SZ:       模板参数，确定最大的图规模;         //
// 2. init:     构建一个大小一定的空的流网络;       //
// 3. insert:   对流网络插入一条边;                 //
// 4. maxFlow:  求出指定源-汇的最大流值;            // 
//                                                  //
//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////

#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
    int     v,  w,  f,  c;
    Edge() {}
    Edge( int v, int w, int c, int f = 0 ) : v(v), w(w), c(c), f(f) {}
    int     next( int vv ) { return vv == v ? w : v; }
    int     remain( int vv ) { return vv == v ? c-f : f; }
    void    increase( int vv, int val ) { vv == v ? f += val : f -= val; }
};

template<int SZ, int BUF_SZ = SZ*SZ> 
class MaxFlow {
    
public:
    
    int     size,   edges;
    vector<Edge*>   V[SZ+1];
    Edge    buf[BUF_SZ];
    Edge*   fwd[SZ+1];
    int     Q[SZ + 1],  top;
    
    int addFlow( int v, int flow ) {
        if( fwd[v] == buf - 1 ) return  flow;
        flow = min( flow, fwd[v] -> remain( fwd[v] -> next( v ) ) );
        flow = min( flow, addFlow( fwd[v] -> next(v), flow ) );
        fwd[v] -> increase( fwd[v] -> next(v), flow );
        return  flow;
    }
    
    bool findPath( int s, int t ) {
        memset( fwd, 0, sizeof( fwd ) );
        Q[0] = s;
        top = 1;
        fwd[s] = buf - 1;   // Sentinel
        while( top && !fwd[t] ) {
            int pos = rand() % top;
            int v = Q[pos];
            swap( Q[pos], Q[--top] );
            for( int i = 0; i < V[v].size(); ++i ) {
                if( !fwd[V[v][i] -> next( v )] &&
                         V[v][i] -> remain( v ) ) {
                    fwd[V[v][i] -> next( v )] = V[v][i];
                    Q[top++] = V[v][i] -> next( v );
                }
            }
        }
        return  fwd[t] ? true : false;
    }
    
public:
    
    void init( int sz ) {
        for( int i = 0; i <= size; ++i )
            V[i].clear();
        memset( fwd, 0, sizeof( fwd ) );
        size = sz;
        edges = 0;
    }
    
    void insert( int v, int w, int c ) {
        buf[edges++] = Edge( v, w, c );
        V[v].push_back( buf + edges - 1 );
        V[w].push_back( buf + edges - 1 );
    } 
    
    int maxFlow( int s, int t ) {
        for( int i = 0; i <= size; ++i )
            for( int j = 0; j < V[i].size(); ++j )
                V[i][j] -> f = 0;
        int total = 0;
        while( findPath( s, t ) )
            total += addFlow( t, INT_MAX );
        return  total;
    }
    
};

//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////



#include <iostream>
using namespace std;

int     N,  M;
char    skip[20]; 

MaxFlow<1502, 1000000>   mf; 

int st, ed; 

bool check( int flow ) {
    for( int i = st; i < ed; ++i )
        mf.buf[i].c = flow;
    return  mf.maxFlow( 0, N + M + 1 ) == N;
} 

int main() {
    
    while( scanf( "%d%d", &N, &M ) && N ) {
        
        mf.init( N + M + 2 ); 
        
        for( int i = 1; i <= N; ++i ) {
            mf.insert( 0, i, 1 );
            scanf( "%s", skip );
            while( getchar() != '\n' ) {
                int x;
                scanf( "%d", &x );
                mf.insert( i, N + 1 + x, 1 ); 
            }
        }
        
        st = mf.edges; 
        
        for( int i = 1; i <= M; ++i )
            mf.insert( N + i, N + M + 1, N );
        
        ed = mf.edges; 
        
        int l = N / M,  r = N,  m; 
        
        while( l < r - 1 ) {
            m = ( l + r ) / 2;
            if( check( m ) )    r = m;
            else                l = m;
        } 
        
        printf( "%d\n", r );
        
    }
    
} 
