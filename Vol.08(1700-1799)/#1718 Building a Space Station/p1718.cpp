// 3004434 2008-07-25 14:50:26 Accepted 1718 C++ 00:00.01 852K 呆滞的慢板 

// 最小生成树 Prim 算法 

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
#include <cmath>
using namespace std;

const int MAX_SZ = 100;

MBH<MAX_SZ, double>    hp;

double  X[MAX_SZ], Y[MAX_SZ], Z[MAX_SZ], R[MAX_SZ], S,  D;

bool    B[MAX_SZ];

int     N,  P;

int main() {
    
    while( scanf( "%d", &N ) && N ) {
        
        for( int i = 0; i < N; ++i )
            scanf( "%lf%lf%lf%lf", X+i, Y+i, Z+i, R+i );
        
        memset( B, 0, sizeof( B ) );
        
        B[P = 0] = true;
        S = 0;
        hp.clear();
        
        while( 1 ) {
            for( int i = 0; i < N; ++i ) {
                if( !B[i] ) {
                    D = sqrt( (X[P]-X[i])*(X[P]-X[i]) +
                              (Y[P]-Y[i])*(Y[P]-Y[i]) +
                              (Z[P]-Z[i])*(Z[P]-Z[i]) );
                    D = ( D > R[P] + R[i] ) ? D - R[P] - R[i] : 0;
                    hp.push( i, D );
                }
            }
            if( hp.empty() )    break;
            P = hp.top().first;
            S += hp.top().second;
            hp.pop();
            B[P] = true;
        }
        
        printf( "%.3lf\n", S );
        
    }
    
} 
