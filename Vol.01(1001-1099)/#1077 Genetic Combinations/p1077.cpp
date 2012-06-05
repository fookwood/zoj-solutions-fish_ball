// matching !!

#include <cstdio>
#include <cstring> 

int main() {
    
    // N 为数据规模，T 为档案序号 
    int    N,    T = 1;
    
    // A 及 B 为字符串数组，储存输入档案 
    char    A[64][5],    B[64][5];
    
    // test为临时译码表，itest为临时反向译码表，code为最终译码表 
    char    test[20],    itest[20],    code[20];
    
    // 匹配序号逻辑表 ( 4 * 4 ) 矩阵 
    // 例如 match[0][2] = 1 代表第1个位置大写字母，与第3个位置小写字母匹配 
    int    match[4][4];
    
    while( scanf( "%d", &N ) && N ) {
        
        printf( "Test #%d:\n", T++ );
        
        // 数据输入 
        for( int i = 0; i < N; i++ )    scanf( "%s", A[i] );
        for( int i = 0; i < N; i++ )    scanf( "%s", B[i] );
        
        // 对于每一组档案，只有一个匹配表，事先归零 
        memset( match, 0, 16 * sizeof( int ) );
        
        // m, n 为第 m 个大写字母试图与第 n 个小写字母匹配 
        for( int m = 0; m < 4; m++ ) {
            
            for( int n = 0; n < 4; n++ ) {
                // 采用矛盾否定的方式 
                bool    fit = 1;
            
                // 初始化临时译码表，0代表未出现 
                memset( test, 0, 20 );
                memset( itest, 0, 20 );
            
                for( int j = 0; j < N; j++ ) {
                    // 如果第 j 组数据译码吻合，直接通过 
                    if( test[A[j][m] - 'A'] == B[j][n] )    continue;
                    // 如果双向均未被标记则双向标记之 
                    if( !test[A[j][m] - 'A'] && !itest[B[j][n] - 'a'] ) {
                        test[A[j][m] - 'A'] = B[j][n];
                        itest[B[j][n] - 'a'] = A[j][m];
                    }
                    // 否则就是矛盾，立刻否定 
                    else { fit = 0; break; }
                }
                
                // 如果匹配 
                if( fit ) {
                    // 在匹配矩阵中记录该位置 
                    match[m][n] = 1;
                    // 将该位置的临时译码表转移到最终译码表 
                    for( int j = 0; j < 5; j++ )
                        code[j + m * 5] = test[j + m * 5];
                }
            }
        }
        
        // 自此所有可能的匹配已经遍历
        // 如果有多匹配的情况则是不确定的，对整组 5 个字母都置为未知 
        for( int m = 0; m < 4; m++ )
            if( match[m][0] + match[m][1] + match[m][2] + match[m][3] != 1 )
                for( int j = 0; j < 5; j++ )
                    code[j + m * 5] = 0;
        
        // 如果在某一组内已经知道了其中 4 个字母匹配，那么第 5 个字母的译码也可推知 
        for( int x = 0; x < 20; x += 5 ) {
        
            // 匹配字母个数的计数 
            int    total = 0,    p,    q;
        
            // 字母对应逻辑表
            bool    v[2][5];
        
            memset( v, 0, 10 * sizeof( bool ) );
            for( int y = 0; y < 5; y++ ) {
        
                if( code[x + y] ) {
        
                    q = ( code[x + y] - 'a' ) / 5;
                    total ++;
                    v[0][y] = true;
                    v[1][( code[x + y] - 'a' ) % 5] = true; 
        
                }
        
                else            p = y;
        
            } 
        
            if( total == 4 )
                for( int r = 0; r < 5; r++ )
                    if( !v[1][r] )
                        code[x + p] = 'a' + q * 5 + r;
        
        }
        // 输出结果
        for( int i = 0; i < 20; i++ ) {
        
            printf( "%c-%c", char( 'A' + i ), code[i] ? code[i] : '?' );
        
            if( i % 5 == 4 )    putchar( '\n' );
        
            else             putchar( ' ' ); 
        
        }
    
    }
     
} 
