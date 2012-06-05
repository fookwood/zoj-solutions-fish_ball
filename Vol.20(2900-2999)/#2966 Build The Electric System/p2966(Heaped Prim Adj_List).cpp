// 2998166 2008-07-23 10:29:17 Accepted 2966 C++ 00:00.04 964K 呆滞的慢板 

// 最小生成树：堆优化 Prim 算法

//////////////////////////////////////////////////////////
//       映射二分堆(Mapped_Binary_Heap)类模板 v1.0      //
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
#include <vector>
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

MBH<500>    hp;

vector<pair<int, int> > W[500];

bool    P[500];

int     V,  E,  T,  L;

int     x,  y,  w;

int main() {

    for( scanf( "%d", &T ); T--; ) {

        scanf( "%d%d", &V, &E );

        for( int i = 0; i < V; ++i )
            W[i].clear();

        while( E-- ) {
            scanf( "%d%d%d", &x, &y, &w );
            W[x].push_back( make_pair( y, w ) );
            W[y].push_back( make_pair( x, w ) );
        }

        hp.clear();
        
        x = 0,  y = V - 1,  L = 0;
        
        memset( P, 0, sizeof( P ) );
        
        while( y-- ) {

            P[x] = true;
            
            for( int i = 0; i < W[x].size(); ++i )
                if( !P[W[x][i].first] )
                    hp.push( W[x][i].first, W[x][i].second );
            
            x = hp.top().first;
            L += hp.top().second;
            hp.pop();
            
        }
        
        printf( "%d\n", L );
        
    }

} 
