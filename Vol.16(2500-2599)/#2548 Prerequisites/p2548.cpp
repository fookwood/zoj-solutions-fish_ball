// 2960121 2008-07-02 22:06:58 Accepted 2548 C++ 00:00.19 408K 呆滞的慢板 

// 菜题一道，直接寻址就行了，因为只有 10000 个课程。
// 但是注意不要用 iostream，会 TLE 

#include <cstdio>
#include <cstring>

bool    B[10000];

int main() {
    
    int x,  y,  z,  w;
    
    while( scanf( "%d", &x ) && x ) {
        
        scanf( "%d", &y );
        
        memset( B, 0, sizeof( B ) );
        for( int i = 0; i < x; ++i ) {
            scanf( "%d", &z );
            B[z] = true;
        }
        
        bool    yes = true;
        for( int i = 0; i < y; ++i ) {
            int cnt = 0;
            scanf( "%d%d", &x, &z );
            for( int j = 0; j < x; ++j ) {
                scanf( "%d", &w );
                if( B[w] )  ++cnt;
            }
            if( cnt < z )
                yes = false;
        }
        
        puts( yes ? "yes" : "no" );
        
    }
    
}
