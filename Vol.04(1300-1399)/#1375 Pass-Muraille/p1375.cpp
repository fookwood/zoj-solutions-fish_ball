// 2976971 2008-07-14 14:04:30 Accepted 1375 C++ 00:00.01 848K 呆滞的慢板 

// 简单贪心，由于 n <= 100，再烂的 O(n^3) 也不会挂 

#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;

int main() {
    
    int T,  N,  K,  M;
    int H[101], cnt;
    
    vector<pair<int, int> > V; 
    
    for( cin >> T; T--; ) {
        
        cin >> N >> K;
        
        M = 0;
        V.clear(); 
        cnt = 0; 
        memset( H, 0, sizeof( H ) );
        
        for( int i = 0; i < N; ++i ) {
            int x1, x2, y;
            cin >> x1 >> y >> x2 >> y;
            if( x1 > x2 )
                swap( x1, x2 );
            for( int j = x1; j <= x2; ++j )
                ++H[j];
            V.push_back( make_pair( x1, x2 ) ); 
        }
        
        for( int i = 0; i <= 100; ++i ) {
            while( H[i] > K ) {
                int pos = -1,    mx = -1;
                for( int j = 0; j < V.size(); ++j ) {
                    if( V[j].first <= i && V[j].second > mx ) {
                        mx = V[j].second;
                        pos = j; 
                    }
                }  
                ++cnt; 
                for( int x = i; x<= V[pos].second; ++x )
                    --H[x];
                swap( V[pos], V.back() );
                V.pop_back();
            }
        }
        
        cout << cnt << endl; 
        
    }
    
}
