// 2890474 2008-05-05 14:07:16 Accepted 2109 C++ 00:00.06 448K 呆滞的慢板

// 简单的贪心即可，从最大比例的入手 

#include <algorithm>
#include <cstdio>
using namespace std;

struct Room { int J,  F; };

inline bool operator < ( const Room& r1, const Room& r2 ) {
    return  r1.J * r2.F > r2.J * r1.F;
}

int main() {
    
    Room    V[1000];
    
    int M,  N;
    double  total;
    
    while( scanf( "%d%d", &M, &N ) ) {
        
        if( M == -1 && N == -1 ) break;
        
        for( int i = 0; i < N; ++i )
            scanf( "%d%d", &V[i].J, &V[i].F );

        sort( V, V + N );

        total = 0.0;

        for( int i = 0; i < N; ++i ) {
            if( M > V[i].F ) {
                total += V[i].J;
                M -= V[i].F;
            }
            else {
                total += double( V[i].J ) *
                         double( M ) / double( V[i].F );
                break;
            }            
        }
        
        printf( "%.3lf\n", total );
        
    }
    
}
