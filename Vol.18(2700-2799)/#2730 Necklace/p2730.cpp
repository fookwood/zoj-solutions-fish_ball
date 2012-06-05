// 2937887 2008-05-31 01:25:01 Accepted 2730 C++ 00:00.03 916K 呆滞的慢板 

// 贪心很难证明，直接 DFS 所有状态就好了 

#include <iostream>
#include <vector>
using namespace std;

bool    A[49][49];
vector<int> P;
int     N,  M;

bool DFS( int R, int X ) {
    if( R == 1 )    return  true;
    bool    ans = false;
    for( int i = 0; i < N; ++i ) {
        if( !A[i][X] ) {
            A[i][X] = A[X][i] = true;
            P.push_back( i );
            if( DFS( R - 1, i ) )
                return  true;
            P.pop_back();
            A[i][X] = A[X][i] = false;
        }
    }
    return  false;
}

int main() {
    
    while( cin >> N ) {
        
        M = N * ( N - 1 ) / 2;
        
        cout << M << endl;
        
        memset( A, 0, sizeof( A ) );
        for( int i = 0; i < N; ++i )
            A[i][i] = true;
                
        P.clear();
        
        P.push_back( 0 );
        
        DFS( M, 0 );
        
        cout << P[0];
        
        for( int i = 1; i < P.size(); ++i )
            cout << ' ' << P[i];
            
        cout << endl;
        
    }
    
}
