// 2897685 2008-05-08 00:05:01 Accepted 1276 C++ 00:00.00 848K 呆滞的慢板 

// 经典矩阵连乘的 DP，但要加上状态的纪录，直接加字符串搞就行 

#include <iostream>
#include <string>
using namespace std;

struct Matrix {
    
    int     total;
    string  str;
    int     x,  y;
    
};

int main() {
    
    int     N,  T = 0;
    Matrix  M[10][10];
    
    while( ( cin >> N ) && N ) {
        
        for( int i = 0; i < N; ++i ) {
            cin >> M[i][i].x >> M[i][i].y;
            M[i][i].total = 0;
            M[i][i].str = "A";
            M[i][i].str += ( '1' + i );
            if( i == 9 ) M[i][i].str = "A10";
        }
        
        cout << "Case " << ++T << ": ";
        
        for( int d = 1; d < N; ++d ) {
            for( int i = 0; i < N - d; ++i ) {
                int pos = i;
                M[i][i + d].x = M[i][i].x;
                M[i][i + d].y = M[i + d][i + d].y;
                M[i][i + d].total = 0x7FFFFFFF;
                for( int j = i; j < i + d; ++j ) {
                    int temp = M[i][j].total +
                               M[j + 1][i + d].total +
                               M[i][j].x * M[i][j].y * M[j + 1][i + d].y;
                    if( temp < M[i][i + d].total ) {
                        M[i][i + d].total = temp;
                        M[i][i + d].str = "(" + M[i][j].str +
                                        " x " + M[j + 1][i + d].str + ")";
                    }
                }
            }
        }
        
        cout << M[0][N - 1].str << endl;
        
    }
    
}
