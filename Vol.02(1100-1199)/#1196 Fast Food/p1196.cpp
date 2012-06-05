// 2939471 2008-06-01 23:57:15 Accepted 1196 C++ 00:00.02 1024K 呆滞的慢板 

// DP !!! O(n^3)
// DP[k][n]: 表示从左手边起的 n 个站时，有 k 个快餐店的结果
// 另外要打一个表: DIS[i][j] 表示在第 i 个到第 j 个站放置 1 个快餐店的花费
// 然后有: DP[k][n] = min( DP[k-1][t] + DIS[t][n] ),  ( k <= t <= n )

#include <iostream>
using namespace std;

int A[200], N,  K,  T = 0;
int DP[31][201],    DIS[200][200];

int main() {
    
    while( cin >> N >> K && N ) {
        
        for( int i = 0; i < N; ++i )
            cin >> A[i];
        
        for( int i = 0; i < N; ++i ) {
            for( int j = i; j < N; ++j ) {
                int x = i,  y = j;
                DIS[i][j] = 0;
                while( x < y )
                    DIS[i][j] += ( A[y--] - A[x++] );
            }
        }

    #ifndef ONLINE_JUDGE
    for( int i = 0; i < N; ++i ) {
        for( int j = 0; j < N; ++j )
            printf( "%3d", DIS[i][j] );
        puts( "" );
    }
    #endif

        for( int i = 1; i <= N; ++i )
            DP[1][i] = DIS[0][i - 1];
            
        for( int i = 2; i <= K; ++i ) {
            for( int j = i; j <= N; ++j ) {
                DP[i][j] = 0x7FFFFFFF;
                for( int k = i - 1; k < j; ++k ) {
                    if( DP[i-1][k] + DIS[k][j-1] < DP[i][j] )
                        DP[i][j] = DP[i-1][k] + DIS[k][j-1]; 
                }
            }
        }

    #ifndef ONLINE_JUDGE
    puts( "" );
    for( int i = 0; i <= K; ++i ) {
        for( int j = 0; j <= N; ++j )
            printf( "%3d", DP[i][j] );
        puts( "" );
    }
    #endif

        cout << "Chain " << ++T << endl;
        cout << "Total distance sum = " << DP[K][N] << endl << endl;
        
    }

}
