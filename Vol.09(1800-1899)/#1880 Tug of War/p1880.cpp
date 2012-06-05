// 3049902 2008-08-25 14:45:02 Accepted 1880 C++ 00:04.05 9624K 呆滞的慢板 

// 背包扩展... 使用 N 个数的时候可以达到的值 

#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

int     N,  S,  X,  T;

set<int>            A[52];
set<int>::iterator  iter;

int main() {
    
    while( scanf( "%d", &N ) != EOF ) {
        
        for( int i = 0; i <= N / 2 + 1; ++i )
            A[i].clear();
            
        A[0].insert( 0 );
        
        for( int i = S = T = 0; i < N; ++i ) {
            scanf( "%d", &X );
            S += X;
            for( int i = min( T++, N / 2 ); i >= 0; --i )
                for( iter = A[i].begin(); iter != A[i].end(); ++iter )
                    A[i+1].insert( *iter + X );
        }
        
        int x = *A[N/2].begin();
        
        for( iter = A[N/2].begin(); iter != A[N/2].end(); ++iter )
            if( abs( 2 * *iter - S ) < abs( 2 * x - S ) )
                x = *iter;
        
        cout << min( x, S - x ) << ' ' << max( x, S - x ) << endl;
        
    }
    
}
