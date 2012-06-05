// 2892015 2008-05-05 22:17:45 Accepted 2554 C++ 00:00.02 1960K 呆滞的慢板 

// 显然，蛮力算法已经到达了下界，这已经是最快的了，肉题 

#include <cstdio>

int X[200000],  Y[200000],  N;

int main() {
    
    while( scanf( "%d", &N ) && N ) {
        
        for( int i = 0; i < N; ++i )
            scanf( "%d%d", X + i, Y + i );
        
        int S = 0,  O = 0;
        int XX = X[N / 2],  YY = Y[N / 2];
        
        for( int i = 0; i < N; ++i ) {
            if( X[i] == XX || Y[i] == YY )
                continue;
            if( ( X[i] > XX ) ^ ( Y[i] > YY ) )
                    ++O;
            else    ++S;
        }
        
        printf( "%d %d\n", S, O );
        
    }
    
}
