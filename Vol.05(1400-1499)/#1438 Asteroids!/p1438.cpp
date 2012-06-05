#include <iostream>
#include <deque>
using namespace std;

struct Point {
	Point() {}
	Point( int x, int y, int z, int l ) : X(x), Y(y), Z(z), L(l) {}
	int	X,	Y,	Z,	L;
};

int	N;
char	A[10][10][11];

bool isValid( int x, int y, int z ) {
	if( x < 0 || x >= N ) return false;
	if( y < 0 || y >= N ) return false;
	if( z < 0 || z >= N ) return false;
	return	A[z][y][x] == 'O';
}

int main() {
	int	x,	y,	z,	p,	q,	r,	l;
	string	s;
	deque<Point>	BFS;
	while( cin >> s >> N ) {
		for( int i = 0; i < N; i++ )
			for( int j = 0 ; j < N; j++ )
				cin >> A[i][j];
		cin >> x >> y >> z;
		BFS.resize( 0 );
		BFS.push_back( Point( x, y, z, 0 ) );
		A[z][y][x] = 'X';
		cin >> x >> y >> z >> s;
		bool	success = false;
		while( BFS.size() ) {
			p = BFS.front().X;
			q = BFS.front().Y;
			r = BFS.front().Z;
			l = BFS.front().L;
			BFS.pop_front();
			if( p == x && q == y && r == z ) {
				cout << N << ' ' << l << endl;
				success = true;
				break;
			}
			if( isValid( p - 1, q, r ) ) {
				BFS.push_back( Point( p - 1, q, r, l + 1 ) );
				A[r][q][p - 1] = 'X';
			}
			if( isValid( p + 1, q, r ) ) {
				BFS.push_back( Point( p + 1, q, r, l + 1 ) );
				A[r][q][p + 1] = 'X';
			}
			if( isValid( p, q - 1, r ) ) {
				BFS.push_back( Point( p, q - 1, r, l + 1 ) );
				A[r][q - 1][p] = 'X';
			}
			if( isValid( p, q + 1, r ) ) {
				BFS.push_back( Point( p, q + 1, r, l + 1 ) );
				A[r][q + 1][p] = 'X';
			}
			if( isValid( p, q, r - 1 ) ) {
				BFS.push_back( Point( p, q, r - 1, l + 1 ) );
				A[r - 1][q][p] = 'X';
			}
			if( isValid( p, q, r + 1 ) ) {
				BFS.push_back( Point( p, q, r + 1, l + 1 ) );
				A[r + 1][q][p] = 'X';
			}
		}
		if( !success )	puts( "NO ROUTE" );
	}
}
