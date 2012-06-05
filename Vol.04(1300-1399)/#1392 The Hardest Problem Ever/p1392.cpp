#include <string> 
#include <cctype> 
#include <iostream>
using namespace std;

int main() {
	const string	code( "VWXYZABCDEFGHIJKLMNOPQRSTU" ); 
	string temp;
	while( 1 ) {
		getline( cin, temp ); 
		if( temp == "START" )
		while(1) {
			getline( cin, temp );
			if( temp == "END" )
				break;
			for( int i = 0; i < temp.size(); i++ ) {
				if( isupper( temp[i] ) )
					temp[i] = code[temp[i] - 'A']; 
			} 
			cout << temp << endl;
		}
		if( temp == "ENDOFINPUT" )
			break; 
	} 
} 
