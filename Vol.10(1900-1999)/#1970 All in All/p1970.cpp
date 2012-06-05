#include <string>
#include <iostream>
using namespace std;

int main() {
	string	a,	b;
	while( cin >> a >> b ) {
		int	i = 0, j = 0; 
		for( ; i < a.size() && j < b.size(); j++ )
			if( a[i] == b[j] ) i++;
		if( i == a.size() )	cout << "Yes\n";
		else			cout << "No\n"; 
	} 
} 
