// 2939590 2008-06-02 11:53:34 Accepted 1995 C++ 00:00.03 5740K 呆滞的慢板 

// DP !!!! 在线刷新 + 路径保存 

#include <iostream>
#include <algorithm>
using namespace std;

int     A[1001];
int     DP[1001][1001];     // DP[i][j], 第 i 次到达高度 j 的最小总高度 
char    PV[1001][1001];     // 第 i 次到达高度 j 的前一个状态
char    C[1001];            // 输出字符串 
int     T,  N;
    

int main() {
    
    
    for( cin >> T; T--; ) {
        
        cin >> N;
        
        int tot = 0;
        for( int i = 0; i < N; ++i ) {
            cin >> A[i];
            tot += A[i];
        }
        
        if( tot % 2 ) {
            puts( "IMPOSSIBLE" );
            continue;
        }
        
        tot /= 2;
        for( int i = 0; i <= N; ++i )
            for( int j = 0; j <= tot; ++j )
                DP[i][j] = 2000;
        
        DP[0][0] = 0;
        
        for( int i = 0; i < N; ++i ) {
            for( int j = 0; j <= tot; ++j ) {
                if( DP[i][j] == 2000 )
                    continue;
                if( j >= A[i] && DP[i+1][j-A[i]] > DP[i][j] ) {
                    DP[i+1][j-A[i]] = DP[i][j];
                    PV[i+1][j-A[i]] = 'D';
                }
                if( j + A[i] <= tot &&
                    DP[i+1][j+A[i]] > max( j + A[i], DP[i][j] ) ) {
                    DP[i+1][j+A[i]] = max( j + A[i], DP[i][j] );
                    PV[i+1][j+A[i]] = 'U';
                }
            }
        }
        
        #ifndef ONLINE_JUDGE
        for( int i = 0; i <= tot; ++i ) {
            for( int j = 0; j <= N; ++j )
                printf( "%5d", DP[j][i] );
            cout << endl;
        }
        #endif
        
        if( DP[N][0] == 2000 ) {
            puts( "IMPOSSIBLE" );
            continue;
        }
        
        C[N] = '\0';
        int pos = 0;
        for( int i = N-1; i >= 0; --i ) {
            C[i] = PV[i+1][pos];
            pos += ( PV[i+1][pos] == 'U' ? -A[i] : A[i] );
        } 

        puts( C );
        
    }
    
}
