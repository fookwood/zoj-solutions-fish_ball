// 测试数据非常大，我估计全部 1~500001 都有测试
// 因此必须事先以高效率生成所有结果，否则绝对 TLE 
// 有类似的题 2286 ，可参见该题解题报告
// 2875858 2008-04-28 09:59:13 Accepted 2095 C++ 00:00.91 2348K 呆滞的慢板 

#include <cstdio>

int main() {
    
    int B[500001] = { 0, 0 };
    
    for( int i = 2; i < 500001; i++ )  B[i] = 1;

    for( int i = 2; i * i < 500001; i++ ) {
        int c = i + 1;
        B[i * i] += i;
        for( int j = i * c; j < 500001; j += i ) {
            B[j] += ( i + c );
            ++c;
        }
    }

    int     T,  N;
    scanf( "%d", &T );

    while( T-- ) {
        scanf( "%d", &N );
        printf( "%d\n", B[N] );
    }
    
}
