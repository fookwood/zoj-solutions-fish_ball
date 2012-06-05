// 3014605 2008-07-30 21:06:22 Accepted 1974 C++ 00:00.13 844K 呆滞的慢板 

// 把线性方程组列出来求解，跟 1973 是一套的题 

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    
    int     N;
    vector<double>  X,  Y;
    
    while( cin >> N ) {
        
        X.resize( N );
        Y.resize( N );
        
        for( int i = 0; i < N; ++i )
            cin >> X[i] >> Y[i];
        
        for( int i = 1; i < N; ++i ) {
            if( i % 2 ) {
                X[i] = X[i-1] - X[i]; 
                Y[i] = Y[i-1] - Y[i]; 
            }
            else {
                X[i] = X[i-1] + X[i]; 
                Y[i] = Y[i-1] + Y[i]; 
            }
        }
        
        for( int i = 0; i < N - 1; ++i ) {
            X[i] *= 2.0;
            Y[i] *= 2.0;
            X[i] -= X[N-1];
            Y[i] -= Y[N-1];
            if( i % 2 ) {
                X[i] *= -1.0;
                Y[i] *= -1.0;
            }
        }
        
        cout << N;
        
        for( int i = 0; i < N; ++i ) {
            printf( " %.6lf %.6lf", 
                X[(i+N-1)%N] + 1e-8,
                Y[(i+N-1)%N] + 1e-8 );
        }

        puts( "" );
        
    }
    
    
}
