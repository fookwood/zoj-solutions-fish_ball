// 3009389 2008-07-27 20:56:53 Accepted 1319 C++ 00:01.41 672K 呆滞的慢板 

//     把box的内容按照输入的顺序存放到array中。我们看到u(N)就是GET操作，
// 相当于在array的前u(N) 个元素中找i-minimum元素。如果array的前u(N)个元
// 素按递增排序好了，那么只要取array[i]就行了。
//     现在的关键是提高排序的速度。假设u(k)的时候，array[0] .... array[u(k)-1]
// 已经排好序，那么只要先对array[u(k)] ... array[u(k+1)-1]排序，再把二
// 者合并起来就行了。C++ STL提供了所有的功能，sort和merge函数可以直接拿来用。

// 很低效，放北大就过不了了 

#include <cstdio>
#include <algorithm>
using namespace std;

int A[60002],   *V = A, *W = A + 30001;

int T,  N,  Q,  P,  X,  Y;

int main() {
    
    for( scanf( "%d", &T ); T--; ) {

        scanf( "%d%d", &N, &Q );

        for( int i = 0; i < N; ++i )
            scanf( "%d", V + i );
        copy( V, V + N, W );
        
        for( int q = X = P = 0; q < Q; ++q ) {
            scanf( "%d", &Y );
            if( Y > X ) {
                sort( V + X, V + Y );
                merge( V, V + X, V + X, V + Y, W );
                swap( V, W );
                X = Y;
            }
            printf( "%d\n", V[P++] );
        }

        if( T ) puts( "" );

    }

}
