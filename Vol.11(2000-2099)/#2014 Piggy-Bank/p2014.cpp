// 3028391 2008-08-09 11:31:14 Accepted 2014 C++ 00:00.38 880K 呆滞的慢板 

// 类似 0-1 背包的 DP，经典 

#include <iostream>
using namespace std;

int     B[10001];

int     E,  F,  N,  P,  W,  T;

int main() {

    for( cin >> T; T--; ) {
        
        cin >> E >> F;
        
        F -= E;
        
        for( int i = 0; i <= F; ++i )
            B[i] = INT_MAX;
        
        B[0] = 0;
        
        for( cin >> N; N--; ) {
            cin >> P >> W;
            for( int i = 0; i + W <= F; ++i )
                if( B[i] != INT_MAX )
                    B[i + W] <?= B[i] + P;
        }
        
        if( B[F] == INT_MAX )
            puts( "This is impossible." );
        else
            printf( "The minimum amount of money in the piggy-bank is %d.\n", B[F] );
        
    }


} 
