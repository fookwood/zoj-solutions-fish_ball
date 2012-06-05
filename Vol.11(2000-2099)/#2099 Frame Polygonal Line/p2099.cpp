#include <cstdio>

int main() {
	bool	begin = false;
	int	x,	y;
	int	lx,	ux;
	int	ly,	uy; 
	while( scanf( "%d%d", &x, &y ) != EOF ) {
		if( !x && !y ) break;
		lx = ux = x;
		ly = uy = y;
		while( scanf( "%d%d", &x, &y ) != EOF ) {
			if( !x && !y ) break;
			if( x < lx )	lx = x;
			else if( x > ux ) ux = x;
			if( y < ly )	ly = y;
			else if( y > uy ) uy = y;
		}
		printf( "%d %d %d %d\n", lx, ly, ux, uy ); 
	}
} 
