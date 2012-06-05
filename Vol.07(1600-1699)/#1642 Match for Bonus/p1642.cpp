// LCS 最长公共子串问题，DP
// 注意大容量的数组块最好在全局范围定义，如果局部定义
// 则为其在栈上分配内存，导致错误。
// 2882503 2008-05-01 15:16:19 Accepted 1642 C++ 00:00.27 16044K 呆滞的慢板  

#include <cstdio>
#include <cstring>

inline int max( const int& x, const int& y ) {
    return  x > y ? x : y;
}

int     DP[2001][2001], S[256];
char    s1[2001],   s2[2001],   in[2];
int     L1, L2, N;

int main() {
    
    while( scanf( "%d", &N ) != EOF ) {

        memset( S, 0, sizeof( S ) );
        while( N-- ) {
            scanf( "%s", in );
            scanf( "%d", S + *in );
        }
        
        scanf( "%s%s", s1, s2 );
        L1 = strlen( s1 );
        L2 = strlen( s2 );
        
        memset( DP, 0, sizeof( DP ) );

        for( int i = 0; i < L1; ++i ) {
            for( int j = 0; j < L2; ++j ) {
                DP[i+1][j+1] = max( DP[i][j+1], DP[i+1][j] );
                if( s1[i] == s2[j] )
                    DP[i+1][j+1] = max( DP[i+1][j+1], S[s1[i]] + DP[i][j] );
            }
        }
        
        printf( "%d\n", DP[L1][L2] );

    }
    
}
