// 3042284 2008-08-19 21:58:30 Accepted 1130 C++ 00:00.03 2800K ´ôÖÍµÄÂý°å 

// DFS

#include <iostream>
#include <vector>
using namespace std;

vector<int> V[16];

bool    B[35000];

int MASK,   now;

bool DFS( int x ) {
    B[x] = true;
    V[now].push_back( x );
    if( V[now].size() == 1 << now ) {
        if( x == 1 << ( now - 1 ) ) return  true;
        V[now].pop_back();
        return  B[x] = false;
    }
    int y = ( x << 1 ) & MASK;
    if( !B[y] && DFS( y ) ||
        !B[y|1] && DFS( y|1 ) ) return  true;
    V[now].pop_back();
    return  B[x] = false;
}

int main() {
    
    for( now = 1; now < 16; ++now ) {
        MASK = ( 1 << now ) - 1;
        V[now].clear();
        memset( B, 0, sizeof( B ) );
        DFS( 0 );
    }
    
    while( cin >> MASK >> now && MASK )
        cout << V[MASK][now] << endl;
    
}
