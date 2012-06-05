// 3056409 2008-09-01 09:18:50 Accepted 1994 C++ 00:00.04 2988K ´ôÖÍµÄÂý°å 

#include <iostream>
#include <iterator>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


struct Edge {
    int v, w, c, f;
    Edge() {}
    Edge(int v, int w, int c) : v(v), w(w), c(c), f(0) {}
    int other(int p)const { return p == v ? w : v; }
    int cap(int p)const { return p == v ? c - f : f; }
    void addFlow(int p, int flow) { f += (p == v ? flow : -flow); }
};


template<int SZ>
class NodeList {    
    int lvl, nxt[SZ], idx[2*SZ];
public:
    void clear() {
        lvl = -1;
        memset(idx, -1, sizeof (idx));
    }
    bool empty()const { return lvl < 0; }
    void insert(int v, int h) {
        nxt[v] = idx[h];
        idx[h] = v;
        lvl = max(lvl, h);
    }
    int remove() {
        int r = idx[lvl];
        idx[lvl] = nxt[idx[lvl]];
        while (lvl >= 0 && idx[lvl] == -1) lvl--;
        return r;
    }
};


template<int SZ, int INF = 0xFFFFFFF>
class MaxFlow {

    vector<Edge> edge;
    vector<Edge*> net[SZ];
    int s, t, v_sz;
    NodeList<SZ> lst;
    int h[SZ], hn[2*SZ], e[SZ], cur[SZ];

    void initNet() {
        for (int i = 0; i < v_sz; ++i)
            net[i].clear();
        for (int i = edge.size() - 1; i >= 0; --i) {
            net[edge[i].v].push_back(&edge[i]);
            net[edge[i].w].push_back(&edge[i]);
        }
    }

    void initHeight() {
        memset(h, 0, sizeof (h));
        memset(hn, 0, sizeof (hn));
        memset(e, 0, sizeof (e));
        e[s] = INF;
        for (int i = 0; i < v_sz; ++i) h[i] = v_sz;
        queue<int>Q;
        Q.push(t);
        h[t] = 0;
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            for (int i = net[v].size() - 1; i >= 0; --i) {
                int w = net[v][i]->other(v),
                    ec = net[v][i]->cap(w);
                if (ec != 0 && h[w] == v_sz && w != s) {
                    h[w] = h[v] + 1;
                    Q.push(w);
                }
            }
        }
        for (int i = 0; i < v_sz; ++i)++hn[h[i]];
    }

    void gapHeuristic(int v) {
        if (hn[v] == 0 && v <= v_sz)
        for (int i = 0; i < v_sz; ++i) {
            if (h[i] > v && h[i] <= v_sz && i != s) {
                --hn[h[i]];
                ++hn[v_sz + 1];
                h[i] = v_sz + 1;
            }
        }
    }

    void push(int v) {
        Edge* now = net[v][cur[v]];
        int flow = min(now->cap(v), e[v]),
            w = now->other(v);
        if (e[w] == 0 && w != t)
            lst.insert(w, h[w]);
        now->addFlow(v, flow);
        e[v] -= flow;
        e[w] += flow;
    }

    void relabel(int v) {
        int now = 2 * v_sz, old = h[v];
        for (int i = net[v].size() - 1; i >= 0; --i) {
            int w = net[v][i]->other(v);
            if (net[v][i]->cap(v) != 0)
                now = min(now, h[w] + 1);
        }
        hn[h[v]]--;
        hn[now]++;
        h[v] = now;
        cur[v] = net[v].size() - 1;
        gapHeuristic(old);
    }

    void initFlow() {
        initNet();
        initHeight();
        for (int i = 0; i < v_sz; ++i)
            cur[i] = net[i].size() - 1;
        lst.clear();
        for (; cur[s] >= 0; --cur[s])push(s);
    }

    void discharge(int v) {
        while (e[v] > 0) {
            if (cur[v] < 0)relabel(v);
            else if (net[v][cur[v]]->cap(v) > 0 &&
                    h[v] == h[net[v][cur[v]]->other(v)] + 1)
                push(v);
            else --cur[v];
        }
    }

public:

    void init(int sz) { v_sz = sz; edge.clear(); }
    
    void insert( Edge e ) { edge.push_back( e ); }
    
    void insert( int v, int w, int c ) {
        edge.push_back( Edge( v, w, c ) );
    }

    vector<Edge>& edges() { return edge; }

    int maxFlow(int ss, int tt) {
        s = ss;
        t = tt;
        initFlow();
        while (!lst.empty()) {
            int v = lst.remove();
            discharge(v);
        }
        return e[t];
    }

};


int     T,  M,  N,  K;
    
int     in[200],        out[20];
int     low[200][20],   high[200][20];


int main() {
    
    const int INF = 0xFFFFFFF;
    
    MaxFlow<300, INF>    mf; 
    
    for( scanf( "%d", &T ); T--; ) {
        
        scanf( "%d%d", &M, &N );
        
        for( int i = 0; i < M; ++i )
            scanf( "%d", in + i );
            
        for( int i = 0; i < N; ++i )
            scanf( "%d", out + i );
        
        for( int i = 0; i < M; ++i ) {
            for( int j = 0; j < N; ++j ) {
                low[i][j] = 0;
                high[i][j] = INF;
            }
        }
        
        for( scanf( "%d", &K ); K--; ) {
            int     x,  y,  v;
            char    c[2];
            scanf( "%d%d%s%d", &x, &y, c, &v );
            for( int i = (x?x:1); i <= (x?x:M); ++i ) {
                for( int j = (y?y:1); j <= (y?y:N); ++j ) {
                    switch( *c ) {
                        case '<':
                            high[i-1][j-1] = min( high[i-1][j-1], v - 1 );
                        break;
                        case '>':
                            low[i-1][j-1] = max( low[i-1][j-1], v + 1 );
                        break;
                        case '=':
                            high[i-1][j-1] = min( high[i-1][j-1], v );
                            low[i-1][j-1] = max( low[i-1][j-1], v );
                        break;
                    }
                }
            }
        }
        
        bool yes = true;
        mf.init( M + N + 2 );
        for( int i = 0; i < M; ++i ) {
            for( int j = 0; j < N; ++j ) {
                if( high[i][j] < low[i][j] )
                    yes = false;
                mf.insert( i, M + j, high[i][j] - low[i][j] );
                in[i] -= low[i][j];
                out[j] -= low[i][j];
            }
        }
        
        int tot = 0, s = M + N, t = s + 1;
        for( int i = 0; i < M; ++i ) {
            mf.insert( s, i, in[i] );
            if( in[i] < 0 ) yes = false;
            tot += in[i];
        }
        for( int i = 0; i < N; ++i ) {
            mf.insert( M + i, t, out[i] );
            if( out[i] < 0 ) yes = false;
        }
        
        if( !yes || mf.maxFlow( s, t ) != tot ) {
            puts( "IMPOSSIBLE" );
            if( T ) puts( "" );
            continue;
        }
        
        for( int i = 0; i < M; ++i ) {
            for( int j = 0; j < N; ++j ) {
                if( j ) putchar( ' ' );
                printf( "%d", mf.edges()[i*N+j].f + low[i][j] );
            }
            puts( "" );
        }
        
        if( T ) puts( "" );
        
    }
    
}
