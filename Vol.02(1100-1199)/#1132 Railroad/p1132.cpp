// 3042230 2008-08-19 21:06:20 Accepted 1132 C++ 00:01.53 3744K 呆滞的慢板 

// Dijsktra，先正向找出最早到达时间，再反向找出最晚出发时间 

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
#include <string>
#include <vector>
using namespace std;

int N,  M,  C = 0;
char    input[10000];
map<string, int>    idx;
vector<string>      name;

// 第一个是到达时间，第二个是车站编号 
vector<map<int, int>* > V[100]; 

map<int, int>    buf[1000];
map<int, int>::iterator it, it2;

MBH<100, int, less<int> >       hp1;
MBH<100, int, greater<int> >    hp2; 

int pre[100],   tim[100];

int main() {
    
      
    while( scanf( "%d", &N ) && N ) {
        
        idx.clear();
        
        name.resize( N );
        
        for( int i = 0; i < N; ++i ) {
            scanf( "%s", input );
            name[i] = input;
            idx[name[i]] = i;
            V[i].clear(); 
        }
        
        scanf( "%d", &M );
        for( int i = 0; i < M; ++i ) {
            int K, X, P; 
            buf[i].clear();
            for( scanf( "%d", &K ); K--; ) {
                scanf( "%d", &X );
                scanf( "%s", input );
                P = idx[input];
                buf[i][X] = P;
                V[P].push_back( buf + i ); 
            }
        }
        
        int T, bg, ed;
        
        scanf( "%d", &T );
        scanf( "%s", input );
        bg = idx[input];
        scanf( "%s", input );
        ed = idx[input];

        memset( pre, -1, sizeof( pre ) );
        
        hp1.clear();
        
        int now = bg;
        
        for( int i = 0; i < V[bg].size(); ++i ) {
            bool    yes = false;
            for( it = V[bg][i] -> lower_bound( T );
                 it != V[bg][i] -> end(); ++it ) {
                if( it -> second == bg )
                    yes = true;
                if( yes ) {
                    hp1.push( bg, it -> first );
                    break;
                }
            }
        }
        
        while( !hp1.empty() ) {
            int sta = hp1.top().first;
            int tm = hp1.top().second;
            hp1.pop();
            pre[sta] = now;
            tim[sta] = tm;
            now = sta;
            for( int i = 0; i < V[sta].size(); ++i )
                for( it = V[sta][i] -> upper_bound( tm );
                     it != V[sta][i] -> end(); ++it )
                    if( pre[it -> second] == -1 )
                        hp1.push( it -> second, it -> first );
            if( pre[ed] != -1 ) break;
        }

        printf( "Scenario #%d\n", ++C );
        
        if( pre[ed] == -1 ) {
            puts( "No connection" );
            puts( "" );
            continue;
        }



        T = tim[ed];
        swap( bg, ed );

        memset( pre, -1, sizeof( pre ) );
        
        now = bg;
        
        hp2.clear();
        
        hp2.push( bg, tim[bg] );
        pre[bg] = bg;
        
        while( !hp2.empty() ) {
            int sta = hp2.top().first;
            int tm = hp2.top().second;
            hp2.pop();
            pre[sta] = now;
            tim[sta] = tm;
            now = sta;
            for( int i = 0; i < V[sta].size(); ++i ) {
                for( it2 = V[sta][i] -> begin(); ; ++it2 )
                    if( it2 -> second == sta )
                        break;
                if( it2 -> first > tim[sta] )   continue;
                for( it = V[sta][i] -> begin(); it != it2; ++it )
                    if( pre[it -> second] == -1 )
                        hp2.push( it -> second, it -> first );
            }
            if( pre[ed] != -1 ) break;
        }
        

        printf( "Departure %04d ", tim[ed] );
        puts( name[ed].c_str() );
        printf( "Arrival   %04d ", tim[bg] );
        puts( name[bg].c_str() );
        puts( "" );
            

    }
    
}
