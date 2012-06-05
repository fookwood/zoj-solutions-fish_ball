// 3032906 2008-08-13 00:50:58 Accepted 1351 C++ 00:00.01 848K 呆滞的慢板 

// 恶心模拟题，规则不说清 

// 例如：密码是 PPABC 
// 猜           PDPPP
// 返回         P.p.. 
// 先匹配完大写字母，然后，匹配的小写字母这样处理
// 总的来说一个字母的大小写数量不能超过密码中该字母出现的数量 
// 从前到后，如果没有超过，返回该小写字母，否则，返回 . 

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm> 
using namespace std;

char    X[6],   S[6],   A[6]; 

int     cnt; 
char    V[100][100]; 

int     C[26];
int     B[26];

int main() {

    while( cin >> X && strcmp( X, "LINGO" ) ) {
        
        puts( "" ); 
        
        cnt = 0; 
        gets( S );
        
        while( gets( S ) && strlen( S ) )
            strcpy( V[cnt++], S );
        
        fill( A, A + 5, '.' );
        A[0] = X[0];
        puts( A ); 
        
        memset( C, 0, sizeof( C ) );
        
        for( int i = 0; i < 5; ++i )
            ++C[X[i] - 'A']; 
        
        for( int i = 0; i < 5 && i < cnt; ++i ) {
            S[0] = '\0'; 
            if( strlen( V[i] ) == 5 )
            for( int j = 0; j < 5; ++j ) {
                if( !isupper( V[i][j] ) )   break;
                if( X[j] == V[i][j] ) {
                    S[strlen(S)+1] = '\0';
                    S[strlen(S)] = X[j];
                }
                else if( C[V[i][j] - 'A'] ) {
                    S[strlen(S)+1] = '\0';
                    S[strlen(S)] = tolower( V[i][j] );
                }
                else {
                    S[strlen(S)+1] = '\0';
                    S[strlen(S)] = '.';
                }
            }
            if( strlen( S ) == 5 ) strcpy( A, S );
            
            memcpy( B, C, sizeof( B ) );
            for( int j = 0; j < 5; ++j )
                if( isupper( A[j] ) )
                    --B[A[j] - 'A'];
            for( int j = 0; j < 5; ++j ) {
                if( islower( A[j] ) ) {
                    if( !B[A[j] - 'a'] ) 
                            A[j] = '.'; 
                    else    B[A[j] - 'a']--; 
                }
            }
            
            if( !strcmp( A, X ) ) {
                puts( A ); 
                A[0] = '\0';
                break; 
            }

            if( i < 5 ) puts( A ); 
            
        }

        if( strlen( A ) ) {
            for( int i = 0; i < 5; ++i )
                X[i] = tolower( X[i] );
            puts( X ); 
        }
        
    }

}
