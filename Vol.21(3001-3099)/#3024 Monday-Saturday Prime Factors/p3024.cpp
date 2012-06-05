// 3059402 2008-09-04 15:58:58 Accepted 3024 C++ 00:00.23 19436K 呆滞的慢板 

// 正解：筛法，筛的过程中保存所有因子

#include <cstdio>

bool    mark[300000] = {};
int     cnt[300000] = {};
int     factor[300000][15]; 

int main() {
    
    for( int i=6, d=2; i<300000; i+=d, d=7-d ) {
        if( !mark[i] ) {
            for( int j = i; j < 300000; j += i ) {
                mark[j] = true;
                factor[j][cnt[j]++] = i;
            }
        }
    }
    
    int x;
    while( scanf( "%d", &x ) && x != 1 ) {
        printf( "%d:", x );
        for( int i = 0; i < cnt[x]; ++i )
            printf( " %d", factor[x][i] );
        puts( "" );
    }
    
} 
