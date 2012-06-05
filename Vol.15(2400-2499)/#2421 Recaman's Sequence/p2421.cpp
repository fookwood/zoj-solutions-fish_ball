#include <iostream>
#include <vector>
using namespace std;

int main() {
	int	A[500010] = { 0 };
	vector<bool>	flag( 10000000, 0); 
	flag[0] = 1; 
	for( int k = 1; k < 500001; k++ ) {
		if( A[k - 1] - k > 0 && !flag[A[k - 1] - k]  )
			A[k] = A[k - 1] - k;
		else
			A[k] = A[k - 1] + k;
		flag[A[k]] = 1; 
	}
	int	N; 
	while( cin >> N ) {
		if( N == -1 ) break; 
		cout << A[N] << endl; 
	}
} 
