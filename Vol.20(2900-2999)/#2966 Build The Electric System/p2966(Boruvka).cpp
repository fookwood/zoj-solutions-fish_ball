// 2997505 2008-07-22 21:09:53 Accepted 2966 C++ 00:00.02 3372K 呆滞的慢板 

// 最小生成树：Boruvka 算法 

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


#include <cstdio>
#include <cstring>

struct Edge {
    int x,  y,  w;
    Edge() {};
    Edge( int x, int y, int w ) :
        x( x ), y( y ), w( w ) {}
};

UFS<500>    U;

Edge    P[500*500];

Edge*   B[500];

int     V,  E,  T,  x,  y,  w,  L,  h,  N;

inline bool operator < ( const Edge& e1, const Edge& e2 ) {
    return  e1.w > e2.w;
}

int main() {
    
    for( scanf( "%d", &T ); T--; ) {

        scanf( "%d%d", &V, &E );

        U.make_set( V );

        for( int i = 0; i < E; ++i ) {
            scanf( "%d%d%d", &x, &y, &w );
            P[i].x = x;
            P[i].y = y;
            P[i].w = w;
        }
        
        L = 0;
        
        
        for( ; E; E = N ) {
        
            memset( B, 0, sizeof( void* ) * V );
            
            for( h = N = 0; h < E; ++h ) {
                int i = U.find_set( P[h].x ),
                    j = U.find_set( P[h].y );
                if( i == j ) continue;
                P[N] = P[h];
                if( !B[i] || P[h].w < B[i]->w ) { B[i] = P + N; }
                if( !B[j] || P[h].w < B[j]->w ) { B[j] = P + N; }
                ++N;
            }
        
            for( h = 0; h < V; ++h ) {
                if( B[h] && U.find_set( B[h]->x ) != U.find_set( B[h]->y ) ) {
                    U.union_set( B[h]->x, B[h]->y );
                    L += B[h]->w;
                }
            }
        
        }

        printf( "%d\n", L );
        
    }

} 
