#include <iostream>
using namespace std;

int main() {
	int	N,	a1,	a2;
	bool	A[3001]; 
	while( cin >> N ) {
		bool	jolly = true; 
		for( int i = 1; i <= N; i++ ) A[i] = 0; 
		for( int i = 0; i < N; i++ ) {
			cin >> a2; 
			int	p = ( a1 > a2 ) ? ( a1 - a2 ) : ( a2 - a1 ); 
			if( i ) {
				A[p] = true; 
			}
			a1 = a2; 
		} 
		for( int i = 1; i < N; i++ ) {
			if( !A[i] ) {
				jolly = false;
				break;
			} 
		} 	
		if( jolly )	cout << "Jolly" << endl;
		else		cout << "Not jolly" << endl; 
	} 
} 
