// 数学问题，最后可化归 log(b)/b 与 log(a)/a 的比较
// 可证明 f(x) = log(x) / x 在 (0, e]上单增，在 [e, +inf) 上单减 
// 因此用二分数值算法即可 

#include <cstdio>
#include <cmath>

const double EXP = exp( 1. );
const double EPS = 1e-8;

int main() {
	double	a,	c,	x,	lb,	ub;
	while( scanf( "%lf", &a ) != EOF ) {
		if( a >= EXP ) {
			puts( "-1" );
			continue;
		}
		c = log( a ) / a;
		lb = EXP;
		x = ub = 44.;
		while( ub - lb > EPS ) {
			if( c - log( x ) / x > 0. )		ub = x;
			else					lb = x;
			x = ( ub + lb ) / 2.;
		}
		printf( "%.5lf\n", x );
	}
}
