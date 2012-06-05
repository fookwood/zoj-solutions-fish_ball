// 3007041 2008-07-26 19:13:13 Accepted 3008 C++ 00:00.00 840K 呆滞的慢板 

// 先把 n^m 分解成素数的因子，然后 DFS 这些素数的组合
// 得到所有可能的分拆 

#include <iostream>
#include <vector>
using namespace std;

int M,  N,  K;
vector<int>         V;
vector<long long>   P;

int         tot;

void DFS( int x, long long val ) {
    if( val > K )   return;
    if( x == V.size() ) { ++tot;  return; }
    DFS( x + 1, val );
    for( int i = 0; i < V[x]; ++i ) {
        val *= P[x];
        if( val > K )   return;
        DFS( x + 1, val );
    }
}

int main() {
    
    while( cin >> M >> N ) {
    
        V.clear();
        P.clear();
        
        if( M == 1 ) {
            puts( "1" );
            continue;
        }
        
        K = M; 
        for( int i = 2; i * i <= M; ++i ) {
            if( M == 1 ) break;
            if( M % i == 0 ) {
                V.push_back( 0 );
                P.push_back( i );
                while( M % i == 0 ) {
                    V.back() += N;
                    M /= i;
                }
            }
        }
        
        if( M != 1 ) {
            V.push_back( N );
            P.push_back( M );
        }
        
        #ifndef ONLINE_JUDGE
            for( int i = 0; i < V.size(); ++i )  cout << P[i] << ' ';puts( "" );
            for( int i = 0; i < V.size(); ++i )  cout << V[i] << ' ';puts( "" );
        #endif
        
        tot = 0;
        
        DFS( 0, 1 );
        
        cout << tot << endl;
    
    }
    
    
}
