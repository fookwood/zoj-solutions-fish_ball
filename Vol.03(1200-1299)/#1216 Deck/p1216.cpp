#include <iostream>
#define MAXLINE 100
using namespace std;

double fun(int N) {
	if( N == 1 )	return .5;
	else		return fun( N - 1 ) + 1. / 2. / double( N );
}

int main() {
	cout << "# Cards  Overhang" << endl; 
	int	N;
	cout.setf( ios::fixed );
	cout.precision(3);
	while( cin >> N ) {
		cout.width(5);
		cout << N << "     " << fun(N) << endl;
	}
	 
}


