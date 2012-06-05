#include <cstdio>

int main() {
	float	prev,	now;
	int	T = 0; 
	while( scanf( "%f", &now ) != EOF ) {
		if( now == 999 ) {
			printf( "End of Output\n" ); 
			break;
		}
		if( T++ )	printf( "%0.2f\n", now - prev );
		prev = now; 
	}
}  
