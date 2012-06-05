#include <string>
#include <iostream>
using namespace std;

int main() {
		//	  ABCDEFGHIJKLMNOPQRSTUVWXYZ 
	char	list[] = " 123 12  22455 12623 1 2 2"; 
	string	a,	b;
	while( cin >> a ) {
		b = "";
		for( int i = 0; i < a.size(); i++ )
			if( list[a[i] - 'A'] != ' ' )
				if( i == 0 || list[a[i] - 'A'] != list[a[i - 1] - 'A'] )
					b += list[a[i] - 'A'];
		cout << b << endl; 
	}
} 
