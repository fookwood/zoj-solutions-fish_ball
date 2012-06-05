// 这道题就有技术含量了
// 基本思路是：计数排序法，生成索引表(index)，同时生成原始的 inversion 数目
// 第一步：O(n^2) 
// 然后，逐个 rotation ，而这个 rotation 是不用真正地做的，
//     rotate 某个元素会产生多少个 inversion 的改变可以从它的 index 中反映出来
// 第二步：O(n) 

// 结论：计数排序法真的很好用
// 但是，提交结果原来并不是那么理想，虽然 1AC，但是 0.19s，420K，根本排不上榜 

#include <cstdio>

int main() {
	int	N,	A[5000];
	short	index[5000];
	while( scanf( "%d", &N ) != EOF ) {
		int	inv = 0;
		for( int i = 0; i < N; i++ ) {
			index[i] = 0;
			scanf( "%d", A + i );
			for( int j = 0; j < i; j++ ) {
				if( A[i] > A[j] )
					index[i]++;
				else {
					index[j]++;
					inv++;
				}
			}
		}
		int	min = inv;
		for( int i = 0; i < N; i++ ) {
			inv += ( N - ( index[i] << 1 ) - 1 );
			if( inv < min ) min = inv;
		}
		printf( "%d\n", min );
	}
}
