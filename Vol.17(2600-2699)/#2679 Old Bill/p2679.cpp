// 直接蛮力穷举也就是 O(90)

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

int main() {
	int	T,	N;
	char	X[2],	Y[2],	Z[2],	num[6];
	scanf( "%d", &T );
	while( T-- ) {
		scanf( "%d%s%s%s", &N, X, Y, Z );
		num[1] = *X;
		num[2] = *Y;
		num[3] = *Z;
		num[5] = '\0';
		bool	found = false;
		for( num[0] = '9'; num[0] > '0'; num[0]-- ) {
			for( num[4] = '9'; num[4] >= '0'; num[4]-- ) {
				int	temp = atoi( num );
				if( temp % N == 0 ) {
					found = true;
					printf( "%c %c %d\n", num[0], num[4], temp / N );
					break;
				}
			}
			if( found )	break;
		}
		if( !found )	puts( "0" );
	}
}
