// 2151691 2010-04-10 19:49:27 Accepted  3321 C++ 0 184 呆滞的慢板 

// 简单的图论题，检查一个给定的图是否是一个单纯的环。
// 充要条件是，图连通，且每个顶点被恰好提及两次。

////////////////////////////////////////////////////
//              并查集模板(UFS) v1.2              //
////////////////////////////////////////////////////
//                                                //
// 1. SZ:         并查集最大元素总数(模板参数);   //
// 2. make_set:   初始化 N 个元素的并查集;        //
// 3. find_set:   找出某个元素所在的集合;         //
// 4. union_set:  合并两个集合;                   // 
// 5. get_sets:   返回并查集子集的个数;           //
// 6. get_size:   返回元素所在子集的大小;         //
//                                                //
// v1.2 新特性：                                  // 
//   启发式策略： 按秩合并、路径压缩              //
//   新增接口：   子集个数、子集大小              // 
//                                                //
////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////

template<int SZ> class UFS {

    int p[SZ+1], rank[SZ+1], size[SZ+1], sets; 

public:
    
    void make_set( int sz ) {
        for( int i = 0; i <= sz; ++i ) {
            p[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
        sets = sz;
    }
    
    int find_set( int x ) {
        if( x != p[x] )
            p[x] = find_set( p[x] );
        return  p[x];
    }

    bool union_set( int x, int y ) {
        x = find_set( x );
        y = find_set( y );
        if( x == y )    return  false;
        --sets;
        if( rank[x] > rank[y] ) {
            size[x] += size[y];
            p[y] = x;
        }
        else {
            size[y] += size[x];
            p[x] = y;
        }
        if( rank[x] == rank[y] )
            ++rank[y];
        return  true;
    }
    
    int get_sets() const { return sets; }
    
    int get_size( int x ) { return size[find_set( x )]; }
    
};

////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    while(cin >> n >> m) {
        vector<pair<int, int> > e(m);
        UFS<20> ufs;
        ufs.make_set(n);
        int b[10] = {};
        for(int i = 0; i < m; ++i) {
            cin >> e[i].first >> e[i].second;
            ufs.union_set(e[i].first, e[i].second);
            b[e[i].first-1]++;
            b[e[i].second-1]++;
        }
        bool yes = true;
        for(int i = 0; i < n; ++i) {
            if(b[i] != 2)
                yes = false;
        }
        puts(n == m && yes && ufs.get_sets() == 1 ? "YES" : "NO");
    }
}
