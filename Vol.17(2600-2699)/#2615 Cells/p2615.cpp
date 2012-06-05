// 2950897 2008-06-16 14:21:12 Accepted 2615 C++ 00:02.01 237312K 呆滞的慢板 

// DFS 时间戳，cp 大牛教的，可以 O(1) 判别有根树两个节点是否有祖先关系
// 然后，这道题无论是时间还是空间，卡得都非常紧
// 图的储存用如下方式（只需要能做一次 DFS 得到时间戳即可）： 
// 对于前面 N 个节点，记录它的儿子数 cnt[n]，以及第一个儿子的序号 child[n] 
// 那么，他的儿子就是 child[n], child[n] + 1 ... child[n] + cnt[n] - 1
// 这样就可以用 2 * N 的内存储存树，可以用一次 DFS 得到结果了

// 另外，数据太大，直接递归 DFS 是会栈溢出的，因此要自己用个数组当栈来 DFS
// 这个数组记录当前的节点即可，然后往下搜可以破坏 child 和 stk 来进行，节省空间 
// DFS 的时候，用一个 tm 记录时间，每压栈或退栈 1 个，tm 都加一 
// 这样，每 DFS 到一个点，记录进入时间 in ，弹出的时候记录退出时间 out 
// 于是，X 是 Y 的充要条件就是：
// X 比 Y 早进入，而比 Y 晚退出。 

#include <cstdio>

int     in[20010000],   out[20010000];
int     child[310000],  cnt[310000];
int     stk[20010000],  top;

int main() {

    int     T,  N,  K;

    scanf( "%d", &T );
    
    for( int t = 1; t <= T; ++t ) {
        
        scanf( "%d", &N );
        
        for( int i = K = 0; i < N; ++i ) {
            scanf( "%d", cnt + i );
            child[i] = K;
            K += cnt[i];
        }

        int     tm = 0, temp;
        stk[top = 0] = 0;
        in[0] = tm++;

        while( top >= 0 ) {
            if( stk[top] >= N || cnt[stk[top]] <= 0 )
                out[stk[top--]] = tm++;
            else {
                temp = child[stk[top]] + cnt[stk[top]]--;
                in[temp] = tm++;
                stk[++top] = temp;
            }
        }

        if( t > 1 ) putchar( '\n' );
        printf( "Case %d:\n", t );

        int     Q,  X,  Y;
        for( scanf( "%d", &Q ); Q--; ) {
            scanf( "%d%d", &X, &Y );
            if( in[X] < in[Y] &&
                out[X] > out[Y] )
                puts( "Yes" );
            else
                puts( "No" );
        }   
        
    }

}
