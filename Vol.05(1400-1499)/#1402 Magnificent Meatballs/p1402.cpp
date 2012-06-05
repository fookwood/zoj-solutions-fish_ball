#include <cstdio> 

int main() {
	int	A[31],	N;
	while( scanf( "%d", &N ) != EOF ) {
		if( !N ) break;
		int	s = 0, s1 = 0; 
		for( int i = 1; i <= N; i++ ) {
			scanf( "%d", A + i );
			s += A[i];
		}
		int k = 1;
		for( ; s1 + s1 < s; k++ ) s1 += A[k];
		if( s1 + s1 == s ) 
			printf( "Sam stops at position %d and Ella stops at position %d.\n", k - 1, k );
		else	printf( "No equal partitioning.\n" ); 
	} 
} 
