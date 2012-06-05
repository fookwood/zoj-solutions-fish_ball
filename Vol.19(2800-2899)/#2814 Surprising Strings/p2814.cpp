// 3067120 2008-09-12 09:26:43 Accepted 2814 C++ 00:00.00 2988K 呆滞的慢板 

//     简单模拟，读懂题就好，给一个字符串，按照不同的间隔 D 为等级抽取所有字符对， 
// 假如在所有等级中这样的对没有重复的，就是 surprising，反之不是。 

#include <iostream> 
#include <cstring> 
#include <vector>
using namespace std;

int main()
{ 
	char	x[80],	y[80];
	bool	flag[80];
	while( cin >> x) {
		if( *x == '*' )	break; 
		strcpy( y, x );
		int	L = strlen(x);
		bool	exit = 0;
		for( char* p = y + 1; p - y < L - 1; p++ ) {
			int	N = L - (p - y);
			for( int i = 0; i < N; i++ )
				flag[i] = 0;
			for( int i = 0; i < N; i++ ) {
				if( flag[i] )	continue;
				flag[i] = 1;
				char temp = x[i];
				vector<char> garbage;
				garbage.resize(0);
				garbage.push_back(p[i]);
				for( int j = i + 1; p[j] != 0; j++ ) {
					if( x[j] == temp ) {
						flag[j] = 1;
						garbage.push_back(p[j]);
					}
				}
				for( int j = 0; j < garbage.size(); j++ ) {
					for( int k = j + 1; k < garbage.size(); k++ ) {
						if( garbage[j] == garbage[k] ) {
							exit = 1;
							break;
						}
					}
					if( exit )	break;
				}
				if( exit )	break;
			}
			if( exit )	break;
		}
		if(exit)	cout << x << " is NOT surprising." << endl;
		else		cout << x << " is surprising." << endl;
	}
}
