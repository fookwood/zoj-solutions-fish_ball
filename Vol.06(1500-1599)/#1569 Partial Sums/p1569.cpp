// 直接求累加后枚举 TLE 
// 转化成某几项累加同余，计算其 2 组合数，AC 

#include <cstdio>

int main() {
    int     A[10001],   B[5000];
    int     M,  N,   count;
    while( scanf( "%d%d", &N, &M ) != EOF ) {
        A[0] = count = 0;
        B[0] = 1;
        for( int i = 1; i < M; i++ )
            B[i] = 0;
        for( int i = 1; i <= N; i++ ) {
            scanf( "%d", A + i );
            A[i] = ( A[i] + A[i - 1] ) % M;
            B[A[i]]++;
        }
        for( int i = 0; i < M; i++ )
            count += ( B[i] * ( B[i] - 1 ) >> 1 );
        printf( "%d\n", count );
    }
}
