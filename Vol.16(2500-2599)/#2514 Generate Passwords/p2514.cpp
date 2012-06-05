// Simple
#include <vector>
#include <iostream>
#include <string>
using namespace std; 

int main() {
	int	N,	C;;
	vector<string>	set;
	vector<string>	name;
	string	X,	Y;
	set.reserve( 1000 );
	name.reserve( 1000 );
	while( ( cin >> N ) && N ) {
		C = 0;
		set.resize( 0 );
		name.resize( 0 );
		while( N-- ) {
			cin >> X >> Y;
			bool	alter = false;
			for( int i = 0; i < Y.size(); i++ ) {
				switch( Y[i] ) {
					case '1': Y[i] = '@'; alter = true; break;
					case '0': Y[i] = '%'; alter = true; break;
					case 'l': Y[i] = 'L'; alter = true; break;
					case 'O': Y[i] = 'o'; alter = true;
				}
			}
			if( alter ) {
				C++;
				name.push_back( X );
				set.push_back( Y );
			}
		}
		if( !C ) cout << "No account is modified." << endl;
		else {
			cout << C << endl;
			for( int i = 0; i < set.size(); i++ )
				cout << name[i] << ' ' << set[i] << endl;
		}
	}
}
