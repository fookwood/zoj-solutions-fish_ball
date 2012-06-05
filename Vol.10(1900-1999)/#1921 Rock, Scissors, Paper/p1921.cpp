// 3013377 2008-07-30 09:38:15 Accepted 1921 C++ 00:01.35 860K 呆滞的慢板 

// 简单模拟，对于每一个格子，只要他周围有一个格子能赢他
// 那个格子就更新成赢他的格子，否则不更新 

#include <iostream>
#include <algorithm>
using namespace std;

char    A[102][102], B[102][102];
char    (*X)[102] = A, (*Y)[102] = B;

int     M,  N,  D,  T;

char be_win( char c ) {
    switch( c ) {
        case 'R':   return 'P';
        case 'S':   return 'R';
        case 'P':   return 'S';
    }
    return  0;
}

int DIR[4][2] = {
    { 0, 1 },
    { 0,-1 },
    {-1, 0 },
    { 1, 0 }
};

int main() {
    
    for( cin >> T; T--; ) {
        
        cin >> M >> N >> D;
        
        memset( X, 0, sizeof( X ) );
        
        for( int i = 1; i <= M; ++i )
            cin >> X[i] + 1;
        
        while( D-- ) {
            for( int i = 1; i <= M; ++i ) {
                for( int j = 1; j <= N; ++j ) {
                    Y[i][j] = X[i][j];
                    for( int k = 0; k < 4; ++k )
                        if( X[i+DIR[k][0]][j+DIR[k][1]] == be_win( X[i][j] ) )
                            Y[i][j] = be_win( X[i][j] );
                }
            }
            swap( X, Y );
        }
        
        for( int i = 1; i <= M; ++i )
            puts( X[i]+1 );
            
        if( T ) puts( "" );
        
    }
    
}
