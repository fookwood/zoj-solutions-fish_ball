// 注意触发的先后次序，因此只能用 BFS 直接递归是 DFS 会 WA 
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std; 

char	grid[500][501];
int	M,	N;

struct oper {
	oper() {}
	oper( int a, int b, char d ) : x( a ), y( b ), c( d ) {}
	int	x,	y;
	char	c;
};

deque<oper>	Force;
void knockDown( int, int, char );

int main() {
	int	X,	Y,	T = 0;
	char	input[2];
	while( scanf( "%d%d", &M, &N ) != EOF ) {
		if( T++ ) putchar( '\n' );
		for( int i = 0; i < M; i++ )
			scanf( "%s", grid[i] );
		scanf( "%d%d%s", &X, &Y, input );
		Force.resize( 0 );
		Force.push_back( oper( X - 1, Y - 1, *input ) );
		while( !Force.empty() ) {
			knockDown( Force[0].x, Force[0].y, Force[0].c );
			Force.pop_front();
		}
		for( int i = 0; i < M; i++ )
			printf( "%s\n", grid[i] );
	}
}

void knockDown( int x, int y, char c ) {
	if( x < 0 || x >= M || y < 0 || y >= N || grid[x][y] != 'X' )	return;
	grid[x][y] = c;
	switch( c ) {
		case 'E': Force.push_back( oper( x - 1, y + 1, 'Y' ) );
			  Force.push_back( oper( x    , y + 1, 'E' ) );
			  Force.push_back( oper( x + 1, y + 1, 'Q' ) );
		break;
		case 'Y': Force.push_back( oper( x - 1, y + 1, 'Y' ) );
			  Force.push_back( oper( x    , y + 1, 'E' ) );
			  Force.push_back( oper( x - 1, y    , 'N' ) );
		break;
		case 'Q': Force.push_back( oper( x + 1, y    , 'S' ) );
			  Force.push_back( oper( x    , y + 1, 'E' ) );
			  Force.push_back( oper( x + 1, y + 1, 'Q' ) );
		break;
		case 'S': Force.push_back( oper( x + 1, y    , 'S' ) );
			  Force.push_back( oper( x + 1, y - 1, 'J' ) );
			  Force.push_back( oper( x + 1, y + 1, 'Q' ) );
		break;
		case 'J': Force.push_back( oper( x + 1, y - 1, 'J' ) );
			  Force.push_back( oper( x    , y - 1, 'W' ) );
			  Force.push_back( oper( x + 1, y    , 'S' ) );
		break;
		case 'W': Force.push_back( oper( x - 1, y - 1, 'V' ) );
			  Force.push_back( oper( x    , y - 1, 'W' ) );
			  Force.push_back( oper( x + 1, y - 1, 'J' ) );
		break;
		case 'V': Force.push_back( oper( x - 1, y - 1, 'V' ) );
			  Force.push_back( oper( x    , y - 1, 'W' ) );
			  Force.push_back( oper( x - 1, y    , 'N' ) );
		break;
		case 'N': Force.push_back( oper( x - 1, y    , 'N' ) );
			  Force.push_back( oper( x - 1, y - 1, 'V' ) );
			  Force.push_back( oper( x - 1, y + 1, 'Y' ) );
	}
}
