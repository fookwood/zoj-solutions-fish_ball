// 1655154 2008-10-03 20:28:27 Accepted  2527 C++ 70 4096 呆滞的慢板 

// 很惨的一道题，让我再次感受到 DP 的困难
// 估计 WA 已经不下 10 次了
// 开始半参考半写写了个 O(n^3)的 DP，然后 TLE
// 然后参考 冗余的代码 博客的解题报告，翻写了一次
// 哪里知道居然结束少了一句害我无数 WA
// 结论：这道题很典型，DP 很重要 

#include <cstdio>
#include <cstdlib>

int icmp( const void* a, const void* b ) {  
	if( *( int* )a > *( int* )b ) return 1;
	if( *( int* )a < *( int* )b ) return -1;
	return	0;
}  

int main() {
	int	max,	top,	temp,	N,	A[1001];
	int*	ptr;
	int	( *B )[1001] = new int[1001][1001];
	while( scanf( "%d", &N ) != EOF ) {
		for( int i = 0; i < N; i++ ) scanf( "%d", A + i );
		// 快排 
		qsort( A, N, 4, icmp );
		// 消除重复的数字，并记录最长的相同大小序列到 max 
		for( int i = top = max = temp = 1; i < N; i++ ) {
			if( A[i] == A[i - 1] )	temp++;
			else {
				A[top++] = A[i];
				if( temp > max ) max = temp;
				temp = 1;
			}
		}
		if( temp > max ) max = temp;
		N = top;
		// 开始DP
		for( int i = 1; i < N; i++ ) {
			for( int j = 0; j < i; j++ ) {
				temp = 2 * A[j] - A[i];
				ptr = ( int* )bsearch( &temp, A, j, 4, icmp );
				if( !ptr )	B[i][j] = 2;
				else {
					B[i][j] = B[j][ptr - A] + 1;
					if( B[i][j] > max ) max = B[i][j];
				}
			}
		}
		if( B[N - 1][N - 2] > max ) max = B[N - 1][N - 2];
		printf( "%d\n", max );
	}
}
