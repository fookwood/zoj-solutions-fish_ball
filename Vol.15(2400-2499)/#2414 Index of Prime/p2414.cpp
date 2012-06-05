// 3021324 2008-08-04 16:41:15 Accepted 2414 C++ 00:00.17 488K 呆滞的慢板 

// 类似背包 DP 的做法 

#include <cstdio>
#include <cstring>

bool    isPrime[10001] = {};
int     Prime[1229],   top = 0, x;

int     cnt[10001], pre[10001];

int main() {
    
    for( int i = 2; i <= 100; ++i )
        if( !isPrime[i] )
            for( int j = i + i; j <= 10000; j += i )
                isPrime[j] = true;
                
    for( int i = 2; i < 10000; ++i )
        if( !isPrime[i] )
            Prime[top++] = i;
    
    memset( cnt, -1, sizeof( cnt ) );
    memset( pre, 0, sizeof( pre ) );
    
    for( int i = cnt[0] = 0; i < top; ++i ) {
        for( int j = 0; j + Prime[i] < 10001; ++j ) {
            if( cnt[j] != -1 ) {
                if( cnt[j + Prime[i]] > cnt[j] + 1 ||
                    cnt[j + Prime[i]] == -1 ) {
                    cnt[j + Prime[i]] = cnt[j] + 1;
                    pre[j + Prime[i]] = j;
                }
            }
        }
    }
    
    while( scanf( "%d", &x ) != EOF ) {
        if( x <= 1 )   puts( "0" );
        else {
            printf( "%d\n%d", cnt[x], x - pre[x] );
            while( ( x = pre[x] ) != 0 )
                printf( " %d", x - pre[x] );
            puts( "" );
        }
    }

}

