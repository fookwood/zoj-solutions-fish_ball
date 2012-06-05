#include <cctype>
#include <iostream>
using namespace std;

int	main()
{
	int	N; 
  	while( cin >> N ) {
		if( !N ) break;
		long	total = 0;
		char	result[20];
		char*	pt = result + 20;
		while( N-- ) {
			string	temp;
			cin >> temp;
			long	sum = 0;
			for( int i = 1; i < temp.size(); i++ ) {
				if( isdigit( temp[i] ) ) {
					sum *= 10;
					sum += temp[i] - '0';
				}
			}
			total += sum;
		}
		*(--pt) = 0;
		*(--pt) = total % 10 + '0';
		total /= 10;
		*(--pt) = total % 10 + '0';
		*(--pt) = '.';
		if( !( total /= 10 ) )
			*(--pt) = '0';
		else {
			int digit = 0;
			do {
				if( digit && digit % 3 == 0 )
					*(--pt) = ',';
				*(--pt) = total % 10 + '0';
				digit++;
			} while( total /= 10 );
		}
		cout << '$' << pt << endl;
	} 
} 
