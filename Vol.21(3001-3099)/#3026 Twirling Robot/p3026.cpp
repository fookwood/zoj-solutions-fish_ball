// 3059170 2008-09-04 11:50:39 Accepted 3026 C++ 00:00.22 900K 呆滞的慢板 

// 最短路，无负权，Dijkstra，注意开始方向是向右 

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
using namespace std;

int D[4*30*30], N,  M,  ans;
int G[30][30],  C[4];

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

MBH<4*30*30> hp;

inline int getIndex( int x, int y, int d ) {
    return  ( ( x * N ) + y ) * 4 + d;
}

int main() {
    
    while( scanf( "%d%d", &N, &M ) && N ) {

        for( int i = 0; i < M; ++i )
            for( int j = 0; j < N; ++j )
                scanf( "%d", &G[i][j] );

        scanf( "%d%d%d%d", C, C+1, C+2, C+3 );

        hp.clear();
        hp.push( 1, 0 );

        memset( D, -1, sizeof( D ) );

        int d,  x,  y,  dd, xx, yy, pos;

        while( !hp.empty() ) {

            pos = hp.top().first;
            D[pos] = hp.top().second;
            hp.pop();

            d = pos & 3,
            x = (pos >> 2) / N,
            y = (pos >> 2) % N,
            xx, yy, dd;
            if( pos >= getIndex( M-1, N-1, 0 ) ) {
                ans = D[pos];
                break;
            }
            switch( G[x][y] ) {
                case 0: dd = d;       break;
                case 1: dd = (d+1)&3; break;
                case 2: dd = (d+2)&3; break;
                case 3: dd = (d+3)&3; break;
                default:  dd = -1;
            }
            if( dd >= 0 ) {
                xx = x + dx[dd];
                yy = y + dy[dd];
                if( xx >= 0 && xx < M &&
                    yy >= 0 && yy < N &&
                    D[getIndex(xx, yy, dd)] == -1 )
                    hp.push( getIndex(xx, yy, dd), D[pos] );
            }
            for( int i = 0; i < 4; ++i ) {
                dd = (d + i) & 3;
                xx = x + dx[dd];
                yy = y + dy[dd];
                if( xx >= 0 && xx < M &&
                    yy >= 0 && yy < N &&
                    D[getIndex(xx, yy, dd)] == -1 )
                    hp.push( getIndex(xx, yy, dd), D[pos]+C[i] );
            }
        }
        printf( "%d\n", ans );
    }
    
}
