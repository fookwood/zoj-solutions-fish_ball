#include <string>
#include <iostream>
using namespace std;
#define MAXNODE 19 

int	A[MAXNODE],	B[MAXNODE];

string tree( int node, int index ) {
	string	s("X"); 
	int	i = 0,	j = node - 1; 
	for( ; i < node; i++, j-- ) {
		int	p = A[i] * A[j];
		if( index >= p )
			index -= p;
		else	break; 
	}
	int	x = index / A[j],	y = index % A[j];
	if( i )	s = '(' + tree( i, x ) + ')' + s;
	if( j ) s = s + '(' + tree( j, y ) + ')';
	return	s;
}

int main() {
	B[1] = ( B[0] = A[0] = A[1] = 1 ) + 1;
	for( int i = 2; i < MAXNODE; i++ ) {
		A[i] = 0;
		for( int j = 0; j < i; j++ )
			A[i] += A[j] * A[i - j - 1];
		B[i] = B[i - 1] + A[i]; 
	} 
	int	N;
	while( cin >> N ) {
		int	node;
		if( !N ) break;
		else	for( node = 0; node < MAXNODE; node++ )
				if( N < B[node]) break; 
		int	index = N - B[node - 1];
		cout << tree( node, index ) << endl; 
	} 
} 
