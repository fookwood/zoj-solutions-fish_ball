#include <cstdio> 
#include <cstring>

int val( char* str, int l ) {
	int	xc = 0,	xg = 0,	xt = 0,	sum = 0;
	for( int i = 0; i < l; i++ ) {
		switch( str[i] ) {
			case 'T': xt++;				break; 
			case 'G': xg++;	sum += xt;		break;
			case 'C': xc++;	sum += ( xg + xt );	break; 
			case 'A': 	sum += ( xg + xt +xc );
		}
	}
	return	sum;
}

int main() {
	int	score[100],	index[100],	T,	N,	L; 
	char	c[100][51];
	char*	d[100];
	scanf( "%d", &T );
	while( T-- ) { 
		scanf( "%d%d", &L, &N );
		for( int i = 0; i < N; i++ ) {
			scanf( "%s", c[i] );
			score[i] = val( c[i], L );
			index[i] = 0; 
			for( int j = 0; j < i; j++ )
				if( score[i] > score[j] )
					index[i]++;
				else	index[j]++;
		}
		for( int i = 0; i < N; i++ )
			d[index[i]] = c[i];
		for( int i = 0; i < N; i++ )
			printf( "%s\n", d[i] );
		if( T )	putchar('\n'); 
	}
} 
