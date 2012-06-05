// 我靠靠靠！！！
// zoj 的数据再次欺骗我的感情！！
// 1 WA，郁闷之际去 poj 看 Forum，有人说 poj 过的 zoj 过不了
// 然后就在 poj submit，结果 AC
// 我靠！然后扩大质数表，在 zoj 也 AC 了
// 无耻的 zoj 数据！！这是第二次了！！上次也是质数表太小害我 WA！！
 
#include <cstdio>
#include <cstring>

int main() {
	// 产生质数表, 1不是质数 
	char	A[40000];
	memset( A, 1, 40000 );
	A[0] = A[1] = 0;
	for( int i = 2; i <= 200; i++ )
		if( A[i] )
			for( int j = i + i; j < 40000; j += i )
				A[j] = 0;
	int	Prime[5000],	top = 0;
	for( int i = 2; i < 40000; i++ )
		if( A[i] ) Prime[top++] = i;
	// 开始，时空权衡+蛮力 
	int	N;
	while( scanf( "%d", &N ) != EOF ) {
		if( !N ) break;
		int	sum = 0;
		int	bnd = ( N + 1 ) / 2;
		for( int i = 0; Prime[i] <= bnd; i++ )
			if( A[N - Prime[i]] )
				sum++;
		printf( "%d\n", sum );
	}
}
