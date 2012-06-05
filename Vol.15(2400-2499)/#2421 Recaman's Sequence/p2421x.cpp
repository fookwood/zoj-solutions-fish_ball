// 1655492 2008-10-03 22:50:58 Accepted  2421 C++ 230 8632 ´ôÖÍµÄÂı°å 

#include <iostream>
#include <set>
using namespace std;

int main() {
	int	A[500010] = { 0 };
	set<int> s; 
	for( int k = 1; k < 500001; k++ ) {
		if( A[k-1]-k > 0 && s.find(A[k-1]-k) == s.end() )
			A[k] = A[k-1] - k;
		else
			A[k] = A[k-1] + k;
		s.insert(A[k]);
	}
	int	N; 
	while( cin >> N ) {
		if( N == -1 ) break; 
		cout << A[N] << endl; 
	}
} 
