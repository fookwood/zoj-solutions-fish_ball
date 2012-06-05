#include <iostream>
#include <vector> 
using namespace std;
 
int main() {
	int	N;
	bool	flag[1001]; 
	while(cin >> N) {
		if( !N ) break;
		for( int i = 0; i < 1001; i++ ) 
			flag[i] = 0; 
		int	x[10][10];
		int	row[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		int	col[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		int	diag1 = 0, diag2 = 0; 
		bool	exit = 0; 
		for( int i = 0; i < N; i++ ) {
			for( int j = 0; j < N; j++ ) {
				cin >> x[i][j];
				if( exit ) continue; 
				if( flag[ x[i][j] ] )
					exit = 1; 
				flag[ x[i][j] ] = 1; 
				row[i] += x[i][j];
				col[j] += x[i][j]; 
				if( i == j )
					diag1 += x[i][j];
				if( i + j == N - 1 )
					diag2 += x[i][j];
			}
		} 
		if( exit          || 
			*row != *col  ||
			*row != diag1 ||
			*row != diag2 ) {
			cout << "No\n";
			continue; 
		}
		for(int i = 0; i < N - 1; i++) {
			if( row[i] != row[i + 1] ||
				col[i] != col[i + 1] ) {
				cout << "No\n";
				continue; 
			}
		} 
		cout << "Yes\n"; 
	} 
} 
