// 没什么好说的，对齐要正确，然后那个复数的 's' 好阴，1 的时候别输出有 's'
// 2863114 2008-04-23 14:30:58 Accepted 1874 C++ 00:00.01 388K 呆滞的慢板  
#include <cstdio>
#include <cstring>

int main() {
    char  A[11], B[11], *C;
    while( scanf( "%s%s", A, B ) ) {
        if( strcmp( A, "0" ) == 0 &&
            strcmp( B, "0" ) == 0 ) break;
        int D = strlen( A ) - strlen( B );
        if( D > 0 )    C = B;
        else { D = -D; C = A; }
        C[strlen( C ) + D] = '\0';
        for( int i = strlen( C ) - 1; i >= 0; --i )
            C[i + D] = C[i];
        for( int i = D - 1; i >= 0; --i )
            C[i] = '0';
        int   count = 0, carry = 0;
        for( int i = strlen( C ); i >= 0; --i ) {
            if( ( A[i] - '0' ) + ( B[i] - '0' ) + carry >= 10 )
                { count++; carry = 1; }
            else    carry = 0;
        }
        if( !count )  printf( "No carry operation" );
        else printf( "%d carry operation", count );
        puts( count <= 1 ? "." : "s." );
    }
}
