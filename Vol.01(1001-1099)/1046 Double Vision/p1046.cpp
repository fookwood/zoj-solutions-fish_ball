#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct grid {
	int	r; 
	string	A[10];
};

void disp( vector<grid> gridSet ) {
	int	R = gridSet[0].r;
	for( int i = 0; i < R; i++ ) {
		cout << gridSet[0].A[i];
		for( int j = 1; j < gridSet.size(); j++ )
			cout << ' ' << gridSet[j].A[i];
		cout << endl;
	}
}

int main() {
	int	N,	R,	C;
	vector<grid>	gridSet;
	int	P[10][80];
	while( cin >> N >> R >> C ) {
		gridSet.resize( N );
		for( int i = 0; i < N; i++ )
			gridSet[i].r = R;
		for( int i = 0; i < R; i++ )
			for( int j = 0; j < N; j++ )
				cin >> gridSet[j].A[i];
		for( int r = 0; r < R; r++ )
		for( int i = 0; i < N; i++ )
		disp( gridSet );
	} 
} 
