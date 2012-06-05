// 3036104 2008-08-15 12:01:08 Accepted 2794 C++ 00:00.07 852K 呆滞的慢板 

// 先 BFS，构造图然后 TSP 

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm> 
using namespace std;

char    A[20][21];
int     B[20][20];

int     G[11][11];

int     W,  H;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

vector<pair<int, int> > V;

int ans;

bool    visited[11];

void DFS( int v, int tot, int rem ) {
    if( tot >= ans ) return;
    if( rem == 0 )  ans = min( ans, tot );
    for( int i = 1; i < V.size(); ++i ) {
        if( !visited[i] && G[v][i] != -1 ) {
            visited[i] = true;
            DFS( i, tot + G[v][i], rem - 1 );
            visited[i] = false;
        }
    }
}

int main() {
    
    while( cin >> W >> H && W ) {
        
        V.resize( 1 );
        
        for( int i = 0; i < H; ++i ) {
            cin >> A[i];
            for( int j = 0; j < W; ++j ) {
                if( A[i][j] == 'o' )
                    V[0] = make_pair( i, j );
                if( A[i][j] == '*' )
                    V.push_back( make_pair( i, j ) );
            }
        }

        for( int i = 0; i < V.size(); ++i ) {
            memset( B, -1, sizeof( B ) );
            deque<pair<int, int> >  Q( 1, V[i] );
            B[V[i].first][V[i].second] = 0;
            while( !Q.empty() ) {
                int x = Q.front().first,
                    y = Q.front().second,
                    p = B[x][y];
                Q.pop_front();
                for( int i = 0; i < 4; ++i ) {
                    x += dx[i];
                    y += dy[i];
                    if( x >= 0 && x < H &&
                        y >= 0 && y < W &&
                        B[x][y] == -1 &&
                        A[x][y] != 'x' ) {
                        B[x][y] = p + 1;
                        Q.push_back( make_pair( x, y ) );
                    }
                    y -= dy[i];
                    x -= dx[i];
                }
            }
            for( int j = i; j < V.size(); ++j )
                G[i][j] = G[j][i] = B[V[j].first][V[j].second];
        }
        
        bool    exit = false; 
        for( int i = 0; i < V.size(); ++i )
            for( int j = 0; j < V.size(); ++j ) 
                if( G[i][j] == -1 )
                    exit = true;
        
        if( exit ) { puts( "-1" ); continue; } 
        
        memset( visited, 0, sizeof( visited ) );
        ans = INT_MAX;
        DFS( 0, 0, V.size() - 1 );
        
        cout << ans << endl;
        
    }
    
}
