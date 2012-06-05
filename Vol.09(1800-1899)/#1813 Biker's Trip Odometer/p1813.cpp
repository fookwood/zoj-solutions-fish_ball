#include <cstdio>

int main() {
	float	d,	r,	t;
	const float	PI = 3.1415927;
	int	trip = 1; 
	while( scanf( "%f%f%f", &d, &r, &t ) != EOF ) {
		if( !r ) break;
		float	s = r * PI * d / 12. / 5280.;
		float	v = s / t * 3600.; 
		printf( "Trip #%d: %0.2f %0.2f\n", trip++, s, v );
	} 
} 
