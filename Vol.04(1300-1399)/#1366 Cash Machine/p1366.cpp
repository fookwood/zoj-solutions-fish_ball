// 2941329 2008-06-04 01:18:25 Accepted 1366 C++ 00:02.70 880K 呆滞的慢板 

// 典型背包 DP，用了位运算 bitset 来搞 

#include <iostream>
#include <bitset>
using namespace std;

bitset<100000>  DP;

int main() {
    
    int     cash,   N,  n,  D;
    
    while( scanf( "%d", &cash ) != EOF ) {
        
        DP.reset();
        DP.set( 0 );
        for( scanf( "%d", &N ); N--; ) {
            for( scanf( "%d%d", &n, &D ); n--; )
                DP |= ( DP << D );
        }
        
        for( int i = cash; i >= 0; --i ) {
            if( DP[i] ) {
                printf( "%d\n", i );
                break;
            }
        }
        
    }
    
}
