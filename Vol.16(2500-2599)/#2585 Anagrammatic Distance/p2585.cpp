// 简单的计算各个字母出现次数，统计所有差别即可
// 用 iostream 和 string 会超时 
#include <cstring>
#include <cstdio>

int main() {
	int	A[26],	B[26],	dis,	L1,	L2,	N;
	char	s1[99],	s2[99];
	scanf( "%d ", &N );
	for( int t = 1; t <= N; t++ ) {
		gets( s1 );
		L1 = strlen( s1 );
		gets( s2 );
		L2 = strlen( s2 );
		memset( A, 0, 104 );
		memset( B, 0, 104 );
		for( int i = 0; s1[i]; i++ )	A[s1[i] - 'a']++;
		for( int i = 0; s2[i]; i++ )	B[s2[i] - 'a']++;
		for( int i = dis = 0; i < 26; i++ )
			dis += A[i] > B[i] ? A[i] - B[i] : B[i] - A[i];
		printf( "Case #%d:  %d\n", t, dis );
	}
}
