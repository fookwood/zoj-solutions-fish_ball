#include <cstdio>
#include <cmath>

int main() {
	double	D,	V;
	const	double	PI = 3.141592654;
	while( scanf( "%lf%lf", &D, &V ) && D && V )
		printf( "%.3lf\n", pow( D * D * D - 6. * V / PI, 1. / 3. ) );
} 
