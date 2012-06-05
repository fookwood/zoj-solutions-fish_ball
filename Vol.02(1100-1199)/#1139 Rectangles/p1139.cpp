// 3023599 2008-08-05 22:00:32 Accepted 1139 C++ 00:02.68 2056K ´ôÖÍµÄÂı°å 

#include <cstdio>
#include <cstring>

int     N;

int     X1[100000], X2[100000], Y1[100000], Y2[100000];  

bool    B[100000];

inline bool inside( int x, int y ) {
    return  X1[x] >= X1[y] && X2[x] <= X2[y] &&
            Y1[x] >= Y1[y] && Y2[x] <= Y2[y];
}

int main() {
    
    while( scanf( "%d", &N ) != EOF ) {
        
        for( int i = 0; i < N; ++i )
            scanf( "%d%d%d%d", X1+i, X2+i, Y1+i, Y2+i );
            
        memset( B, 0, sizeof( B ) );
            
        for( int i = 0; i < N; ++i ) {
            for( int j = i + 1; j < N; ++j ) {
                if( inside( i, j ) )    B[i] = true;
                if( inside( j, i ) )    B[j] = true;
            }
        }
        
        int cnt = 0;
        for( int i = 0; i < N; ++i )
            cnt += B[i];
        
        printf( "%d\n", cnt );
    
    }
    
}
