// 3022225 2008-08-05 10:28:12 Accepted 1140 C++ 00:00.82 872K 呆滞的慢板 

// 求最大匹配，标准 Hungarian 算法
 
#include <iostream>
#include <vector>
using namespace std; 

#define clr( x ) memset( x, 0, sizeof( x ) ); 

int     P,  N,  T; 

bool    G[101][301];

int     BK[301];
bool    BM[301]; 

bool out( int );

bool in( int x ) {
    for( int i = 1; i <= N; ++i ) {
        if( G[x][i] && !BM[i] ) {
            BM[i] = true;
            if( !BK[i] || in( BK[i] ) ) {
                BK[i] = x;
                return  true;
            }
        }
    } 
    return  false;
} 


int main() {
    
    for( scanf( "%d", &T ); T--; ) {
        
        scanf( "%d%d", &P, &N );
        
        clr( G );
        clr( BK );
        
        for( int i = 1; i <= P; ++i ) {
            int k,  x;
            for( scanf( "%d", &k ); k--; ) {
                scanf( "%d", &x );
                G[i][x] = true; 
            }
        }
        
        bool  yes = true;
        for( int i = 1; i <= P; ++i ) {
            clr( BM );
            if( !in( i ) ) {
                yes = false;
                break;
            }
        }
        
        puts( yes ? "YES" : "NO" );
                 
    } 
    
} 
