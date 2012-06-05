// 3043265 2008-08-20 16:41:03 Accepted 1692 C++ 00:00.00 836K 呆滞的慢板 

// 霸王硬上弓，对待数据小的题不要心软... 

#include <iostream>
using namespace std;

int     C[10][10];
bool    B[10][10];

int N,      X;

int cnt,    tot,    now;

int dx[6] = { -1, -1,  0, 0, 1, 1 };
int dy[6] = { -1,  0, -1, 1, 0, 1 };

bool DFS( int x, int y ) {
    B[x][y] = true;
    cnt += 1;
    bool    ret = true;
    for( int i = 0; i < 6; ++i ) {
        x += dx[i]; y += dy[i];
        if( x >= 0 && x < N && y >= 0 && y <= x && !B[x][y] ) {
            if( C[x][y] == 0 )                      ret = false;
            if( C[x][y] == now && !DFS( x, y ) )    ret = false;
        }
        x -= dx[i]; y -= dy[i];
    }
    return  ret ? true : ( cnt = 0 );
}

int main() {
    
    while( cin >> N >> X && N ) {
        
        for( int i = 0; i < N; ++i )
            for( int j = 0; j <= i; ++j )
                cin >> C[i][j];
        
        int mx = INT_MIN;
        
        for( int i = 0; i < N; ++i ) {
            for( int j = 0; j <= i; ++j ) {                
                if( C[i][j] == 0 ) {
                    C[i][j] = X;
                    memset( B, 0, sizeof( B ) );
                    tot = 0;
                    for( int x = 0; x < N; ++x ) {
                        for( int y = 0; y <= x; ++y ) {
                            if( !B[x][y] && C[x][y] ) {
                                cnt = 0;
                                now = C[x][y];
                                DFS( x, y );
                                if( now == X )
                                        tot -= cnt;
                                else    tot += cnt;
                            }
                        }
                    }

                    C[i][j] = 0;
                    if( tot > mx )  mx = tot;
                }
            }
        }
        
        cout << mx << endl;
        
    }
    
}
