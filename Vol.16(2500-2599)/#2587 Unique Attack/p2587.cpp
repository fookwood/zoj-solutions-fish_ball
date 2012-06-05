// 1658831 2008-10-06 20:02:59 Accepted  2587 C++ 1540 776 呆滞的慢板 

// 求最大流，然后从余流网分别从源和汇 bfs，看是否 bfs 到所有的顶点 

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
    
    bool B[801];
    
    void minCut( int v ) {
        B[v] = true;
        for( int i = V[v].size() - 1; i >= 0; --i ) {
            int w = V[v][i]->next( v );
            if( V[v][i]->remain( v ) > 0 && !B[w] )
                minCut( w );
        }
    }

    bool uniQ( int s, int t ) {
        int ans = size;
        memset( B, 0, sizeof( B ) );
        maxFlow( s, t );
        minCut( s );
        maxFlow( t, s ); 
        minCut( t );
        for(int i = 0; i < size; ++i)
            if(B[i]) --ans;
        return ans == 0;
    }

};

//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////


#include <iostream>
using namespace std;

MaxFlow<801, 20002> mf;

int N, M, A, B;

int main() {
    
    while(scanf("%d%d%d%d", &N, &M, &A, &B) && N) {
        mf.init(N);
        for(int i = 0; i < M; ++i) {
            int x, y, c;
            scanf("%d%d%d", &x, &y, &c);
            x--;y--;
            mf.insert(x, y, c);
            mf.insert(y, x, c);
        }
        puts(mf.uniQ(A-1, B-1) ? "UNIQUE" : "AMBIGUOUS" );
    }
    
}
