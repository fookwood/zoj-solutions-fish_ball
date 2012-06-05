// 2951296 2008-06-17 09:28:20 Accepted 1948 C++ 00:00.15 5412K 呆滞的慢板 

// 这是把 map 改掉之后的结果，注意用 iostream 就会超时！ 

#include <deque>
#include <cstdio>
#include <cstring>
using namespace std;

int     T,  N,  M,  C = 1;
    
char    input[10];
    
deque<int>  P[1000],    Q;
    
int     L[1000000];

int main() {
    
    while( scanf( "%d", &T ) && T ) {
        
        Q.clear();
        
        printf( "Scenario #%d\n", C++ );
        
        for( int i = 0; i < T; ++i ) {
            for( scanf( "%d", &N ); N--; ) {
                scanf( "%d", &M );
                L[M] = i;
            }
            P[i].clear();
        }
        
        while( scanf( "%s", input ) ) {
            
            if( input[0] == 'E' ) {
                scanf( "%d", &N );
                M = L[N];
                if( P[M].empty() )
                    Q.push_back( M );
                P[M].push_back( N );
            }
            
            else if( input[0] == 'D' ) {
                M = Q.front();
                printf( "%d\n", P[M].front() );
                P[M].pop_front();
                if( P[M].empty() )
                    Q.pop_front();
            }
            
            else    break;
            
        }
        
        putchar( '\n' );
        
    }
    
}
