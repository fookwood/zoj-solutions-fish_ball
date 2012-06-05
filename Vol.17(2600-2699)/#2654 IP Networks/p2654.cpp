// 位操作题，注意运算符优先级 

#include <cstdio>
#include <cstring>

void disp( unsigned IP ) {
	printf( "%u.", ( IP >> 24 ) & 0xFFu );
	printf( "%u.", ( IP >> 16 ) & 0xFFu );
	printf( "%u.", ( IP >> 8  ) & 0xFFu );
	printf( "%u\n",  IP         & 0xFFu );
}

int main() {
	int	N;
	unsigned int IP, x[4], last, mask;
	while( scanf( "%d", &N ) != EOF ) {
		for( int i = 0; i < N; i++ ) {
			scanf( "%u.%u.%u.%u", x, x + 1, x + 2, x +3 );
			IP = x[0] << 24 | x[1] << 16 | x[2] << 8 | x[3];
			if( i == 0 ) {
				mask = 0xFFFFFFFFu;
				last = IP;
				continue;
			}
			for( unsigned i = 1 << 31; i & mask; i >>= 1 ) {
				if( ( i & IP ) != ( i & last ) ) {
					for( unsigned j = i; j & mask; j >>= 1 )
						mask &= ~j;
					break;
				}
			}
			last = IP;
		}
		IP &= mask;
		disp( IP );
		disp( mask );
	}
}
