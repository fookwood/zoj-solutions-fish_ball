#include <string>
#include <vector> 
#include <iostream> 
#include <algorithm> 
using namespace std;

int main() {
	int	N;
	vector<string>	A; 
	while( cin >> N ) { 
		if( !N ) break;
		A.resize( 0 ); 
		while( N-- ) {
			string	temp;
			cin >> temp;
			A.push_back( temp );
		}
		sort( A.begin(), A.end() );
		int	max = 1, count = 1;
		string	balloon = A[0]; 
		for( int i = 1; i < A.size(); i++ ) {
			if( A[i - 1] != A[i] ) 
				count = 1; 
			else	count++;
			if( max < count ) {
				max = count;
				balloon = A[i]; 
			} 
		} 
		cout << balloon << endl; 
	}
} 
