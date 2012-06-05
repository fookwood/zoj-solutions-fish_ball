#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Box {
	int	x,	y,	z;
	Box( int a = 0, int b = 0, int c = 0 ): x(a), y(b), z(c) {} 
}; 

bool operator > ( Box A, Box B ){ return A.x >  B.x; }
bool operator >=( Box A, Box B ){ return A.x >= B.x; }
bool operator < ( Box A, Box B ){ return A.x <  B.x; }
bool operator <=( Box A, Box B ){ return A.x <= B.x; }
bool operator ==( Box A, Box B ){ return A.x == B.x; }
bool operator !=( Box A, Box B ){ return A.x != B.x; } 


int main() {
	vector<Box>	boxSet;
	vector<int>	status; 
	int	T = 1,	N,	a,	b,	c,	max;
	while( cin >> N ) {
		if( !N ) break;
		 
		boxSet.resize( 0 );
		for( int i = 0; i < N; i++ ) {
			cin >> a >> b >> c;
			if( a > b )	boxSet.push_back( Box( a, b, c ) );
			else		boxSet.push_back( Box( b, a, c ) );
			if( a > c )	boxSet.push_back( Box( a, c, b ) );
			else		boxSet.push_back( Box( c, a, b ) );
			if( c > b )	boxSet.push_back( Box( c, b, a ) );
			else		boxSet.push_back( Box( b, c, a ) );
		}
		sort( boxSet.begin(), boxSet.end() );
		max = 0;
		N *= 3; 
		status.resize( N );
		for( int i = 0; i < N; i++ ) {
			int	mx = 0; 
			for( int j = 0; j < i; j++ )
				if( boxSet[i].x > boxSet[j].x &&
				    boxSet[i].y > boxSet[j].y &&
				    status[j] > mx ) 
					mx = status[j];
			status[i] = mx + boxSet[i].z;
			if( status[i] > max ) max = status[i]; 
		}
		cout << "Case " << T++ << ": maximum height = " << max << endl; 
	}
} 
