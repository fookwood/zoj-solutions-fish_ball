// 1687646 2008-11-03 16:09:48 Accepted  2567 C++ 70 3536 呆滞的慢板 

// 给一个二分图 <U, V>，选取最小的边集，使得每个顶点的度大于等于 2
// 构造网络，增加源点 s 汇点 t，s->U 的容量为 deg[U]-2， 
// V->t 的容量为 deg[V]-2，求最大流，那么没有流的边集即为所选。 

//////////////////////////////////////////////////////
//                    最大流 v1.1                   //
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
public:
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


    
};


//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//            Thanks Rainco && wy Bigcow            //
//////////////////////////////////////////////////////



#include <iostream>
using namespace std;

MaxFlow<610> mf;
int D1[300], D2[300];
int M, N, E, x, y, s, t;

int main() {
    while(cin >> M >> N >> E) {
        s = M + N;
        t = s + 1;
        mf.init(M + N + 2);
        memset(D1, 0, sizeof(D1));
        memset(D2, 0, sizeof(D2));
        for(int i = 0; i < E; ++i) {
            scanf("%d%d", &x, &y);
            mf.insert(x-1, M+y-1, 1);
            D1[x-1] += 1;
            D2[y-1] += 1;
        }
        bool yes = true;
        for(int i = 0; i < M; ++i) {
            if(D1[i] < 2) {yes = false; break;}
            mf.insert(s, i, D1[i]-2);
        }
        for(int j = 0; j < N; ++j) {
            if(D2[j] < 2) {yes = false; break;}
            mf.insert(M+j, t, D2[j]-2);
        }
        if(!yes) puts("-1");
        else {
            cout << E - mf.maxFlow(s, t) << endl;
            int cnt = 0;
            for(int i = 0; i < E; ++i) {
                if(mf.edge[i].f == 0) {
                    if(cnt++) putchar(' ');
                    printf("%d", i+1);
                }
            }
            puts("");
        }
    }
}
