// DFS
// TLE

#include <cstring>
#include <cstdio> 

void DFS( float D[30][30],
          int V, int* stk, 
          int &top, float &loop, int n ) {
    
	for( int i = 0; i < V; i++ ) {
	
    	if( D[n][i] > 0. ) {
	
    		int j = 0; 
	
    		for( ; j <= top; j++ ) {
				if( stk[j] == i ) {
					float	temp = D[n][i];
					for( int k = j; k < top; k++ )
						temp *= D[stk[k]][stk[k + 1]];
					if( temp > loop ) loop = temp;
					break; 
				}
			}
	
    		if( j == top + 1 ) {
				stk[++top] = i;
				DFS( D, V, stk, top, loop, i );
				top--; 
			}
	
    	}
	}
} 

int main() {
	int	V,	E,	T = 1;
	char	A[30][100],	s1[100],	s2[100];
	float	x,	loop,	D[30][30];
	int	top,	stk[30];
	while( scanf( "%d", &V ) ) {
		if( !V ) break; 
		for( int i = 0; i < V; i++ ) {
			scanf( "%s", A[i] );
			for( int j = 0; j < V; j++ )
				D[i][j] = 0.; 
		}
		scanf( "%d", &E );
		for( int i = 0; i < E; i++ ) {
			scanf( "%s%f%s", s1, &x, s2 );
			int	j = 0,	k = 0;
			while( 1 ) 	if( strlen(A[j]) == strlen(s1) && !strcmp( A[j], s1 ) ) break;
					else j++; 
			while( 1 ) 	if( strlen(A[k]) == strlen(s2) && !strcmp( A[k], s2 ) ) break;
					else k++; 
			D[j][k] = x; 
		}
		loop = 0.;
		top = 0; 
		stk[0] = 0; 
		DFS( D, V, stk, top, loop, 0 );
		printf( "Case %d", T++ ); 
		if( loop > 1. ) printf( ": Yes\n" );
		else		printf( ": No\n" ); 
	}
} 

