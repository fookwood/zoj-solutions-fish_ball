// 3055295 2008-08-29 19:40:32 Accepted 2616 C++ 00:00.62 6368K 呆滞的慢板 

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

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int SZ = 6002;
const int INF = 1 << 28;

// 边结构体

struct Edge {
    // u,v 为这条边的两个端点
    // cuv 和 cvu 为这条边两个方向的容量
    // f 为这条边的当前流量
    int u, v, cuv, cvu, f;

    Edge() {
    }

    Edge(int u, int v, int cuv, int cvu) :
            u(u), v(v), cuv(cuv), cvu(cvu), f(0) {
    }

    int other(int p)const {
        return p == u ? v : u;
    }

    int cap(int p)const {
        return p == u ? cuv - f : cvu + f;
    }

    void addFlow(int p, int flow) {
        f += (p == u ? flow : -flow);
    }
};


// 高度顶点列表

class NodeList {
    // lvl 为当前列表最高顶点的高度
    // nxt 为某个顶点的后继(一个顶点只能存在于一个高度中)
    // idx 为某个高度的第一个顶点编号
    // v 为这个高度表的顶点数目
    int lvl, nxt[SZ], idx[2 * SZ], v;
public:

    // 清空顶点列表

    void clear(int cv) {
        v = cv;
        lvl = -1;
        memset(idx, -1, sizeof (idx));
    }

    // 检查顶点列表是否为空

    bool empty()const {
        return lvl < 0;
    }

    // 在高度 h 处插入顶点 n

    void insert(int n, int h) {
        nxt[n] = idx[h];
        idx[h] = n;
        lvl = max(lvl, h);
    }

    // 移除最高的顶点，返回他的编号

    int remove() {
        int r = idx[lvl];
        idx[lvl] = nxt[idx[lvl]];
        while (lvl >= 0 && idx[lvl] == -1) lvl--;
        return r;
    }
};

// 网络类

class MaxFlow {public:
    // edge 为所有边的实际定位
    // net 为图的邻接表，指向 edge 中的边
    // v 为顶点数，s,t 为源和汇的顶点编号
    // lst 为高度顶点列表
    // h 为顶点对应的高度
    // hn 为各高度具有的顶点数
    // e 为顶点的余流
    // cur 为！！！
    vector<Edge> edge;
    vector<Edge*> net[SZ];
    int v, s, t;
    NodeList lst;
    int h[SZ], hn[2 * SZ], e[SZ], cur[SZ];

    // 根据已有的 edge 构造图邻接表

    void initNet() {
        for (int i = 0; i < v; ++i)
            net[i].clear();
        for (int i = edge.size() - 1; i >= 0; --i) {
            net[edge[i].u].push_back(&edge[i]);
            net[edge[i].v].push_back(&edge[i]);
        }
    }

    // 初始化各顶点的高度

    void initHeight() {
        memset(h, 0, sizeof (h));
        memset(hn, 0, sizeof (hn));
        memset(e, 0, sizeof (e));
        e[s] = INF;
        for (int i = 0; i < v; ++i) h[i] = v;
        queue<int>Q;
        Q.push(t);
        h[t] = 0;
        while (!Q.empty()) {
            int p = Q.front();
            Q.pop();
            for (int i = net[p].size() - 1; i >= 0; --i) {
                int u = net[p][i]->other(p), ec = net[p][i]->cap(u);
                if (ec != 0 && h[u] == v && u != s) {
                    h[u] = h[p] + 1;
                    Q.push(u);
                }
            }
        }
        for (int i = 0; i < v; ++i)++hn[h[i]];
    }

    // 执行间隙优化

    void gapHeuristic(int k) {
        if (hn[k] != 0 || k > v + 1)return;
        for (int i = 0; i < v; ++i) {
            if (h[i] > k && h[i] <= v && i != s) {
                --hn[h[i]];
                ++hn[v + 1];
                h[i] = v + 1;
            }
        }
    }

    // 对某个顶点的当前边执行压入操作

    void push(int u) {
        Edge*te = net[u][cur[u]];
        int ex = min(te->cap(u), e[u]), p = te->other(u);
        if (e[p] == 0 && p != t)lst.insert(p, h[p]);
        te->addFlow(u, ex);
        e[u] -= ex;
        e[p] += ex;
    }

    // 重标记一个顶点

    void relabel(int u) {
        int mh = 2 * v, oh = h[u];
        for (int i = net[u].size() - 1; i >= 0; --i) {
            int p = net[u][i]->other(u);
            if (net[u][i]->cap(u) != 0)
                mh = min(mh, h[p] + 1);
        }
        hn[h[u]]--;
        hn[mh]++;
        h[u] = mh;
        cur[u] = net[u].size() - 1;
        gapHeuristic(oh);
    }

    // 初始化网络流

    void initFlow() {
        initNet();
        initHeight();
        for (int i = 0; i < v; ++i)
            cur[i] = net[i].size() - 1;
        lst.clear(v);
        for (; cur[s] >= 0; --cur[s])push(s);
    }

    // 排除一个顶点

    void discharge(int u) {
        while (e[u] > 0) {
            if (cur[u] < 0)relabel(u);
            else if (net[u][cur[u]]->cap(u) > 0 &&
                    h[u] == h[net[u][cur[u]]->other(u)] + 1)
                push(u);
            else --cur[u];
        }
    }

public:

    // 返回边集合的引用

    vector<Edge>& edges() {
        return edge;
    }

    // 求最大流

    int maxFlow(int ss, int tt) {
        s == ss;
        t = tt;
        initFlow();
        while (!lst.empty()) {
            int u = lst.remove();
            discharge(u);
        }
        return e[t];
    }
};

#include <iostream>
#include <set>
using namespace std;

MaxFlow     mf;

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
////////////////////
        mf.edges().clear();
        
        scanf( "%d", &N );
        for( int i = 1; i <= N; ++i ) {
            scanf( "%d", &X );
            S += X;
////////////////////
            mf.edges().push_back( Edge( 0, i, X, 0 ) );
            while( getchar() != '\n' ) {
                scanf( "%d", &X );
                H[X].push_back( i );
            }
        }
        
        scanf( "%d", &M );
        for( int i = N+1; i <= N+M; ++i ) {
            scanf( "%d", &X );
            S += X;
            mf.edges().push_back( Edge( i, N+M+1, X, 0 ) );
            P.clear();
            while( getchar() != '\n' ) {
                scanf( "%d", &X );
                for( int j = 0; j < H[X].size(); ++j )
                    P.insert( H[X][j] );
            }
            for( it = P.begin(); it != P.end(); ++it )
                mf.edges().push_back( Edge( *it, i, INF, 0 ) );
        }
        
        printf( "Case %d:\n", t + 1 );
        mf.v = M+N+2;
        printf( "%d\n", S - mf.maxFlow( 0, N+M+1 ) );

    }

}
