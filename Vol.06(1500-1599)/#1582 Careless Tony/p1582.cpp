// 3059199 2008-09-04 12:23:56 Accepted 1582 C++ 00:00.00 836K 呆滞的慢板 

// 这么简单的字符串题，居然 1WA
// 原因是没考虑空格也是字符串的一部分
// 因此只能用 getline 而不能用 cin >> s 

#include <iostream>
#include <string>
using namespace std;

int main() {
	int	T,	dt,	pos;
	string	corr,	mstk;
	cin >> T;
	while( T-- ) {
		cin >> dt;
		getchar();
		getline( cin, corr );
		getline( cin, mstk );
		for( pos = 0; pos < corr.size() && pos < mstk.size(); pos++ )
			if( corr[pos] != mstk[pos] ) break;
		cout << dt * ( mstk.size() + corr.size() - pos - pos ) << endl;
	}
}
