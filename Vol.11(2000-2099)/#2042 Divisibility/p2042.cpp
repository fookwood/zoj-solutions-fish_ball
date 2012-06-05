// DP, O(N*K),用 iostream 会超时 
// 输入的数全部对 K 求余，然后 
// 做一个 K 位的 bool 表 A，代表在第 n 个数之后有没有能到达这个数位的
// 在做一个 K 位的 bool 表 B，每输入一个数，求余，然后遍历 A
// 如果 A 的某位已经占有，将该位 加/减 新输入的数后能到达的状态在 B 标记
// 然后将 B 复制到 A
// 最后如果 A 在 0 处为 true，则 Divisible
// 2845273 2008-04-15 15:57:30 Accepted 2042 C++ 00:00.40 396K 呆滞的慢板  

#include <cstring>
#include <cstdio>

int main() {
    int     T,  N,  K,  temp;
    bool    A[100], B[100];
    scanf( "%d", &T ); 
    while( T-- ) {
        scanf( "%d%d", &N, &K );
        memset( A, 0, sizeof( A ) );
        A[0] = true;
        for( int i = 0; i < N; i++ ) {
            memset( B, 0, sizeof( B ) );
            scanf( "%d", &temp ); 
            if( temp > 0 )  temp %= K;
            else    temp = -temp % K;
            for( int i = 0; i < K; i++ ) {
                if( A[i] ) {
                    B[(i+temp)%K] = true;
                    B[(i+K-temp)%K] = true;
                }
            }
            memcpy( A, B, sizeof( B ) );
        }
        if( A[0] )  puts( "Divisible" );
        else        puts( "Not divisible" );
        if( T ) puts( "" );
    }
}
