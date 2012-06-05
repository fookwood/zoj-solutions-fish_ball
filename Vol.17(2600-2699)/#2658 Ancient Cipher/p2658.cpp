// 简单，只需判别重复字母出现次数的分布是否符合即可 
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int	A[26],	B[26],	C[26];
	string	temp1,	temp2;
	while( cin >> temp1 >> temp2 ) {
		for( int i = 0; i < 26; i++ )
			A[i] = B[i] = 0;
		for( int i = 0; i < temp1.size(); i++ )
			A[temp1[i] - 'A']++;
		for( int i = 0; i < temp2.size(); i++ )
			B[temp2[i] - 'A']++;
		sort( A, A + 26 );
		sort( B, B + 26 );
		bool	yes = true;
		for( int i = 0; i < 26; i++ ) {
			if( A[i] != B[i] ) {
				yes = false;
				break;
			}
		}
		if( yes )	cout << "YES" << endl;
		else		cout << "NO" << endl;
	}
}
