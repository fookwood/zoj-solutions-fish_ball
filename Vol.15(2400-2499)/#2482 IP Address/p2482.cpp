#include <iostream>
using namespace std;
int 	main()
{
	int	N;
	char	bit[33]; 
	cin >> N;
	while( N-- ) {
		cin >> bit;
		for(int n = 0; n < 4; n++) {
			if(n) 	putchar('.'); 
			int 	sum = 0; 
			for(int i = 0; i < 8; i++) {
				sum *= 2;
				if(bit[n * 8 + i] == '1')
					sum += 1;
			}
			cout << sum; 
		} 
		cout << endl; 
	}
} 
