// 2951295 2008-06-17 09:25:21 Accepted 1948 C++ 00:00.24 2448K 呆滞的慢板 

// 队列套队列~~ 耗时的在于 map，原来的一直 RTE 只好重写，就好了... 

#include <deque>
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    
    int     T,  N,  M,  C = 1;
    
    char    input[10];
    
    deque<int>  P[1000],    Q;
    
    map<int, int>   L;
    
    while( scanf( "%d", &T ) && T ) {
        
        L.clear();
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
