// ºÚµ•Ã‚ 

#include <cstdio>

int main() {
    int*    A = new int[100001];
    int     N;
    while( scanf( "%d", &N ) && N ) {
        for( int i = 1; i <= N; i++ )
            scanf( "%d", A + i );
        bool    ambiguous = true;
        for( int i = 1; i <= N; i++ ) {
            if( A[A[i]] != i ) {
                ambiguous = false;
                break;
            }
        }
        puts( ambiguous ? "ambiguous" : "not ambiguous" );
    }
}
