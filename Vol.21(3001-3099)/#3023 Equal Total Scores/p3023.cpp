// 3039915 2008-08-18 01:24:14 Accepted 3023 C++ 00:00.02 840K 呆滞的慢板 

// 水题，简单贪心 

#include <iostream>
#include <algorithm>
using namespace std;

int A[100], B[100], M,  N,  SA, SB, X;

int main() {
    
    while( cin >> M >> N && M ) {
        
        for( int i = SA = 0; i < M; ++i ) {
            cin >> A[i];
            SA += A[i];
        }
            
        for( int i = SB = 0; i < N; ++i ) {
            cin >> B[i];
            SB += B[i];
        }

        sort( A, A + M );
        sort( B, B + N );
        
        SB -= SA;
        if( SB & 1 ) {
            puts( "-1" );
            continue;
        }
        SB /= 2;
        
        X = -1;
        for( int i = 0; i < M; ++i ) {
            if( binary_search( B, B + N, A[i] + SB ) ) {
                X = A[i];
                break;
            }
        }
        
        if( X == -1 )   puts( "-1" );
        else            cout << X << " " << X + SB << endl;
            
    }
    
}
