// 好好恶心啊，不用 double 还不让过 

#include <cstdio>
#include <cmath>

int main() {
	double	n,	x,	y;
	while( scanf( "%lf", &n ) != EOF ) {
		if( !n ) {
			puts( "1" );
			continue;
		}
		x = n * log10( n );
		printf( "%d\n", int( pow( 10, ( x - int( x ) ) ) ) );
	}
}
