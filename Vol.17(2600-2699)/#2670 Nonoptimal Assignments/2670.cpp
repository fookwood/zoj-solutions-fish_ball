// 很特别的一道题，也很简单，我的方法是按如下规律输出，注意 N = 2 的情况
/* 0 0 0 0 1
   0 0 0 1 2
   0 0 1 2 3
   0 1 2 3 4
   1 2 3 4 5
*/ 
 
#include <cstdio>

int main() {
	int	N;
	while( scanf( "%d", &N ) != EOF ) {
		if( N == 2 ) {
			printf( "0 1\n1 10\n\n" );
			continue;
		}
		for( int i = 1; i <= N; i++ ) {
			for( int j = i + 1; j <= N; j++ ) printf( "0 " );
			for( int j = 1; j <= i; j++ )     printf( "%d ", j );
			putchar( '\n' );
		}
	}
}
