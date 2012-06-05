// 3038302 2008-08-16 21:49:19 Accepted 3017 C++ 00:00.12 1308K 呆滞的慢板 

// 记忆化 BFS，状态由所在城堡、所在楼层以及剩余魔法构成。 

#include <deque>
#include <iostream>
using namespace std;

struct Status {
    int csl, lvl, mna;
    Status( int c, int l, int m ) :
        csl( c ), lvl( l ), mna( m ) {}
};

deque<Status>   Q;

int DP[10][100][101];

int N,  M,  Z,  T;

int S[10][100];

int G[10][10];

int main() {
    
    for( cin >> T; T--; ) {
        
        cin >> N >> M >> Z;
        
        for( int i = 0; i < M; ++i )
            for( int j = 1; j < N; ++j )
                cin >> S[i][j];
                
        for( int i = 0; i < M; ++i )
            for( int j = 0; j < M; ++j )
                cin >> G[i][j];
                
        memset( DP, -1, sizeof( DP ) );
        
        Q.clear();
        
        DP[0][0][Z] = 0;
        Q.push_back( Status( 0, 0, Z ) );
        
        int *target, *source;
        
        int ans = INT_MAX;
        
        while( !Q.empty() ) {
            
            Status  now = Q.front();
            Q.pop_front();
            
            source = &DP[now.csl][now.lvl][now.mna];
            
            if( now.lvl == N - 1 ) {
                ans <?= *source;
                continue;
            }
            
            for( int i = 0; i < M; ++i ) {
                if( i == now.csl || now.mna < G[now.csl][i] )
                    continue;
                now.mna -= G[now.csl][i];
                target = &DP[i][now.lvl][now.mna];
                if( *target == -1 || *target > *source ) {
                    *target = *source;
                    Q.push_back( Status( i, now.lvl, now.mna ) );
                }
                now.mna += G[now.csl][i];
            }
            
            target = &DP[now.csl][++now.lvl][now.mna];
            if( *target == -1 ||
                *target > *source + S[now.csl][now.lvl] ) {
                *target = *source + S[now.csl][now.lvl];
                Q.push_back( now );
            }
            
        }
        
        cout << ans << endl;
        
    }
    
}
