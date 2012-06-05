// 简单，但是很阴，用 iostream TLE
// 2838869 2008-04-11 21:36:38 Accepted 1171 C++ 00:00.08 396K 呆滞的慢板 

#include <cstdio>

int main() {
    char    a,  b;
    int     T,  N;
    scanf( "%d", &T );
    while( T-- ) {
        scanf( "%d", &N );
        if( N-- )
            while( ( a = getchar() ) != 'D' && a != 'U' );
        int count = 0;
        while( N-- ) {
            while( ( b = getchar() ) != 'D' && b != 'U' );
            count += ( b != a );
            a = b;
        }
        printf( "%d\n", count );
        if( T ) puts( "" );
    }
}
