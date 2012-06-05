// 2967675 2008-07-09 11:23:35 Accepted 1798 C++ 00:00.00 864K 呆滞的慢板 

// 求哈密顿回路存在性，NP
// 还好规模奇小，直接 DFS 蛮搞 

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool    G[11][11];
bool    B[11]; 
int     N,  T;

bool Hamilton( int v, int r ) {
    
    if( v == 0 && r == 0 )  return  true;
    
    for( int i = 0; i <= N; ++i ) {
        if( !B[i] && G[v][i] ) {
            B[i] = true;
            if( Hamilton( i, r - 1 ) )
                return  true;
            B[i] = false;
        }
    }
    
    return  false;
    
}

int main() {
    
    T = 0;
    
    while( cin >> N && N ) {
        
        string  input;
        getline( cin, input );
    
        memset( G, 0, sizeof( G ) );
        memset( B, 0, sizeof( B ) );
        
        for( int i = 1, j; i <= N; ++i ) {
            getline( cin, input );
            istringstream   is( input );
            while( is >> j )
                G[i][j] = G[j][i] = true;
        }
        
        printf( "Case %d: ", ++T );
        puts( Hamilton( 0, N + 1 ) ?
              "Granny can make the circuit." :
              "Granny can not make the circuit." );
    
    }
    
}
