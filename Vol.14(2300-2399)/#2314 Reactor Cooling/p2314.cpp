// 1659674 2008-10-07 15:42:34 Accepted  2314 C++ 160 1792 呆滞的慢板 

// 带上下界的环形流
// 添加源点和汇点 S, T，若存在边 (u, v)，则添加边 (S, v), (u, T)，
// 容量为 l，(u, v) 的容量改为c - l。
// 看 S, T 的最大流是否为 sigma(li)。

// 道理很简单，每条边的下界流，先将这些下界流预存在该边中，
// 然后他们都必须从其他地方流回反向点，例如： 
// 如果某边 v->w 有下界 li，那么必须从 w 有另外的途径
// 将 li 的流从 w 流回 v，而这些另外途径的流只能占用 c-l 部分的容量 

// 而环流合法的条件就是这个 s-t 网络有 sigma(li) 的最大流。 

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

int v[50000], w[50000], l[50000], c[50000];
int s[200], t[200], N, M, T, S;
MaxFlow<210> mf;

int main() {
    for(scanf("%d", &T); T--;) {
        scanf("%d%d", &N, &M);
        mf.init(N+2);
        memset(s, 0, sizeof(s));
        memset(t, 0, sizeof(t));
        for(int i = S = 0; i < M; ++i) {
            scanf("%d%d%d%d", v+i, w+i, l+i, c+i);
            S += l[i];
            s[w[i]-1] += l[i];
            t[v[i]-1] += l[i];
            mf.insert(v[i]-1, w[i]-1, c[i]-l[i]);
        }
        for(int i = 0; i < N; ++i) {
            mf.insert(N, i, s[i]);
            mf.insert(i ,N+1, t[i]);
        }
        if(mf.maxFlow(N, N+1) != S) puts("NO");
        else {
            puts("YES");
            for(int i = 0; i < M; ++i) {
                printf("%d\n", mf.buf[i].f+l[i]);
            }
        }
        if(T) puts("");
    }
}
