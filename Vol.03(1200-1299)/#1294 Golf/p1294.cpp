#include <iostream>
using namespace std;

int main() {
	int	p,	s,	T = 1;
	while( cin >> p >> s ) {
		if( !p ) break;
		cout << "Hole #" << T++ << endl;
		if( s == 1 )	cout << "Hole-in-one." << endl;
		else switch( p - s ) {
			case 3  : cout << "Double Eagle." << endl;	break;
			case 2  : cout << "Eagle." << endl;		break;
			case 1  : cout << "Birdie." << endl;		break;
			case 0	: cout << "Par." << endl;		break;
			case -1 : cout << "Bogey." << endl;		break;
			default : cout << "Double Bogey." << endl;
		}
		cout << endl;
	}
}
