// Purely Brute Force 

#include <string>
#include <iostream>
using namespace std;

int common( string s1, string s2 ) {
	int	max = 0,	count; 
	for( int i = 0; i < s1.size(); i++ ) {
		count = 0; 
		for( int j = 0; i + j < s1.size(); j++ )
			if( s2[j] == s1[i + j] )
				count++; 
		if( count > max )
			max = count; 
	} 
	for( int i = 0; i < s2.size(); i++ ) {
		count = 0; 
		for( int j = 0; i + j < s2.size(); j++ )
			if( s1[j] == s2[i + j] )
				count++; 
		if( count > max )
			max = count; 
	} 
	return	max * 2; 
} 

int gcd( int m, int n ) {
	if( !n ) return m;
	else	return gcd( n, m % n ); 
} 

int main() {
	string	s1,	s2;
	while( cin >> s1 ) {
		if( s1 == "-1" ) break;
		cin >> s2;
		int	p = common( s1, s2 );
		int	q = s1.size() + s2.size();
		cout << "appx(" << s1 << ',' << s2 << ") = ";
		if( p == 0 )		cout << "0\n";
		else if( p == q ) 	cout << "1\n";
		else {
			int	r = gcd( q, p ); 
			cout << p / r << '/' << q / r << '\n';
		} 
	} 
} 
