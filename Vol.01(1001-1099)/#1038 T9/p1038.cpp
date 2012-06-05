// 8-tree!!
// Simulate!!
// Coding Tree Algorithm!!
// Similar to Huffman!!
// 这么漂亮的算法居然 WA 不让过 -_-|
// 最后还是靠poj各位大牛给的数据找到了问题，AC了 
// 原来，复杂也是一种错 

#include <cstdio>
#include <cstring>

/*************** 常量 ***************/
// 字母译数字译码表，对应编码树的儿子的编号 
const char code[26] = { 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 
		                3, 3, 4, 4, 4, 5, 5, 5, 5, 6,
                        6, 6, 7, 7, 7, 7 }; 

/*************** 类定义 ***************/
// 编码树结构 
struct Tree {
    // 该节点的字符串(引用)
    char*   word;
    // 发生概率
    int     prob;
    // 下属指针(共8个，对应2~9个按键)
    Tree*   son[8]; 
};
// 清空指定树结点的内容，并标记为叶子 
inline void clear( Tree* root ) {
    memset( root, 0, sizeof( Tree ) );
}
// 销毁根为 root 的编码树 
void destroy( Tree* root ) {
    if( root ) {
        destroy( root -> son[0] );
        destroy( root -> son[1] );
        destroy( root -> son[2] );
        destroy( root -> son[3] );
        destroy( root -> son[4] );
        destroy( root -> son[5] );
        destroy( root -> son[6] );
        destroy( root -> son[7] );
        delete    root;
    }
}
// 向编码树结点插入单个字符串 
void insert( Tree* root, char* s, int p, char c ) {
    if( !( root -> son[code[c - 'a']] ) ) {
        root -> son[code[c - 'a']] = new Tree;
        root = root -> son[code[c - 'a']];
        clear( root );
    }
    else if( ( root -> son[code[c - 'a']] -> prob ) >= p )    return;
    else    root = root -> son[code[c - 'a']];
        root -> word = s; 
        root -> prob = p;
} 
 
/*************** 变量 ***************/
// 存放实际字串表 
char    C[1001][101],    P[1000],    Q[1000];
// 字符串的升序索引 
int     idx[1000];
char*   D[1001];

// 用现有的字符串表建树 
void build( Tree* root, int x1, int x2, int t ) {
    int    x = x1,    p = 0;
    char    c = D[x1][t];
    while( 1 ) {
        if( x > x2 ) break;
        bool    match = true; 
        for( int i = 0; i <= t; i++ ) {
            if( D[x1][i] != D[x + 1][i] ) {
                match = false;
                break; 
            }
        }
        if( !match ) break;
        x++;
    } 
    for( int i = x1; i <= x; i++ )    p += P[i];
    insert( root, D[x1], p, c );
    // 向后深入
    if( D[x1][t + 1] )
        build( root -> son[code[c - 'a']], x1, x, t + 1 );
    else if( x1 < x2 && D[x1 + 1][t + 1] )
        build( root -> son[code[c - 'a']], x1 + 1, x, t + 1 );
    // 向下深入
    if( x < x2 )
        build( root, x + 1, x2, t );
}

int main() {
    // 编码树的根 
    Tree*    root = NULL;
    int    T,    N;
    scanf( "%d", &T );
    for( int t = 0; t < T; t++ ) {
        printf( "Scenario #%d:\n", t + 1 ); 
        // 对于每个档案开头清空编码树一次 
        destroy( root );
        root = new Tree;
        clear( root );
        // 清空字符表及索引表 
        memset( C, 0, 101101 ); 
        memset( idx, 0, 1001 * sizeof( int ) );
        scanf( "%d", &N );
        // 输入字符串表以及概率表，并对索引做计数排序 
        for( int n = 0; n < N; n++ ) {
            scanf( "%s%d", C[n], &Q[n] );
            for( int m = 0; m < n; m++ )
                if( strcmp( C[n], C[m] ) >= 0 )    idx[n]++;
                else                idx[m]++;
        }
        // 按照索引排序字符串 
        for( int n = 0; n < N; n++ ) {
            D[idx[n]] = C[n];
            P[idx[n]] = Q[n];
        } 
        // 哨兵(Sentinel)，防止建树时越界比较 
        memset( C[N], '~', 101 ); 
        D[N] = C[N]; 
        // 建树 
        if( N ) build( root, 0, N - 1, 0 );
        // 查询 
        int    M;
        scanf( "%d", &M );
        while( M-- ) {
            char    check[101];
            scanf( "%s", check );
            if( !N ) {
                for( unsigned int i = 0; i < strlen( check ) - 1; i++ )
                    printf( "MANUALLY\n" );
                putchar( '\n' );
                continue; 
            }
            Tree*    v = root;
            for( int i = 0; check[i] != '1'; i++ ) {
                if( v )    v = v -> son[check[i] - '2'];
                if( v ) for( int j = 0; j <= i; j++ )
                    putchar( v -> word[j] );
                else    printf( "MANUALLY" );
                putchar( '\n' );
            }
            putchar( '\n' );
        }
        putchar( '\n' ); 
    }
} 
