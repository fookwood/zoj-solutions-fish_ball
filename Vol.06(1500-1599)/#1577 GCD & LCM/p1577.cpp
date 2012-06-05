// 1653342 2008-10-01 21:26:38 Accepted  1577 C++ 220 260 呆滞的慢板 

// 这道题蛮力是可以过的，主要是头脑不大清醒
// 逻辑不能错了，谨慎
// 但算法总是不太好的，可以推公式 
#include <cstring>
#include <cstdio>

int main() {
	int	X,	Y,	M,	N,	R;
	while( scanf( "%d%d", &X ,&Y ) != EOF ) {
		int	count = 0;
		for( int i = X; i <= Y; i += X ) {
			if( Y % i == 0 ) {
				M = X * Y / i;
				N = i;
				while( N ) {
					R = M % N;
					M = N;
					N = R;
				}
				if( M == X )	count++;
			}
		}
		printf( "%d\n", count );
	}
	
}
