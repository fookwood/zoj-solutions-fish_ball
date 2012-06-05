// 3064791 2008-09-09 17:02:17 Accepted 2504 C++ 00:00.04 952K 呆滞的慢板 

// 简单最短路，Dijktra 

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
#include <map>
#include <vector>
using namespace std;

map<int, int>   G[1001];
map<int, int>::iterator iter;

vector<int> P;

int T,  N,  M,  K,  C = 0;

MBH<1001>   hp;
int D[1001];

int main() {
    
    for( scanf( "%d", &T ); T--; ) {
        
        scanf( "%d%d", &N, &M );
        
        for( int i = 1; i <= N; ++i  )
            G[i].clear();
        
        for( int i = 0; i < M; ++i ) {
            int x,  y,  d;
            scanf( "%d%d%d", &x, &y, &d );
            G[x][y] = G[y][x] = d;
        }
        
        scanf( "%d", &K );
        P.resize( K );
        
        for( int i = 0; i < K; ++i )
            scanf( "%d", &P[i] );
        
        printf( "TEST %d ", ++C );
            
        int len = 0;
        for( int i = 1; i < K; ++i ) {
            iter = G[P[i-1]].find( P[i] );
            if( iter == G[P[i-1]].end() ) {
                len = -1;
                break;
            }
            len += iter->second;
        }
        
        if( len == -1 ) {
            puts( "N" );
            continue;
        }
        
        if( N == 1 ) {
            puts( "Y 0" );
            continue;
        }
        
        memset( D, -1, sizeof( D ) );
        hp.clear();
        D[1] = 0;
        hp.push( P[1], G[P[0]][P[1]] );
        while( !hp.empty() ) {
            int v = hp.top().first;
            int d = hp.top().second;
            hp.pop();
            D[v] = d;
            if( v == N ) break;
            for( iter = G[v].begin(); iter != G[v].end(); ++iter )
                if( D[iter->first] == -1 )
                    hp.push( iter->first, d + iter->second );
        }
        
        printf( "Y %d\n", len - D[N] );
        
    }
    
}
