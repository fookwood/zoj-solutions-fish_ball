#include <string>
#include <iostream>
#include <cctype>
using namespace std;

struct code {
	char	x;
	bool	exist[26];
	string	gs(); 
};

string code :: gs() {
	string	disp( "" );
	for( int i = 0 ; i < 26; i++ )
		if( exist[i] )
			disp += ( 'a' + i ); 
	return disp; 
} 

void add( code* D, string s1, string s2 ) {
	for( int i = 0; i < s1.size(); i++ )
		for( int j = 0; j < s2.size(); j++ )
			D[s1[i] - 'A'].exist[s2[j] - 'a'] = true;
}

void sub( code* D, string s1, string s2 ) {
	for( int i = 0; i < s1.size(); i++ )
		for( int j = 0; j < s2.size(); j++ )
			D[s1[i] - 'A'].exist[s2[j] - 'a'] = false;
}

void equ( code* D, string s1, string s2 ) {
	for( int i = 0; i < s1.size(); i++ ) {
		for( int j = 0; j < 26 ; j++ )
			D[s1[i] - 'A'].exist[j] = false;
		for( int j = 0; j < s2.size(); j++ )
			D[s1[i] - 'A'].exist[s2[j] - 'a'] = true;
	}
}

int main() {
	int	T = 1;
	code	D[26];
	string	temp,	part;
	while( cin >> temp ) {
		if( temp == "#" )	break;
		cout << T++ << ':'; 
		for( int i = 0; i < 26; i++ ) {
			D[i].x = 'A' + i;
			for( int j = 0; j < 26; j++ )
				D[i].exist[j] = false;
		}
		while( temp.size() ) {
			int	pos;
			if( ( pos = temp.find( ',' ) ) >= 0 ) {
				part = temp.substr( 0, pos );
				temp.erase( 0, pos + 1 );
			}
			else {
				part = temp;
				temp = "";
			}
			char	op;
			pos = 0;
			while( pos < part.size() ) {
				if( !isalpha( part[pos] ) ) {
					op = part[pos];
					break;
				}
				pos++;
			}
			string	s1 = part.substr( 0, pos ), s2 = part.substr( pos + 1 );
			switch( op ) {
				case '+':	add( D, s1, s2 );	break;
				case '-':	sub( D, s1, s2 );	break;
				case '=':	equ( D, s1, s2 );	break;
			}
		}
		string	before(""),	disp; 
		for( int i = 0; i < 26; i++ ) {
			disp = D[i].gs();
			if( disp.size() ) {
				if( before != disp )
					cout << before; 
				before = disp; 
				putchar( D[i].x );
			}
		}
		cout << before << endl; 
	} 
} 
