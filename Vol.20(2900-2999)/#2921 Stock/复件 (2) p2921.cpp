// Greedy
#include <cstdio>
#include <cstring>
#define MAX 100001

int main() {
	int	A[MAX],	a[MAX],	count[MAX], 
		p[MAX],	m[MAX],	sum;
	int	T,	N;
	int*	index[MAX];
	scanf( "%d", &T ); 
	while( T-- ) {
		scanf( "%d", &N ); 
		sum = 0;
		scanf( "%d%d%d", A, p, m );
		a[0] = A[0];
		for( int i = 1; i < N; i++ ) {
			scanf( "%d%d%d", A + i, p + i, m + i );
			// a 是 A 的求和 
			a[i] = a[i - 1] + A[i];
		}
		memset( count, 0, N * sizeof( int ) );
		// 生成价格排序索引 
		for( int i = N - 2; i >= 0; i-- )
		for( int j = i + 1; j < N; j++ )
			if( p[i] < p[j] )	count[j]++;
			else			count[i]++;
		for( int i = 0; i < N; i++ )
			index[count[i]] = p + i;
		// 主操作，贪心算法，从最贵的卖起 
		for( int i = N - 1; i >= 0; i-- ) {
			if( !*index[i] ) continue;
			int	j = index[i] - p;
			// 实际卖出为现存股票与最大卖出量之间的最小值 
			int	minus = ( a[j] > m[j] ) ? m[j] : a[j];
			sum += minus * p[j];
			// 从现有股票数组 A 和 a 中减去卖出股票，贪心策略，先卖出日期靠后的
			for( int k = j + 1; k < N; k++ )
				a[k] -= minus;
			while( 1 ) {
				if( minus > A[j] ) {
					a[j] -= A[j];
					minus -= A[j];
					A[j--] = 0;
				}
				else {
					A[j] -= minus;
					a[j] -= minus;
					break;
				}
			}
		}
	/*		
			
			
		while( 1 ) {
			int	max = 0, maxi = -1;
			for( int i = 0; i < N; i++ ) {
				if( p[i] && p[i] >= max ) {
					max = p[i];
					maxi = i;
				}
			}
			if( maxi == -1 ) break;
			int	a = 0;
			for( int i = 0; i <= maxi; i++ )	a += A[i];
			int	minus = ( a > m[maxi] ) ? m[maxi] : a;
			sum += minus * p[maxi];
			p[maxi] = 0;
			while( 1 ) {
				if( minus > A[maxi] ) {
					minus -= A[maxi];
					A[maxi--] = 0;
				}
				else {
					A[maxi] -= minus;
					break;
				}
			}
		}	
		
		
		*/
		printf( "%d\n", sum );
	} 
} 
