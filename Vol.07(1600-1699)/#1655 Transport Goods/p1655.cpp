// 3005534 2008-07-26 00:19:37 Accepted 1655 C++ 00:00.04 928K 呆滞的慢板 

// 单源最短路，注意权最短的含义，用 Dijkstra，使得路权乘积最大 

// 注意，这是个无向图，有很 WS 的两点：
// 1. 有平行边; 2. 不确保连通。

// 以后做题，一定要注意咬文嚼字，对于这些细节要特别细心 

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
#include <cmath>
using namespace std;

MBH<100, double, greater<double> >  hp;

double  dist[101],  val[101],   z,  tot;

double  G[101][101]; 

int N,  M,  x,  y;

int main() {
    
    while( scanf( "%d%d", &N, &M ) != EOF ) {
    
        for( int i = 1; i < N; ++i )
            scanf( "%lf", val + i );
        
        memset( G, 0, sizeof( G ) );
        
        while( M-- ) {
            scanf( "%d%d%lf", &x, &y, &z );
            if( G[y][x] < 1.0 - z )
                G[y][x] = 1.0 - z; 
            G[x][y] = G[y][x];
        }
        
        for( int i = 1; i < N; ++i )
            dist[i] = -1.0; 
        
        dist[x = N] = 1.0;
        hp.clear();
        
        while( 1 ) {
            for( y = 1; y <= N; ++y )
                if( G[x][y] > -0.5 && dist[y] < -0.5 )
                    hp.push( y, dist[x] * G[x][y] );
            if( hp.empty() )    break; 
            x = hp.top().first;
            dist[x] = hp.top().second;
            hp.pop();
        }
        
        tot = 0.0;
        for( int i = 1; i < N; ++i )
            if( dist[i] > -0.5 ) 
                tot += ( val[i] * dist[i] );
            
        printf( "%.2lf\n", tot );
    
    }
    
}
