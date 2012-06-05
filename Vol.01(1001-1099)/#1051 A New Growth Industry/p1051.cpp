#include <iostream> 
using namespace std;

int main() {
	int T;
	cin >> T;
	int	grid[22][22]; 
	int	temp[22][22];
	int	D[16]; 
	while( T-- ) {
		int	N; 
		cin >> N;
		for(int i = 0; i < 16; i++) {
			cin >> D[i]; 
		} 
		for(int i = 0; i <= 21; i++) {
			for(int j = 0; j <= 21; j++) { 
				if(i == 0 || j == 0 || i == 21 || j == 21) 
					grid[i][j] = 0;
				else cin >> grid[i][j]; 
			}
		} 
		while(N--) {
			for(int i = 1; i <= 20; i++) {
				for(int j = 1; j <= 20; j++) {
					temp[i][j] = grid[i][j] + grid[i + 1][j] + grid[i - 1][j]
						   + grid[i][j + 1] + grid[i][j - 1];
	          			temp[i][j] = D[temp[i][j]]; 
        			} 
      			}
			for(int i = 1; i <= 20; i++) {
				for(int j = 1; j <= 20; j++) {
					grid[i][j] += temp[i][j];
					if(grid[i][j] > 3) grid[i][j] = 3;
					if(grid[i][j] < 0) grid[i][j] = 0;
				} 
			} 
		} 
		for(int i = 1; i <= 20; i++) {
			for(int j = 1; j <= 20; j++) {
				switch(grid[i][j]) {
					case 0: putchar('.'); break;
					case 1: putchar('!'); break;
					case 2: putchar('X'); break;
					case 3: putchar('#'); 
				} 
			} 
			cout << endl; 
		} 
		if( T )	cout << endl; 
	}
} 
