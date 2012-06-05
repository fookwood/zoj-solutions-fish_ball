// 2946394 2008-06-10 00:46:17 Accepted 2412 C++ 00:00.01 844K ´ôÖÍµÄÂý°å 

// DFS...

#include <iostream>
using namespace std;

int     M,  N;

char    A[50][51];
bool    B[50][50]; 

bool    C[11][4] = {
    { 1,  1,  0,  0 },
    { 0,  1,  1,  0 }, 
    { 1,  0,  0,  1 },
    { 0,  0,  1,  1 },
    { 0,  1,  0,  1 },
    { 1,  0,  1,  0 },
    { 1,  1,  1,  0 },
    { 1,  1,  0,  1 },
    { 1,  0,  1,  1 },
    { 0,  1,  1,  1 },
    { 1,  1,  1,  1 }
};

int D[4][2] = {
    {  0, -1 },  // ×ó 
    { -1,  0 },  // ÉÏ 
    {  0,  1 },  // ÓÒ 
    {  1,  0 }   // ÏÂ 
};


inline bool isValid( int x, int y ) {
    return  x >= 0 && x < M &&
            y >= 0 && y < N;
}

void DFS( int x, int y ) {

    B[x][y] = true;
    
    for( int i = 0; i < 4; ++i ) {
        if( C[A[x][y]-'A'][i] &&
            isValid( x+D[i][0], y+D[i][1] ) &&
            !B[x+D[i][0]][y+D[i][1]] &&
            C[A[x+D[i][0]][y+D[i][1]]-'A'][i^2] ) {
            DFS( x+D[i][0], y+D[i][1] );
        }
    }

}

int main() {
    
    while( cin >> M >> N && M >= 0 )  {
        
        memset( B, 0, sizeof( B ) );
        
        for( int i = 0; i < M; ++i )
            cin >> A[i]; 
        
        int     ans = 0;
        
        for( int i = 0 ;i < M; ++i ) {
            for( int j = 0; j < N; ++j ) {
                if( !B[i][j] ) {
                    ++ans;
                    DFS( i, j );
                } 
            } 
        } 
        
        cout << ans << endl;
        
    }
    
}
