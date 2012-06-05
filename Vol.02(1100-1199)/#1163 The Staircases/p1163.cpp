// 2872357 2008-04-26 20:04:57 Accepted 1163 C++ 00:00.18 2796K 呆滞的慢板 
// DP 即可，但我用的是记忆化搜索 

#include <iostream>
using namespace std;

long long	A[501][501];

long long fun( const int& x, const int& y ) {

    if( x <= y )           return A[x][y] = 0ll;
    if( x < y + y + 3 )    return A[x][y] = 1ll;
    if( A[x][y] >= 0 )     return A[x][y];
    
    A[x][y] = 1ll;
    for( int i = y + 1; i <= x / 2; i++ )
		A[x][y] += fun( x - i, i );

	return	A[x][y];

}

int main() {

    int	N;

    for( int i = 0; i < 501; i++ )
		for( int j = 0; j < 501; j++ )
			A[i][j] = -1ll;

	while( ( cin >> N ) && N ) {

		long long sum = 0ll;

        for( int i = 1; i <= N / 2; i++ )
			sum += fun( N - i, i );

        cout << sum << endl;

    }
}
