// 2883086 2008-05-01 21:25:53 Accepted 1602 C++ 00:00.00 876K 呆滞的慢板 
// 改变表现，类似于矩阵连乘，DP 

#include <iostream>
#include <algorithm>
using namespace std;

int A[100][100],    N;
int X[100],         temp;

int main() {

    while( cin >> N ) {
        
        for( int i = 0; i < N; ++i ) {
            A[i][i] = 0;
            cin >> X[i];
        }
        
        // 转换成矩阵列 [X,Y] 连乘 
        --N;
        
        for( int k = 1; k < N; ++k ) {
            
            for( int i = 0; i + k < N; ++i ) {
                
                A[i][i + k] = 0x7FFFFFFF;
                
                for( int j = 0; j < k; ++j ) {
                    
                    temp = A[i][i + j] + A[i + j + 1][i + k] +
                        X[i] * X[i + j + 1] * X[i + k + 1];
                        
                    if( temp < A[i][i + k] )
                        A[i][i + k] = temp;
                        
                }
                
            }
            
        }
        
        cout << A[0][N - 1] << endl;

        
    }
    
}
