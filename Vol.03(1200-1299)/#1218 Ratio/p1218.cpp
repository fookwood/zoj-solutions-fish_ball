// 迭代改进思想，贪心算法
// 注意两点，第一点首当其冲精度问题，第二点出现重复的比例要舍去
// 2823271 2008-04-04 19:58:15 Accepted 1218 C++ 00:00.00 392K 呆滞的慢板 

#include <cstdio>
#include <cmath>

const double EPS = 1e-8;

int main() {
    int     M,  N,  T = 0;
    while( scanf( "%d%d", &M, &N ) != EOF ) {
        if( T++ )   putchar( '\n' );
        int     m = ( M > N ) ? M : N;
        int     n = ( M > N ) ? N : M;
        while( n ) {
            int r = m % n;
            m = n;
            n = r;
        }
        M /= m;
        N /= m;
        double  ratio = double( M ) / double( N );
        double  eps = 1e999,    temp = 0;
        for( int denom = 1; denom < N; denom++ ) {
            double  now = ratio * double( denom );
            int     alter = 0;
            if( ceil( now ) / double( denom ) - ratio < eps &&
                fabs( ceil( now ) / double( denom ) - temp ) > EPS ) {
                temp = ceil( now ) / double( denom );
                eps = temp - ratio;
                alter = 1;
            }
            if( ratio - floor( now ) / double( denom ) < eps &&
                fabs( floor( now ) / double( denom ) - temp ) > EPS ) {
                temp = floor( now ) / double( denom );
                eps = ratio - temp;
                alter = 2;
            }
            if( alter == 1 )
                printf( "%d/%d\n", int( ceil( now ) + EPS ), denom );
            if( alter == 2 )
                printf( "%d/%d\n", int( floor( now ) + EPS ), denom );
        }
        printf( "%d/%d\n", M, N );
    }
}
