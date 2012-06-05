#include <cstdio>
#include <cstring> 

int main() {
	int	x,	y,	z,	N,	max,	min;
	char	bully[9], temp[9], victim[9]; 
	while( scanf( "%d", &N ) != EOF ) {
		if( N == -1 ) break;
		max = 0;
		min = 10000; 
		while( N-- ) {
			scanf( "%d%d%d%s", &x, &y, &z, temp );
			int	p = x * y * z;
			if( p > max ) {
				max = p;
				strcpy( bully, temp ); 
			} 
			if( p < min ) {
				min = p;
				strcpy( victim, temp ); 
			} 
		} 
		printf( "%s took clay from %s.\n", bully, victim ); 
	} 
} 
