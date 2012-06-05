// 我的第一道DP题
// DP + 记忆化搜索 

#include <cstdio>

int	b[100][100],	a[100][100];
bool	status[100][100]; 
int	n,	k;

void MFDP( int x, int y ) {
	int	max = 0; 
	for( int i = x - k; i <= x + k; i++ ) {
		if( 	i < 0 || i >= n ||
			i == x || b[i][y] <= b[x][y] )
			continue;
		if( !status[i][y] )	MFDP( i, y );
		if( a[i][y] > max )	max = a[i][y]; 
	}
	for( int j = y - k; j <= y + k; j++ ) {
		if( 	j < 0 || j >= n ||
			j == y || b[x][j] <= b[x][y] )
			continue;
		if( !status[x][j] )	MFDP( x, j );
		if( a[x][j] > max )	max = a[x][j];
	}
	a[x][y] += max;
	status[x][y] = true; 
} 

int main() {
	while( scanf( "%d%d", &n, &k ) != EOF ) {
		if( n == -1 && k == -1 ) break;
		for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ ) {
			scanf( "%d", &a[i][j] );
			b[i][j] = a[i][j];
			status[i][j] = false; 
		}
		MFDP( 0, 0 );
		printf( "%d\n", a[0][0] );
	} 
} 
