// 记得有一道比较相像的题叫三剑客
// 很简单 

#include <cstdio>

int main() {
	unsigned	N;
	while( scanf( "%d", &N ) && N ) {
		int	sum = 0;
		while( N > 1 ) {
			N = ( N + 1 ) / 2;
			sum++;
		}
		printf( "%d\n", sum );
	}
}
