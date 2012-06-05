// 2996113 2008-07-22 13:13:50 Accepted 1942 C++ 00:00.02 904K 呆滞的慢板 

// 在一个欧几里德图上，求一条路径使得途径边最大值最小
// 输出这个最小值

// 用 Kruscal 变相解决，效率有点低 

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

    void union_set( int x, int y ) {
        x = find_set( x );
        y = find_set( y );
        if( x == y )    return;
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
    }
    
    int get_sets() const { return sets; }
    
    int get_size( int x ) { return size[find_set( x )]; }
    
};

////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Edge {
    int x,  y,  dist;
    Edge( int x, int y, int d ) :
        x( x ), y( y ), dist( d ) {}
};

inline bool operator < ( Edge e1, Edge e2 ) {
    return  e1.dist < e2.dist;
}

UFS<200>    U;

vector<Edge>    V;
vector<pair<int, int> > P;

int     N,  T = 0;

int main() {
    
    while( cin >> N && N ) {
        
        P.resize( N );
        V.clear();
        
        for( int i = 0; i < N; ++i ) {
            cin >> P[i].first >> P[i].second;
            for( int j = 0; j < i; ++j ) {
                int x = P[i].first - P[j].first,
                    y = P[i].second- P[j].second;
                V.push_back( Edge( i, j, x*x + y*y ) );
            }
        }
        
        sort( V.begin(), V.end() );
        
        U.make_set( N );
        
        for( int i = 0; i < V.size(); ++i ) {
            U.union_set( V[i].x, V[i].y );
            if( U.find_set( 0 ) == U.find_set( 1 ) ) {
                printf( "Scenario #%d\nFrog Distance = %.3lf\n\n",
                    ++T, sqrt( double( V[i].dist ) ) );
                break;
            }
        }

    }
    
    
}
