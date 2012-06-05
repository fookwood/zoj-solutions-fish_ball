#include <iostream>
using namespace std;

int main() {
	int	N,	i = 0;
	cin >> N; 
	while( i++ < N) {
		if(i == 1)	getchar();
		cout << "String #" << i << endl;
		while(1) {
			char temp = getchar();
			if( temp == '\n' ) {
				putchar('\n');
				break;
			}
			if( temp == 'Z' )
				putchar('A');
			else
				putchar(temp + 1);
		}
		putchar('\n');
	}
} 
