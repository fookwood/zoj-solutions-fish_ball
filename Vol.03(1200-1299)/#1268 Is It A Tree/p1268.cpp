// 这题要太阳了...
// 网上找到的很多算法都是扯淡
// 其实就是这样：每输入一条边，将其指向的节点标记 
// 如果已经标记过，不是树 
// 同时标记出现过的顶点数，以及所有的边数 
// 如果在标记被指向点的时候已经否决过就不是树 
// 否则，当顶点数等于边数加一的时候就是树 
// 想不到...居然让下面写的无意义边界数据整了 
// 连并查集都没用到，时间 O(E)，空间 3 * O(V)

/*  Special Test Case

    Input:
        
    0 0
    -1 -1
    
    Output:
        
    Case 1 is a tree.
    
*/

// 2821991 2008-04-03 23:22:57 Accepted 1268 C++ 00:00.00 392K 呆滞的慢板 

#include <cstdio>
#include <cstring>

int main() {
    bool    B[1001];
    bool    C[1001];
    int     v1, v2, T = 1;
    while( scanf( "%d%d", &v1, &v2 ) && ( v1 != -1 || v2 != -1 ) ) {
        memset( B, 0, sizeof( B ) );
        memset( C, 0, sizeof( C ) );
        bool    tree = true;
        // 记录边数，顶点数 
        int     edge = 0,   vertex = 0;
        if( v1 || v2 ) while( 1 ) {
            if( tree ) {
                edge++;
                if( v1 == v2 )  tree == false;
                if( !B[v1] )    { vertex++; B[v1] = true; }
                if( !B[v2] )    { vertex++; B[v2] = true; }
                if( !C[v2] )    C[v2] = true;
                else            tree = false;
            }
            scanf( "%d%d", &v1, &v2 );
            if( !v1 && !v2 )    break;
        }
        tree = !edge || tree && vertex == edge + 1;
        printf( "Case %d is ", T++ );
        puts( tree ? "a tree." : "not a tree." );
    }
}
