#include <iostream>
#include <cstdio> 
using namespace std;

int gcd( int M, int N ) {
	if( !N )	return M;
	else 		return gcd( N, M % N ); 
} 

int main() {
	int	M,	N;
	while( cin >> M >> N ) {
		printf( "%10d%10d", M, N );
		if( M < N ) {
			int	temp = M;
			M = N;
			N = temp; 
		} 
		if( gcd( M, N ) == 1 )
			cout << "    Good Choice\n\n";
		else
			cout << "    Bad Choice\n\n";
	} 
} 
