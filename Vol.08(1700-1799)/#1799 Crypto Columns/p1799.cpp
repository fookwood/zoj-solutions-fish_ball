// 2955178 2008-06-23 11:32:27 Accepted 1799 C++ 00:00.00 848K 呆滞的慢板 

// 先还原原矩阵，再直接输出

// 通过 key 做一个逆序计数，再直换群一下
//   按照这个顺序将 text 里面的字符填进矩阵，即可还原矩阵 

#include <iostream>
#include <string>
using namespace std;

char    A[10][100];

string  key,    text;
int     C[10],  D[10];

int     M,  N;

int main() {
    
    while( cin >> key >> text ) {
    
        if( key == "THEEND" )
            break;
            
        M = key.size();
        N = ( text.size() - 1 ) / M + 1;
        
        for( int i = 0; i < M; ++i ) {
            C[i] = 0;
            for( int j = 0; j < i; ++j ) {
                if( key[j] > key[i] )   ++C[j];
                else                    ++C[i];
            }
        }
        
        for( int i = 0; i < M; ++i )
            D[C[i]] = i;
        
        int pos = 0;
        for( int i = 0; i < M; ++i )
            for( int j = 0; j < N; ++j )
                A[D[i]][j] = text[pos++];
                
        for( int j = 0; j < N; ++j )
            for( int i = 0; i < M; ++i )
                putchar( A[i][j] );
        
        putchar( '\n' );
    
    }
    
}
