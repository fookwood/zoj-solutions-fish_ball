#include <iostream> 
using namespace std;

int 	main()
{
	int	N;
	cin >> N;
	char	x[101]; 
	while( N-- ) {
		cin >> x;
		char*	p = x;
		int	count = 0;  
		while( char temp = *(p++) ) {
			if( temp != *p ) {
				if(count)
					cout << count + 1;
				count = 0;
				putchar(temp); 
			}
			else count++;	 
		} 
		cout << endl; 
	} 
} 
