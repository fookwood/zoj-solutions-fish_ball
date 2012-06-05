// 3036755 2008-08-15 16:31:28 Accepted 2747 C++ 00:00.04 1244K ´ôÖÍµÄÂý°å 

#include <iostream>
#include <vector>
using namespace std;

int     W[10001],   H[10001];

int     A[101],     MW[200],    MH[200];

struct Rectangle {
    int r1, c1, r2, c2, clr;
    void get() {
        r1, c1, r2, c2, clr;
        scanf( "%d%d%d%d%d", 
            &r1, &c1, &r2, &c2, &clr );
    }
} R[100];

int     N,  X,  Y,  K,  L,  S,  T = 0;

int     clr[201][201],  lnk[201][201];

int paint( int x, int y, int end, int color ) {
    if( y >= end )  return  y;
    if( !clr[x][y] ) clr[x][y] = color;
    return  lnk[x][y] = paint( x, lnk[x][y], end, color );
}

int main() {
    
    while( scanf( "%d%d", &X, &Y ) && ( X || Y ) ) {
        
        if( T++ )   puts( "" );
        
        printf( "Case %d:\n", T );
        
        memset( W, -1, sizeof( W ) );
        memset( H, -1, sizeof( H ) );
        
        cin >> N;
        for( int i = 0; i < N; ++i ) {
            R[i].get();
            R[i].r1 <?= X;
            R[i].r2 <?= X;
            R[i].c1 <?= Y;
            R[i].c2 <?= Y;
            W[R[i].r1] = W[R[i].r2] =
            H[R[i].c1] = H[R[i].c2] = 0;
        }
        
        for( int i = K = 0; i <= X; ++i )
            if( !W[i] ) MW[W[i] = K++] = i;
        
        for( int i = L = 0; i <= Y; ++i )
            if( !H[i] ) MH[H[i] = L++] = i;
        
        memset( clr, 0, sizeof( clr ) );
        
        for( int i = 0; i < K; ++i )
            for( int j = 0; j < L; ++j )
                lnk[i][j] = j + 1;
        
        for( int n = N - 1; n >= 0; --n )
            for( int i = W[R[n].r1]; i < W[R[n].r2]; ++i )
                paint( i, H[R[n].c1], H[R[n].c2], R[n].clr );
     
        memset( A, 0, sizeof( A ) );
        for( int i = 0; i < K; ++i ) {
            for( int j = 0; j < L; ++j ) {
                if( clr[i][j] ) {
                    A[clr[i][j]] += ( MW[i+1] - MW[i] ) *
                                    ( MH[j+1] - MH[j] );
                }
            }
        }
        
        for( int i = S = 0; i < 101; ++i ) {
            if( A[i] ) {
                ++S;
                printf( "%d %d\n", i, A[i] );
            }
        }
        
        if( S > 1 ) printf( "There are %d colors left on the wall.\n", S );
        else        printf( "There is %d color left on the wall.\n", S );
        
    }
    
}
