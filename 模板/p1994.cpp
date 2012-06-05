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
class MaxFlow {public:
    
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

MaxFlow<300> mf;

int T,  N,  M,  K;

vector<Edge>    E;

int high[200][20],  low[200][20];

int in[200],        out[20];

int main() {
    
    for( scanf( "%d", &T ); T--; ) {
        
        scanf( "%d%d", &N, &M );
        
        int s = N + M,  t = s + 1;
    
        for( int i = 0; i < N; ++i )
            scanf( "%d", in + i );
        
        for( int i = 0; i < M; ++i )
            scanf( "%d", out + i );
        
        for( int i = 0; i < N; ++i ) {
            for( int j = 0; j < M; ++j ) {
                low[i][j] = 0;
                high[i][j] = INT_MAX;
            }
        }
        
        char    c[2];
        int     x,  y,  v;
    
        for( scanf( "%d", &K ); K--; ) {
            scanf( "%d%d%s%d", &x, &y, c, &v );
            if( x == 0 )
            for(x=1;x<=N;++x)
            switch( c[0] ) {
                case '>':   low[x-1][y-1] >?= v+1;  break;
                case '<':   high[x-1][y-1] <?= v-1; break;
                case '=':   low[x-1][y-1] >?= v;
                            high[x-1][y-1] <?= v;   break;
            }
            else if( y == 0 )
            for(y=1;y<=M;++y)
            switch( c[0] ) {
                case '>':   low[x-1][y-1] >?= v+1;  break;
                case '<':   high[x-1][y-1] <?= v-1; break;
                case '=':   low[x-1][y-1] >?= v;
                            high[x-1][y-1] <?= v;   break;
            }
            else
            switch( c[0] ) {
                case '>':   low[x-1][y-1] >?= v+1;  break;
                case '<':   high[x-1][y-1] <?= v-1; break;
                case '=':   low[x-1][y-1] >?= v;
                            high[x-1][y-1] <?= v;   break;
            }
/*
for( int i = 0; i < N; ++i ){
for( int j = 0; j < M; ++j )
cout << low[i][j] << ' ';
cout << endl;}puts("");
for( int i = 0; i < N; ++i ){
for( int j = 0; j < M; ++j )
cout << high[i][j] << ' ';
cout << endl;}puts("");
*/
        }
    
        bool yes = true;
        E.clear();
        for( int i = 0; i < N; ++i ) {
            for( int j = 0; j < M; ++j ) {
                if( high[i][j] < low[i][j] )
                    yes = false;
                E.push_back( Edge( i, N + j, high[i][j] - low[i][j] ) );
                in[i] -= low[i][j];
                out[j] -= low[i][j];
            }
        }
        
        int sum = 0;
        for( int i = 0; i < N; ++i ) {
            if( in[i] < 0 ) yes = false;
            E.push_back( Edge( s, i, in[i] ) );
            sum += in[i];
        }
        for( int i = 0; i < M; ++i ) {
            if( out[i] < 0 ) yes = false;
            E.push_back( Edge( i+N, t, out[i] ) );
        }
        
        if( !yes ) {
            puts( "IMPOSSIBLE" );
            if( T ) puts( "" );
            continue;
        }
        
//        mf.getEdges( E.begin(), E.end() );

        mf.init( M + N + 2 );
        for( int i = 0; i < E.size(); ++i )
            mf.insert( E[i].v, E[i].w, E[i].c );


//for( int i = 0; i < mf.edges; ++i )
//    cout << mf.buf[i].v << ' ' << mf.buf[i].w << ' ' << mf.buf[i].c << endl;


/*
for( int i = 0; i < N; ++i ){
for( int j = 0; j < M; ++j )
cout << low[i][j] << ' ';
cout << endl;}puts("");
for( int i = 0; i < N; ++i ){
for( int j = 0; j < M; ++j )
cout << high[i][j] << ' ';
cout << endl;}puts("");
        
cout << E.size() << endl;
for( int i = 0; i < E.size(); ++i )
    cout << E[i].u << ' ' << E[i].v << ' ' << E[i].c << endl;
//*/

//cout << mf.v << endl;
//cout << s <<' '<< t << endl;

        int ans = mf.maxFlow( s, t );
/*
for( int i = 0; i < N; ++i ){
for( int j = 0; j < M; ++j )
cout << low[i][j] << ' ';
cout << endl;}puts("");
*/
//puts("");
//for( int i = 0; i < mf.edges; ++i )
//    cout << mf.buf[i].v << ' ' << mf.buf[i].w << ' ' << mf.buf[i].f << endl;
        if( ans != sum ) {
            puts( "IMPOSSIBLE" );
            if( T ) puts( "" );
            continue;
        }
        
        for( int i = 0; i < N; ++i ) {
            for( int j = 0; j < M; ++j ) {
                if( j ) putchar( ' ' );
                printf( "%d", mf.buf[i*M+j].f + low[i][j] );
            }
            puts( "" );
        }
        
        if( T ) puts( "" );
    
    }
    
}
