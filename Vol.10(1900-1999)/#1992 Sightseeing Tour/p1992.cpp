// 3049463 2008-08-25 00:32:29 Accepted 1992 C++ 00:00.24 912K 呆滞的慢板 

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
    
};

//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////

#include <iostream>
using namespace std;

MaxFlow<202, 1010>  mf;

int     T,  V,  E;

int     in[201],    out[201];

vector<pair<int, int> > P;

int main() {
    
    for( cin >> T; T--; ) {
         
        P.clear();
        
        memset( in, 0, sizeof( in ) );
        memset( out, 0, sizeof( out ) );
        
        for( cin >> V >> E; E--; ) {
            int x,  y,  t;
            cin >> x >> y >> t;
            ++out[x];
            ++in[y];
            if( !t ) P.push_back( make_pair( x, y ) );
        }
        
        bool yes = true;
        int tot = 0;
        for( int i = 1; i <= V; ++i ) {
            in[i] -= out[i];
            if( in[i] % 2 ) { yes = false; break; }
            in[i] /= 2;
            if( in[i] > 0 ) tot += in[i];
        }
        if( !yes ) { puts( "impossible" ); continue; }
        
        mf.init( V + 2 );
        
        for( int i = 0; i < P.size(); ++i )
            mf.insert( P[i].first, P[i].second, 1 );

        for( int i = 1; i <= V; ++i ) {
            if( in[i] < 0 )
                mf.insert( 0, i, -in[i] );
            if( in[i] > 0 )
                mf.insert( i, V+1, in[i] );
        }
        
        puts( mf.maxFlow( 0, V+1 ) == tot ?
            "possible" : "impossible" );
        
    }
    
}
