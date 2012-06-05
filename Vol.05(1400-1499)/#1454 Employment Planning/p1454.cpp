// 3028008 2008-08-08 17:31:55 Accepted 1454 C++ 00:00.10 840K 呆滞的慢板 

// 基础 DP

// DP[i][j]，第 i 个月保有 j 个员工的花费

#include <iostream>
using namespace std;

int     N,  H,  S,  F; 

int     M[13],  MX;

int     DP[13][101]; 

int cost( int x, int y ) {
    int ans = S * y;
    if( x > y ) ans += F * ( x - y );
    else        ans += H * ( y - x );
    return  ans;
}

int main() {
    
    while( cin >> N && N ) {
        
        cin >> H >> S >> F;

        MX = M[0] = 0;
        
        for( int i = 1; i <= N; ++i ) {
            cin >> M[i];
            MX >?= M[i];
        }
        
        for( int i = M[1]; i <= MX; ++i )
            DP[1][i] = H * i + i * S;
        
        for( int i = 2; i <= N; ++i ) {
            for( int j = M[i]; j <= MX; ++j ) {
                DP[i][j] = INT_MAX;
                for( int k = M[i-1]; k <= MX; ++k )
                    DP[i][j] <?= ( DP[i-1][k] + cost( k, j ) );
            }
        }
        
        int ans = INT_MAX;
        for( int k = M[N]; k <= MX; ++k )
            ans <?= DP[N][k];
            
        cout << ans << endl;
            
    } 
    
} 
 
