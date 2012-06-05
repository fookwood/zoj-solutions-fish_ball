#include <vector> 
#include <iostream>
using namespace std;

int main() {
	char	grid[100][100];
	int	x,	y,	z;
	while( cin >> x >> y >> z ) {
		if( !x && !y && !z ) break; 
		for( int i = 0; i < x; i++ )
			cin >> grid[i];
		int	posX = 0,	posY = z - 1; 
		vector<int>	recX(0),	recY(0); 
		while( 1 ) {
			if( 	posX >= x || posX < 0 || posY >= y || posY < 0 ) {
					cout << recX.size() << " step(s) to exit\n";
				break;
			}
			bool	exit = 0;
			int	i = 0; 
			for( ; i < recX.size(); i++ ) {
				if( posX == recX[i] && posY == recY[i] ) {
					exit = 1; 
					break; 
				}
			} 
			if( exit ) {
				cout << i << " step(s) before a loop of " <<
				    recX.size() - i << " step(s)\n";
				break; 
			} 
			recX.push_back( posX );
			recY.push_back( posY ); 
			switch( grid[posX][posY] ) {
				case 'N':	posX--; break; 
				case 'E':	posY++; break; 
				case 'S':	posX++; break; 
				case 'W':	posY--; 
			}
		} 
	} 
} 
