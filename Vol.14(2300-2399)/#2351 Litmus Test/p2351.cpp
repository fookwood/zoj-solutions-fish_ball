// XXXX很邪恶的题，题意超难懂
// 看了很久才知道原来是这样：
// 对于任意一种酸，它放到水里总是有一部分溶化（变成H+），有一部分不溶（没有H+）
// 假设溶化的酸根数是[acid ions]，不溶的酸是[acid]， 
// 那么记Ka = [H+][acid ions]/[acid];
// 其中[H+]表示在[acid ions]这么多酸里面有多少个[H+]
// 因为Ka是固定的，那么如果溶液的酸百分比是a*100%
// 则1(L)的溶液会有a(mol)的酸分子，而设这里面有x(mol)酸被溶解
// 假设1个溶解的酸分子含m个[H+]及n个酸根分子，于是：
// [H+] = x*m 
// [acid ions] = x*n
// [acid] = a - x
// 于是我们得出公式:
// Ka = ( x * x * n * m ) / ( a - x )
// 我们要求的是[H+]，因此应该换成t[H+] = x*m，得到
// Ka = ( t * t * n / m ) / ( a - t / m ) 
// 倒腾一下公式，得到：
// n * t * t + Ka * t - Ka * m * a = 0
// 代入二次方程求根公式解 t 
// t = ( sqrt( Ka * Ka + 4. * n * Ka * m * a ) - Ka ) / 2. / n 
// 而结果是 - log10(t) 

#include <cstdio>
#include <cmath>

int main() {
	int	T;
	scanf( "%d", &T ); 
	while( T-- ) {
		double	Ka, a, m, n;
		while( 1 ) {
			scanf( "%lf%lf%lf%lf", &Ka, &a, &m, &n );
			if( Ka == 0 && a == 0 && m == 0 && n == 0 )
				break;
			printf( "%.3lf\n", -log10( ( sqrt( Ka * Ka + 4. * n * Ka * m * a ) - Ka ) / 2. / n ) );
		}
		if( T ) putchar( '\n' ); 
	} 
} 
