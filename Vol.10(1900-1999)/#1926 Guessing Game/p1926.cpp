#include <string>
#include <iostream>
using namespace std;

int main() {
	int	up,	down,	temp;
	string	s;
	while( cin >> temp ) {
		if( !temp ) break;
		bool	yes = 1, begin = 1; 
		up = 10;
		down = 1; 
		while( 1 ) { 
			if( begin )	begin = 0;
			else		cin >> temp; 
			cin >> s >> s;
			if( s == "high" ) {
				if( up >= temp ) up = temp - 1; 
				if( down > up )	 yes = 0;
			}
			else if( s == "low" ) {
				if( down <= temp ) down = temp + 1; 
				if( down > up )	 yes = 0;
			}
			else {
				if( temp < down || temp > up ) yes = 0;
				break;
			} 
		}
		if( yes )	cout << "Stan may be honest" << endl;
		else		cout << "Stan is dishonest" << endl;
	} 
} 
