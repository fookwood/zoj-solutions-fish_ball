// 2993679 2008-07-21 15:35:42 Accepted 2833 C++ 00:00.93 1612K 呆滞的慢板 

// 并查集，优美的类... 

////////////////////////////////////////////////////
//              并查集模板(UFS) v1.2              //
////////////////////////////////////////////////////
//                                                //
// 1. SZ:         并查集最大元素总数(模板参数);   //
// 2. make_set:   初始化 N 个元素的并查集;        //
// 3. find_set:   检查两个元素是否共集;           //
// 4. union_set:  合并两个集合;                   // 
// 5. get_sets:   返回并查集子集的个数;           //
// 6. set_size:   返回元素所在子集的大小;         //
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


#include <cstdio>
#include <cstring>

UFS<100000> U;

int     M,  N,  x,  y,  t;

char    OP[2];    

int main() {
    
    t = 0;
    
    while( scanf( "%d%d", &M, &N ) != EOF ) {
        
        if( t++ )   puts( "" );
        printf( "Case %d:\n", t );
        
        U.make_set( M );
        
        while( N-- ) {
        
            scanf( "%s", OP );
        
            if( *OP == 'M' ) {
                scanf( "%d%d", &x, &y );
                U.union_set( x, y );
            }
            
            else {
                scanf( "%d", &x );
                printf( "%d\n", U.get_size( x ) );
            }
            
        }
        
    }
    
}
