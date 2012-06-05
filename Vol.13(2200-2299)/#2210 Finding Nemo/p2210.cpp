// 1651806 2008-09-29 22:27:37 Accepted  2210 C++ 80 1644 呆滞的慢板 

// 最短路 Dijkstra 搜索，注意 Nemo 的位置 X, Y 可能大于 200 

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
#include <algorithm>
using namespace std;

const int X = 202, Y = 202;

int WH[210][210], WV[210][210];
int DH[210][210], DV[210][210];
int G[210][210];

MBH<210*210> hp;

int main() {
    
    int N, M, x, y, k, l, px, py;
    double fx, fy;
    while(cin >> N >> M && N != -1) {
        memset(WH, 0, sizeof(WH));
        memset(WV, 0, sizeof(WV));
        memset(DH, 0, sizeof(DH));
        memset(DV, 0, sizeof(DV));
        
        while(N--) {
            cin >> x >> y >> k >> l;
            if(k) while(l--)
                WV[x][y++] = true;
            else while(l--) 
                WH[x++][y] = true;
        }
        while(M--) {
            cin >> x >> y >> k;
            if(k) {DV[x][y] = true; WV[x][y] = false;}
            else {DH[x][y] = true; WH[x][y] = false;}
        }
        cin >> fx >> fy;
        if(fx > X || fy > Y) {
            puts("0");
            continue;
        }
        px = int(fx);
        py = int(fy);
        memset(G, -1, sizeof(G));
        hp.clear();
        hp.push(0, 0);
        while(!hp.empty()) {
            x = hp.top().first % X;
            y = hp.top().first / X;
            k = G[x][y] = hp.top().second;
            if(x == px && y == py) break;
            hp.pop();
            if(x > 0 && !WV[x][y] && G[x-1][y] == -1)
                hp.push(x-1+y*X, k + DV[x][y]);
            if(x + 1 < X && !WV[x+1][y] && G[x+1][y] == -1)
                hp.push(x+1+y*X, k + DV[x+1][y]);
            if(y > 0 && !WH[x][y] && G[x][y-1] == -1)
                hp.push(x+(y-1)*X, k + DH[x][y]);
            if(y + 1 < Y && !WH[x][y+1] && G[x][y+1] == -1)
                hp.push(x+(y+1)*X, k + DH[x][y+1]);
        }
        
        cout << G[px][py] << endl;
    }
    
}
