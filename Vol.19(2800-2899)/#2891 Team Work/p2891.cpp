// 2963126 2008-07-05 23:47:35 Accepted 2891 C++ 00:06.26 844K 呆滞的慢板 

// bt++ 的搜索
// 基本是 DFS，然后先枚举长度（从大到小）
// 然后判别，标记上用排列，n!可以，标记禁止的长度 
 
// 注意题意：1. 必须由两根以上拼接
//           2. 不可以有开断相同的地方 
 
#include <cstdio>
#include <bitset> 
#include <map> 
using namespace std; 

int     N,  tot_len,    len;
bool    C[250]; // 标记禁止长度 
bitset<250> B;
map<int, int>   M; 

typedef map<int, int>::iterator Iter; 

// 前置判定，用的是背包 DP
// 能够构成 3 个棍子的，必须部分和能达到 
//      B[len]，B[2*len]，B[3*len] 
bool pred() {
    return  B[len] && B[len * 2] && B[len * 3];
} 

// 精准搜索，x 代表剩余棍子数，y 代表当前棍子长度 
bool DFS( int x, int y ) {

    if( x == 0 )    return  true;
    
    for( Iter it = M.begin(); it != M.end(); ++it ) {
        // 标记下戳位置，退栈用 
        int tick = y + it -> first;
        if( !it -> second ) continue; 
        if( C[tick] )       continue;
        if( tick > len )    continue;
        if( y == 0 && tick == len ) continue;
        if( tick == len ) {
            --it -> second;
            if( DFS( x - 1, 0 ) ) {
                ++it -> second;
                return  true;
            }
            ++it -> second;
            continue;
        }
        C[tick] = true;
        --it -> second;
        if( DFS( x, tick ) ) {
            ++it -> second;
            C[tick] = false;
            return  true;
        }
        ++it -> second;
        C[tick] = false;
    }
    
    return  false;

} 

int main() {
    
    int T = 0; 
    
    while( scanf( "%d", &N ) && N ) {
        
        tot_len = 0; 
        M.clear();
        B.reset();
        B.set( 0 );
        
        for( int i = 0; i < N; ++i ) {
            int temp; 
            scanf( "%d", &temp );
            tot_len += temp;
            ++M[temp];
            B |= ( B << temp );
        }
        
        printf( "Case %d: ", ++T ); 
        
        bool    found = false; 
        
        for( len = tot_len / 3; len > M.begin() -> first; --len ) {
            
            // 前置剪枝 
            if( !pred() )  continue;
            
            memset( C, 0, sizeof( C ) );
            
            if( DFS( 3, 0 ) ) {
                found = true;
                printf( "%d\n", len );
                break; 
            }
        
        } 
        
        if( !found )    puts( "0" );
        
    }
    
} 

