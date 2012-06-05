#include <iostream>
using namespace std;

void perm( int data[], int N ) {
	int	x[50] = {0};
	bool	y[50] = {0};
	for( int i = 0; i < N; i++ ) {
		for( int j = 0; j < data[i] - 1; j++ ) {
			if( !y[j] )	x[j]++;
		}
		y[ data[i] - 1 ] = 1;
	}
	for( int i = 0; i < N; i++ )
		data[i] = x[i];
}

void iperm( int data[], int N ) {
	int	x[50] = {0};
	for( int i = 0; i < N; i++ ) {
		int*	p = x;
		for( int m = data[i]; m; m-- ) {
			while( *p ) p++;
			p++;
		}
		while( *p ) p++;
		*p = i + 1;
	}
	for( int i = 0; i < N; i++ )
	data[i] = x[i];
}

int main() {
	int	M;
	char	type[2];
	int	data[50];
	while( cin >> M ) {
		if( !M ) break;
		cin >> type;
		for( int i = 0; i < M; i++ )
			cin >> data[i];
		if( *type == 'P' ) perm( data, M );
		else	iperm( data, M );
		for( int i = 0; i < M - 1; i++ )
			cout << data[i] << ' ';
		cout << data[M - 1] << endl;
	}
}
