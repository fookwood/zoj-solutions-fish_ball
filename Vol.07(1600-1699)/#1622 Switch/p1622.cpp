#include <iostream>
using namespace std;

int main() {
	bool	a,	c;
	int	N,	n1,	n2;
	while( cin >> N ) {
		a = true;
		n1 = n2 = 0; 
		while( N-- ) {
			cin >> c;
			if( c ^ a )	n1++;
			else		n2++;
			a = !a; 
		}
		if( n1 > n2 ) 	cout << n2 << endl;
		else		cout << n1 << endl;
	} 
} 
