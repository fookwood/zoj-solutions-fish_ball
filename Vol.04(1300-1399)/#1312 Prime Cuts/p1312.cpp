// BS数据！！
// 说是1000以内，写了刚好1000 WA了我两次！！
// 好在 POJ 上面有同样问题，回头一改大了范围就 AC 了 

#include <iostream>
using namespace std;

int main() {
	bool	Label[2000] = {};
	int	Prime[500],	N = 0;
	for( int i = 2; i <= 31; i++ )
		if( !Label[i] )
			for( int j = i + i; j < 2000; j += i )
				Label[j] = true;
	for( int i = 1; i < 2000; i++ )
		if( !Label[i] )
			Prime[N++] = i;
	int	X,	Y;
	while( cin >> X >> Y ) {
		cout << X << ' ' << Y << ':';
		int	I = 0;
		while( X >= Prime[I] ) I++;
		int	lb = ( I + 1 ) / 2 - Y;
		if( lb < 0 )	lb = 0;
		int	M = ( I % 2 ) ? 2 * Y - 1 : 2 * Y;
		for( int i = 0; i < M && lb + i < I; i++ )
			cout << ' ' << Prime[lb + i];
		cout << endl << endl;
	}
}
