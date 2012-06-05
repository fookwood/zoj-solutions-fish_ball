// 等价于求最长上升子序列，DP 
// 平凡算法，O(n^2) TLE 

#include <cstdio>

int main() {
    int     A[40000],   B[40000],   P,  T;
    scanf( "%d", &T );
    while( T-- ) {
        scanf( "%d", &P );
        for( int i = 0; i < P; i++ )
            scanf( "%d", A + i );
        int     max = 0;
        for( int i = 0; i < P; i++ ) {
            int     m = 0;
            for( int j = 1; j < i; j++ )
                if( A[j] < A[i] && B[j] > m )
                    m = B[j];
            B[i] = m + 1;
            if( B[i] > max )
                max = B[i];
        }
        printf( "%d\n", max );
    }
}
