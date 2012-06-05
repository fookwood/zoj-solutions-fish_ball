// 3048891 2008-08-24 14:55:53 Accepted 2616 C++ 00:02.81 21792K 呆滞的慢板 

// 实际上是一个划分的问题，可以转化为求最小割 

// 假设 A 方有 N 个竞标，B 方有 M 个竞标

// 在理想情况下，结果应该是所有竞标都能收到，总价值达到 S

// 然而，在 N 和 M 个竞标中有某些不能共存

// 因此要割断某些边，以符合这个约束

// 构造一个图，S -> N 各有一条边，容量为该个竞标的价格

// M -> T 各有一条边，容量为该个竞标的价格

// 另外，对于 M，N 之间，如果某两个竞标之间不能共存

// 在他们之间增加一条无限容量的边

// 然后求该图最小割，也就是最大流，这就是最大的损失

// 结果就是 S - MaxFlow

// 可以这样理解，这个最小割必然不会包括中间的那些边

// 也就是不会同时取矛盾的双方

// 另外构图上需要一些巧劲 

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
#include <set>
using namespace std;

MaxFlow<6002, 1000000>   mf;

int     T,  N,  M,  S,  X;

vector<int> H[300001];

set<int>    P;
set<int>::iterator  it;

int main() {

    scanf( "%d", &T );

    for( int t = 0; t < T; ++t ) {

        if( t ) puts( "" );

        for( int i = 1; i < 300001; ++i )
            H[i].clear();
            
        S = 0;

        mf.init( 6002 );
        
        scanf( "%d", &N );
        for( int i = 1; i <= N; ++i ) {
            scanf( "%d", &X );
            S += X;
            mf.insert( 0, i, X );
            while( getchar() != '\n' ) {
                scanf( "%d", &X );
                H[X].push_back( i );
            }
        }
        
        scanf( "%d", &M );
        for( int i = N+1; i <= N+M; ++i ) {
            scanf( "%d", &X );
            S += X;
            mf.insert( i, N+M+1, X );
            P.clear();
            while( getchar() != '\n' ) {
                scanf( "%d", &X );
                for( int j = 0; j < H[X].size(); ++j )
                    P.insert( H[X][j] );
            }
            for( it = P.begin(); it != P.end(); ++it )
                mf.insert( *it, i, 1000 );
        }
        
        printf( "Case %d:\n", t + 1 );
        printf( "%d\n", S - mf.maxFlow( 0, N+M+1 ) );

    }

}
