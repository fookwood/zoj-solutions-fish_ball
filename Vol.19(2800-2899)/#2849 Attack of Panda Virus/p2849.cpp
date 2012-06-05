// 1688347 2008-11-03 22:04:08 Accepted  2849 C++ 720 6412 呆滞的慢板 

// 典型的最短路 PFS，每个节点进一次优先队列，优先级别为：
// 时间标记短的优先，其次变种号小的优先。 

//////////////////////////////////////////////////////////
//       映射二分堆(Mapped_Binary_Heap)类模板 v1.3      //
//////////////////////////////////////////////////////////
//                                                      //
//                   模板参数                           //
// 1. SZ:     映射二分堆的最大索引号;                   //
// 2. T:      映射二分堆蕴含值类型，缺省为 int;         //
// 3. Op:     比较准则 functor，缺省为小于;             // 
//                                                      //
//                     接口                             //
// 1. clear:  清空堆;                                   //
// 2. empty:  判空;                                     // 
// 3. size:   返回堆大小(元素个数);                     //
// 4. top:    返回堆顶元素(索引和值结对);               //
// 5. push:   按索引插入元素，自动识别更新为最小值;     //
// 6. pop:    删除最小值;                               //
//                                                      //
//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////

#include <functional>
#include <algorithm>
using namespace std;

template <int SZ, class T = int, class Op = less<T> >
class MBH {

    pair<int, T> heap[SZ + 1];
    int key[SZ + 1], sz;

public:

    void clear() { sz = 0; memset( key, 0, sizeof( key ) ); }
    
    int size() const { return sz; }
    
    bool empty() const { return sz == 0; } 
    
    pair<int, T> top() const { return heap[1]; }
    
    void push( int idx, T val ) {
        if( !key[idx] ) {
            key[idx] = ++sz;
            heap[sz] = make_pair( idx, val );
        }
        else if( Op()( val, heap[key[idx]].second ) )
            heap[key[idx]].second = val;
        for( int pos = key[idx], c;
            ( c = pos >> 1 ) && Op()( val, heap[c].second ); pos = c ) {
            swap( heap[pos], heap[c] );
            key[idx] = c;
            key[heap[pos].first] = pos;
        }
    }
    
    void pop() {
        key[heap[1].first] = 0;
        heap[1] = heap[sz--];
        if( sz == 0 )   return;
        key[heap[1].first] = 1;
        for( int pos = 1, c; ( c = pos<<1 ) <= sz; pos = c ) {
            if( c < sz && Op()( heap[c+1].second, heap[c].second ) ) ++c;
            if( Op()( heap[c].second, heap[pos].second ) ) {
                swap( heap[c], heap[pos] );
                key[heap[c].first] = c;
                key[heap[pos].first] = pos;
            }
            else break;
        }
    }

};

//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
using namespace std;

const int N1 = 520;

int G[N1][N1], M, N, Q, K;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<int> cnt;

bool inside(int x, int y) {
    return x >= 0 && x < M &&
            y >= 0 && y < N;
}

MBH<N1*N1, pair<int, int> > hp;

int main() {

    while(scanf("%d%d", &M, &N) != EOF) {
        hp.clear();
        int V = 0;
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                scanf("%d", &G[i][j]);
                if(G[i][j] > 0) {
                    hp.push(i*N1+j, make_pair(1, G[i][j]));
                    V = max(V, G[i][j]);
                }
            }
        }
        while(!hp.empty()) {
            int x = hp.top().first / N1;
            int y = hp.top().first % N1;
            int d = hp.top().second.first;
            int v = hp.top().second.second;
            G[x][y] = v;
            hp.pop();
            for(int i = 0; i < 4; ++i) {
                x += dx[i];
                y += dy[i];
                if(inside(x, y) && G[x][y] < 0)
                    hp.push(x*N1+y, make_pair(max(d, -G[x][y]), v));
                y -= dy[i];
                x -= dx[i];
            }
        }
        cnt.assign(V+1, 0);
        for(int i = 0; i < M; ++i)
            for(int j = 0; j < N; ++j)
                cnt[G[i][j]] += 1;
        for(scanf("%d", &Q); Q--;) {
            scanf("%d", &K);
            printf("%d\n", cnt[K]);
        }
    }

}
