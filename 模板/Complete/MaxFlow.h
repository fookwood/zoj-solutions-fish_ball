//////////////////////////////////////////////////////
//             超级最大流(最高标号) v1.1            //
///////////////////Documentation//////////////////////
//                                                  //
// 1. SZ:       模板参数，确定最大的图规模;         //
// 2. INF:      模板参数，确定无限流量的值;         // 
// 3. init:     构建一个大小一定的空的流网络;       //
// 4. insert:   对流网络插入一条边;                 //
// 5. maxFlow:  求出指定源-汇的最大流值;            // 
// 6. edges:    返回插入的边集合的引用;             // 
//                                                  //
// 1.1 新增了最小割接口，返回最小割顶点集和边集;    // 
//                                                  //
//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//            Thanks Rainco && wy Bigcow            //
//////////////////////////////////////////////////////

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
            edge[i].f = 0;
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


// 以下求最小割 (v1.1) 
// cutV 返回割中 s 集合内的顶点，
// cutE 返回割边的指针

private: 

    vector<int> cutV;
    vector<Edge*> cutE;
    bool B[SZ]; 

    void minCut( int v ) {
        B[v] = true;
        cutV.push_back( v );
        for( int i = net[v].size() - 1; i >= 0; --i ) {
            int w = net[v][i]->other( v );
            if( net[v][i]->cap( v ) > 0 && !B[w] )
                minCut( w );
        }
    }

public:

    void runCut( int ss, int tt ) {
        maxFlow( ss, tt ); 
        memset( B, 0, sizeof( B ) );
        cutV.clear();
        cutE.clear();
        minCut( s );
        for( int i = 0; i < edge.size(); ++i )
            if( B[edge[i].v] && !B[edge[i].w] )
                cutE.push_back( &edge[i] );
    }
    
    vector<int>& getCutV() { return cutV; }
    
    vector<Edge*> getCutE() { return cutE; }
    
};


//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//            Thanks Rainco && wy Bigcow            //
//////////////////////////////////////////////////////
