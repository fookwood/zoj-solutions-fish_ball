// 2955074 2008-06-23 01:10:37 Accepted 2955 C++ 00:00.08 876K 呆滞的慢板 

// 很好的数论题，首先，将 10000 以内的结果 DP 出来
// 方法很明显，标记 DP[i] 为结果，如果不存在则为 -1 
// 枚举 i = 1~10000
// 其中可以选择的数为 SC[j]
// 如果 DP[i-SC[j]] 不是 -1，那么刷新这个值为最小的 DP[i-SC[j]] + 1
// 这个表要打出来最坏要 10000 * 100 次运算

// 然后当 N > 10000 的时候，枚举 x = 1~10000
// 则将 N 表示成 N = k * x + y (k = N / x, y = N % x)
// 这时候，共需要 k * DP[x] + DP[y] 次
// 然后，枚举 x = 1~10000，取最优值即可

// 至于为什么 10000 以内就保证算法正确...这个没证过...但这是可以证明的... 

#include <iostream>
#include <algorithm>
using namespace std;

int     DP[10001];
int     SC[100],    M,  N,  T;

int main() {
    
    for( cin >> T; T--; ) {
        
        memset( DP, -1, sizeof( DP ) );
        DP[0] = 0;
        
        cin >> M >> N;
        int top = min( N, 10000 );
        
        for( int i = 0; i < M; ++i )
            cin >> SC[i];
        
        sort( SC, SC + M );
        
        for( int i = 1; i <= top; ++i ) {
            for( int j = 0; j < M; ++j ) {
                if( i < SC[j] )    break;
                if( DP[i-SC[j]] != -1 ) {
                    if( DP[i] == -1 || DP[i] > DP[i-SC[j]] + 1 )
                        DP[i] = DP[i-SC[j]] + 1;
                }
            }
        }
        
        if( N <= 10000 ) {
            cout << DP[N] << endl;
            continue;
        }
        
        int ans = -1;
        for( int i = 1; i <= 10000; ++i ) {
            if( DP[i] != -1 && DP[N % i] != -1 ) {
                if( ans == -1 || ans > ( N / i ) * DP[i] + DP[N % i] ) 
                    ans = ( N / i ) * DP[i] + DP[N % i];
            }
        }
        
        cout << ans << endl;
        
    }
    
}
