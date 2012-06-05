// BFS 注意标记的次序，应该是在弹出之后标记，不然会丢失档案 

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

struct Point {
	Point() {}
	Point( int x, int y, int s, bool b ) : 
		X(x), Y(y), step(s), bomb(b) {}
	int	X,	Y;
	bool	bomb;
	int	step;
};

int	M,	N,	T;
char	A[10][11];

bool isValid( int x, int y ) {
	if( x < 0 || x >= M ) return false;
	if( y < 0 || y >= N ) return false;
	if( A[x][y] == '#' )  return false;
	return true;
}

int main() {
	deque<Point>	Q;
	cin >> T;
	for( int t = 1; t <= T; t++ ) {
		cin >> M >> N;
		getchar();
		for( int i = 0; i < M; i++ )	gets( A[i] );
		cout << "Mission #" << t << ":\n";
		int	sX,	sY,	sT;
		bool	bB;
		for( int i = 0; i < M; i++ ) {
			for( int j = 0; j < N; j++ ) {
				if( A[i][j] == 'S' ) {
					sX = i;
					sY = j;
				}
			}
		}
		Q.resize( 0 );
		Q.push_back( Point( sX, sY, 0, false ) );
		int	count1 = 0,	count2 = 0,	total;
		bool	end = false;
		while( Q.size() ) {
			if( end && Q.front().step != total ) break;
			sX = Q.front().X;
			sY = Q.front().Y;
			sT = Q.front().step;
			bB = Q.front().bomb;
			Q.pop_front();
			if( A[sX][sY] == 'T' ) {
				if( !end ) {
					end = true;
					total = sT;
				}
				if( bB ) count1++;
				else     count2++;
			}
			else	A[sX][sY] = '#';
			if( isValid( sX - 1, sY ) )
				Q.push_back( Point( sX - 1, sY, sT + 1, bB || A[sX - 1][sY] == 'M' ) );
			if( isValid( sX + 1, sY ) )
				Q.push_back( Point( sX + 1, sY, sT + 1, bB || A[sX + 1][sY] == 'M' ) );
			if( isValid( sX, sY - 1 ) )
				Q.push_back( Point( sX, sY - 1, sT + 1, bB || A[sX][sY - 1] == 'M' ) );
			if( isValid( sX, sY + 1 ) )
				Q.push_back( Point( sX, sY + 1, sT + 1, bB || A[sX][sY + 1] == 'M' ) );
		}
		if( count2 == 0 )	cout << "Mission Impossible.\n";
		else {
			cout << "The probability for the spy to get to the telegraph transmitter is ";
			cout.setf( ios :: fixed );
			cout.precision( 2 );
			cout << float( count2 ) / float ( count1 + count2 ) * 100. << "%.\n";
		}
		cout << endl;
	}
}
