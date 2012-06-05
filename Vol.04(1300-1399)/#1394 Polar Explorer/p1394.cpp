#include <cstdio> 

int main() {
	char	c[11];
	const float	PI = 3.14159; 
	float	x,	y,	z; 
	while( scanf( "%s", c ) ) {
		if( *c == 'E' ) break;
		scanf( "%f%f%f%s", &x, &y, &z, c );
		if( z > 180 ) z = 360 - z; 
		x *= ( z * PI / 450. );
		if( y >= x )	printf( "YES %d\n", int(y - x) );
		else		printf( "NO %d\n", int(5. * y) );
	} 
} 
