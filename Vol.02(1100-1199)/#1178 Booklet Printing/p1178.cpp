// 模拟题，怎么做都行，有点麻烦 
// 2838983 2008-04-11 22:16:21 Accepted 1178 C++ 00:00.00 388K 呆滞的慢板 

#include <cstdio>

int main() {
    int     N;
    while( scanf( "%d", &N ) && N ) {
        printf( "Printing order for %d pages:\n", N );
        int     x1 = 1, x2 = N % 4 ? N + 4 - N % 4 : N;
        int     piece = 0;
        while( x1 < x2 ) {
            if( piece % 2 == 0 ) {
                printf( "Sheet %d, front: ", piece / 2 + 1 );
                if( x2 > N )
                    printf( "Blank, " );
                else
                    printf( "%d, ", x2 );
                printf( "%d\n", x1 );
            }
            else {
                if( x1 > N )   break;
                printf( "Sheet %d, back : ", piece / 2 + 1 );
                printf( "%d, ", x1 );
                if( x2 > N )
                    printf( "Blank\n" );
                else
                    printf( "%d\n", x2 );
            }
            piece++;
            x1++;
            x2--;
        }
    }
}
