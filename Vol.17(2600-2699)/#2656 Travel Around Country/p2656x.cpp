// 改良版，还是那么慢，越来越佩服上榜的人了 
// 1.83s 392K 1AC

#include <cstdio>

int main() {
	int	N,	x1,	x2;
	int	fuel[2],	city;
	while( scanf( "%d", &N ) != EOF ) {
		fuel[0] = fuel[1] = city = 0;
		for( int i = 0; i < N; i++ ) {
			scanf( "%d%d", &x1, &x2 );
			fuel[1] += ( x1 - x2 );
			if( fuel[1] < 0 ) {
				fuel[0] += fuel[1]; 
				fuel[1] = 0; 
				city = i + 1;
			}
		}
		if( fuel[0] + fuel[1] < 0 ) 
			printf( "impossible\n" );
		else	printf( "%d\n", city );
	}
}
