// 3007065 2008-07-26 19:18:26 Accepted 3010 C++ 00:00.00 836K ´ôÖÍµÄÂý°å 

// Ó²Ã¶¾Ù 2^N 

#include <iostream>
#include <bitset>
using namespace std;

struct Lamp {
    int     N;
    double  S;
    int     R[10];
};

Lamp        L[10];
int         M;
double      V,  mx;
bitset<10>  B,  C;

int main() {
    
    while( cin >> M >> V && M ) {
        
        for( int i = 0; i < M; ++i ) {
            cin >> L[i].N;
            for( int j = 0; j < L[i].N; ++j ) {
                cin >> L[i].R[j];
                --L[i].R[j];
            }
            L[i].R[L[i].N++] = i;
            cin >> L[i].S;
            L[i].S = ( 1.0 - L[i].S / 100.0 );
        }
            
        mx = -1.0;
        for( int x = 0; x < 1 << M; ++x ) {
            B.reset();
            C = x;
            double val = 1.0;
            for( int i = 0; i < M; ++i ) {
                if( C[i] ) {
                    val *= L[i].S;
                    for( int j = 0; j < L[i].N; ++j )
                        B.flip( L[i].R[j] );
                }
            }
            if( B.count() == M && val > mx )
                mx = val;
        }
        
        if( mx < -0.5 ) { puts( "-1" ); continue; }
        else    printf( "%.2lf\n", mx * V );
        
    }
    
}
