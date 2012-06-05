// 1693333 2008-11-08 16:30:59 Accepted  2935 C++ 0 196 呆滞的慢板 

// 地图最短路，直接归约成一般图 Dijkstra。 

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

MBH<500, int> hp;

int D[500];

vector<pair<int, int> > G[500];

int M, N, K;

int main() {
    while(cin >> M >> N && M) {
        hp.clear();
        K = (M+1) * (N+1);
        memset(D, -1, sizeof(D));
        for(int i = 0; i < K; ++i)
            G[i].clear();
        for(int i = 0, dist; i < N; ++i) {
            char c;
            cin >> dist >> c;
            if(dist == 0) continue;
            dist = 2520 / dist;
            if(c == '>' || c == '*')
                G[0*(N+1)+i].push_back(make_pair(0*(N+1)+i+1, dist));
            if(c == '<' || c == '*')
                G[0*(N+1)+i+1].push_back(make_pair(0*(N+1)+i, dist));
        }
        for(int j = 0; j < M; ++j) {
            for(int i = 0, dist; i <= N; ++i) {
                char c;
                cin >> dist >> c;
                if(dist == 0) continue;
                dist = 2520 / dist;
                if(c == 'v' || c == '*')
                    G[j*(N+1)+i].push_back(make_pair((j+1)*(N+1)+i, dist));
                if(c == '^' || c == '*')
                    G[(j+1)*(N+1)+i].push_back(make_pair(j*(N+1)+i, dist));
            }
            for(int i = 0, dist; i < N; ++i) {
                char c;
                cin >> dist >> c;
                if(dist == 0) continue;
                dist = 2520 / dist;
                if(c == '>' || c == '*')
                    G[(j+1)*(N+1)+i].push_back(make_pair((j+1)*(N+1)+i+1, dist));
                if(c == '<' || c == '*')
                    G[(j+1)*(N+1)+i+1].push_back(make_pair((j+1)*(N+1)+i, dist));
            }
        }
        hp.push(0, 0);
        while(!hp.empty()) {
            int x = hp.top().first;
            int d = hp.top().second;
            D[x] = d;
            hp.pop();
            for(int i = 0; i < G[x].size(); ++i)
                if(D[G[x][i].first] == -1)
                    hp.push(G[x][i].first, d + G[x][i].second);
        }
        if(D[(M+1)*(N+1)-1] == -1) puts("Holiday");
        else printf("%d blips\n", D[(M+1)*(N+1)-1]);
    }
}
