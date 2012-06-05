#include <iostream>
using namespace std;

int main() {
	int	a,	b,	c,	d,	e,	f;
	while( cin >> a >> b >> c >> d >> e >> f ) {
		if( !a && !b && !c && !d && !e && !f ) break;
		int	x = a + b;
		int	y = ( a + c + e - b - d -f );
		cout 	<< "Anna's won-loss record is "
			<< ( x - y ) / 2 << '-' << ( x + y ) / 2 << ".\n";
	}
} 
