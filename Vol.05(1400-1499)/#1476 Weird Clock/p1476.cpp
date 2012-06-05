#include <cstdio> 

int main() {
	int	a,	b;
	while( scanf( "%d%d", &a, &b ) != EOF ) {
		if( !a && !b ) break;
		int i = 1; 
		b++; 
		for( ; i < 60; i++ ) {
			a = a * b % 60; 
			if( a == 0 ) break; 
		} 
		if( i == 60 )
			printf( "Impossible\n" ); 
		else
			printf( "%d\n", i ); 
	} 
} 
