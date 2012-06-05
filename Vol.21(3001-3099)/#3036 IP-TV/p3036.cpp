// 3058663 2008-09-03 19:59:22 Accepted 3036 C++ 00:01.65 1776K 呆滞的慢板 

// 又是最小生成树 

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

#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

map<string, int> idx;
map<string, int>::iterator it;
int     T,  N,  M,  K;
string  input;

int addName( string name ) {
    it = idx.find( name );
    if( it != idx.end() ) return it->second;
    return idx[name] = K++;
}

struct Edge {
    int v,  w,  l;
    Edge() {}
    Edge( int v, int w, int l ) :
        v(v), w(w), l(l) {}
};

bool operator < ( Edge lhs, Edge rhs ) {
    return  lhs.l < rhs.l;
}

vector<Edge> EE;

UFS<2000> ufs;

int tot;

int main() {
    
    for( cin >> T; T--; ) {
        cin >> N >> M;
        idx.clear();
        K = 0;
        tot = 0;
        EE.clear();
        for( int i = 0; i < M; ++i ) {
            int x,  y,  l;
            cin >> input;
            x = addName( input );
            cin >> input;
            y = addName( input );
            cin >> l;
            EE.push_back( Edge( x, y, l ) );
        }
        sort( EE.begin(), EE.end() );
        ufs.make_set( N );
        for( int i = 0; i < M; ++i ) {
            int x = ufs.find_set( EE[i].v ),
                y = ufs.find_set( EE[i].w );
            if( ufs.find_set( EE[i].v ) != 
                ufs.find_set( EE[i].w ) ) {
                ufs.union_set( EE[i].v, EE[i].w );
                tot += EE[i].l;
                if( ufs.get_sets() == 1 )
                    break;
            }
        }
        
        cout << tot << endl;
        
    }
    
}
