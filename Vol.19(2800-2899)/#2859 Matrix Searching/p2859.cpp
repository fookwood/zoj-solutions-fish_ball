// 3034351 2008-08-13 23:42:55 Accepted 2859 C++ 00:01.96 29508K 呆滞的慢板 

// 二维 RMQ，二维的 ST 算法，注意枚举次序 

#include <iostream>
#include <algorithm>
using namespace std;

int     A[9][9][301][301];

int     T,  N,  Q,  i,  j;

int     m,  n,  m_2,    n_2;

int     xx1, yy1, xx2, yy2, s1, s2, ans;

int main() {
    
    for( cin >> T; T--; ) {
        
        cin >> N;
        
        for( i = 0; i < N; ++i )
            for( j = 0; j < N; ++j )
                scanf( "%d", &A[0][0][i][j] );

        for( m = 0; ( m_2 = 1<<m ) <= N; ++m )
            for( n = 0; ( n_2 = 1<<n ) <= N; ++n )
                if( m || n ) for( i = 0; i + m_2 <= N; ++i )
                    for( j = 0; j + n_2 <= N; ++j )
                        A[m][n][i][j] = m ?
                            min( A[m-1][n][i][j], A[m-1][n][i+(1<<m-1)][j] ) :
                            min( A[m][n-1][i][j], A[m][n-1][i][j+(1<<n-1)] );

        for( cin >> Q; Q--; ) {
            
            scanf( "%d%d%d%d", &xx1, &yy1, &xx2, &yy2 );
            
            s1 = xx2 - xx1--;
            s2 = yy2 - yy1--;
            
            for( i = 0; 1 << i + 1 <= s1; ++i );
            for( j = 0; 1 << j + 1 <= s2; ++j );
            
            ans =           A[i][j][xx1]       [yy1]         ;
            ans = min( ans, A[i][j][xx2-(1<<i)][yy1]        );
            ans = min( ans, A[i][j][xx1]       [yy2-(1<<j)] );
            ans = min( ans, A[i][j][xx2-(1<<i)][yy2-(1<<j)] );
            printf( "%d\n", ans );
            
        }
        
    }
    
}
