// 3035308 2008-08-14 18:50:47 Accepted 1229 C++ 00:00.06 840K 呆滞的慢板 

// 经典 DP
// 但是这道题很 WS，N 是 1e6 的规模的，怎么搞都会超时
// 然而网上有一个结论：N > 50 时，肯定可以，至于其正确性与证明方法

// 都是空白... 相当 WS 

#include <iostream>
#include <bitset>
using namespace std;

bitset<50>  B,  C;

int     M,  N;

int main() {
    
    while( cin >> N >> M && N ) {
        
        if( N > 50 ) { puts( "Let me try!" ); continue; }

        C.reset();
        for( int i = 0; i < N; ++i )
            C.set( i );
        
        B = 1;
        
        int pos = 3;
        while( B.any() && !B[M - 1] ) {
            B = C & ( ( B << pos ) | ( B >> pos ) );
            pos += 2;
        }
        
        puts( B[M - 1] ? "Let me try!" : "Don't make fun of me!" );
        
    }
    
}
