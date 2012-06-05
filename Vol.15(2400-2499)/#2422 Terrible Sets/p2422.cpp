// 3020837 2008-08-04 14:29:08 Accepted 2422 C++ 00:00.22 1628K ´ôÖÍµÄÂý°å 

// 1985 µÄÉý¼¶°æ£¬DP 

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int N,  W[50002], H[50002], L[50002], R[50002];

vector<int> stk;

int main() {
    
    while( cin >> N && N >= 0 ) {
        
        for( int i = 1; i <= N; ++i )
            scanf( "%d%d", W + i, H + i );
            
        W[0] = W[N + 1] = 1;
        H[0] = H[N + 1] = -1;
        
        partial_sum( W, W + N + 2, W );

        stk.assign( 1, 0 );
        L[0] = 0;
        for( int i = 1; i <= N; ++i ) {
            while( H[stk.back()] >= H[i] )
                stk.pop_back();
            L[i] = W[stk.back()];
            stk.push_back( i );
        }
        
        stk.assign( 1, N+1 );
        R[N+1] = W[N];
        for( int i = N; i > 0; --i ) {
            while( H[stk.back()] >= H[i] )
                stk.pop_back();
            R[i] = W[stk.back() - 1];
            stk.push_back( i );
        }
        
        int mx = 0;
        for( int i = 1; i <= N; ++i )
            mx >?= ( R[i] - L[i] ) * H[i];
        
        cout << mx << endl;
        
    }
    
}
