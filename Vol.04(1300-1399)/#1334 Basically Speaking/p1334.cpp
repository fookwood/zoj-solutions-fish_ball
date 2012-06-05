#include <string>
#include <cctype> 
#include <iostream>
using namespace std;

int main() {
	string	str;
	int	a,	b,	sum;
	char	list[] = "0123456789ABCDEF";
	while( cin >> str >> a >> b ) {
		for( int i = sum = 0; i < str.size(); i++ ) {
			int	digit;
			if( isdigit( str[i] ) )
				digit = int( str[i] - '0' );
			else
				digit = 10 + int( str[i] - 'A' );
			sum *= a;
			sum += digit; 
		} 
		string	disp("");
		while( sum ) {
			int	x = sum % b;
			sum /= b;
			disp = list[x] + disp; 
		}  
		if( disp.size() > 7 )
			cout << "  ERROR" << endl;
		else {
			while( disp.size() < 7 )
				disp = ' ' + disp;
			cout << disp << endl;
		} 
	} 
} 
