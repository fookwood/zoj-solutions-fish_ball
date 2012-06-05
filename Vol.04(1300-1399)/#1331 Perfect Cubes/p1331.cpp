// Combination set achieve
#include <stdio.h>

int main() {
	int	a,	b,	c,	d;
	for( int a = 1; a <= 200; a++ ) {
		int	x = a * a * a;
		for( int b = 2; b < a; b++ ) {
			int	y = b * b * b;
			if( y >= x ) continue;
			for( int c = b; c < a; c++ ) {
				int z = y + c * c * c;
				if( z >= x ) continue;
				for( int d = c; d < a; d++ ) {
					int r = z + d * d * d;
					if( r == x )
						printf( "Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d );
					if( r >= x )	break;
				}
			}
		}
	}
} 
